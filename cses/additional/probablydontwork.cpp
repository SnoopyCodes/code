#include <bits/stdc++.h>
using namespace std;

// Struct to hold labels for each node
struct Labels {
    vector<int> Lin;  // Backward labels
    vector<int> Lout; // Forward labels
};

// Function to perform Kosaraju's algorithm to find SCCs
struct Graph {
    int n;
    vector<vector<int>> adj;
    vector<vector<int>> adj_rev;
    Graph(int size) : n(size), adj(size + 1), adj_rev(size + 1) {}
    
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    
    // Returns the list of SCCs, each as a vector of nodes
    vector<vector<int>> get_SCCs(){
        vector<bool> visited(n + 1, false);
        vector<int> order;
        
        // First DFS to compute finishing times
        function<void(int)> dfs1 = [&](int u) {
            visited[u] = true;
            for(auto &v: adj[u]){
                if(!visited[v]) dfs1(v);
            }
            order.push_back(u);
        };
        
        for(int u=1; u<=n; u++) if(!visited[u]) dfs1(u);
        
        // Second DFS on reversed graph
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> SCCs;
        
        function<void(int, vector<int>&)> dfs2 = [&](int u, vector<int> &component) {
            visited[u] = true;
            component.push_back(u);
            for(auto &v: adj_rev[u]){
                if(!visited[v]) dfs2(v, component);
            }
        };
        
        for(int i=order.size()-1; i>=0; i--){
            int u = order[i];
            if(!visited[u]){
                vector<int> component;
                dfs2(u, component);
                SCCs.push_back(component);
            }
        }
        
        return SCCs;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    Graph g(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }
    
    // Get SCCs
    vector<vector<int>> SCCs = g.get_SCCs();
    int num_SCC = SCCs.size();
    
    // Assign each node to its SCC
    vector<int> node_SCC(n + 1);
    for(int i=0; i<num_SCC; i++) {
        for(auto &u: SCCs[i]) node_SCC[u] = i;
    }
    
    // Build condensed DAG
    vector<vector<int>> DAG(num_SCC, vector<int>());
    for(int u=1; u<=n; u++){
        for(auto &v: g.adj[u]){
            if(node_SCC[u] != node_SCC[v]){
                DAG[node_SCC[u]].push_back(node_SCC[v]);
            }
        }
    }
    
    // Remove duplicate edges
    for(int i=0; i<num_SCC; i++){
        sort(DAG[i].begin(), DAG[i].end());
        DAG[i].erase(unique(DAG[i].begin(), DAG[i].end()), DAG[i].end());
    }
    
    // Topological sort on DAG
    vector<int> in_degree(num_SCC, 0);
    for(int u=0; u<num_SCC; u++) {
        for(auto &v: DAG[u]) in_degree[v]++;
    }
    
    queue<int> q_queue;
    for(int u=0; u<num_SCC; u++) if(in_degree[u] == 0) q_queue.push(u);
    
    vector<int> topo_order;
    while(!q_queue.empty()){
        int u = q_queue.front(); q_queue.pop();
        topo_order.push_back(u);
        for(auto &v: DAG[u]){
            in_degree[v]--;
            if(in_degree[v] == 0) q_queue.push(v);
        }
    }
    
    // Initialize labels
    vector<Labels> labels(num_SCC);
    
    // Assign forward labels (Lout) in topological order
    for(auto &u: topo_order){
        // Forward labels: start with itself
        labels[u].Lout.push_back(u);
        
        // For each outgoing neighbor, merge their Lout into current's Lout
        for(auto &v: DAG[u]){
            // Merge labels[u].Lout and labels[v].Lout
            // Since both are sorted, perform a sorted merge without duplicates
            vector<int> merged;
            merged.reserve(labels[u].Lout.size() + labels[v].Lout.size());
            int i1 = 0, i2 = 0;
            while(i1 < labels[u].Lout.size() && i2 < labels[v].Lout.size()){
                if(labels[u].Lout[i1] < labels[v].Lout[i2]){
                    merged.push_back(labels[u].Lout[i1++]);
                }
                else if(labels[u].Lout[i1] > labels[v].Lout[i2]){
                    merged.push_back(labels[v].Lout[i2++]);
                }
                else{
                    merged.push_back(labels[u].Lout[i1]);
                    i1++; i2++;
                }
            }
            while(i1 < labels[u].Lout.size()) merged.push_back(labels[u].Lout[i1++]);
            while(i2 < labels[v].Lout.size()) merged.push_back(labels[v].Lout[i2++]);
            labels[u].Lout = merged;
        }
    }
    
    // Build Reverse Condensed DAG for backward labels
    vector<vector<int>> Reverse_DAG(num_SCC, vector<int>());
    for(int u=0; u<num_SCC; u++) {
        for(auto &v: DAG[u]){
            Reverse_DAG[v].push_back(u);
        }
    }
    
    // Assign backward labels (Lin) in topological order
    for(auto &u: topo_order){
        // Backward labels: start with itself
        labels[u].Lin.push_back(u);
        
        // For each incoming neighbor, merge their Lin into current's Lin
        for(auto &v: Reverse_DAG[u]){
            // Merge labels[u].Lin and labels[v].Lin
            // Both are sorted
            vector<int> merged;
            merged.reserve(labels[u].Lin.size() + labels[v].Lin.size());
            int i1 = 0, i2 = 0;
            while(i1 < labels[u].Lin.size() && i2 < labels[v].Lin.size()){
                if(labels[u].Lin[i1] < labels[v].Lin[i2]){
                    merged.push_back(labels[u].Lin[i1++]);
                }
                else if(labels[u].Lin[i1] > labels[v].Lin[i2]){
                    merged.push_back(labels[v].Lin[i2++]);
                }
                else{
                    merged.push_back(labels[u].Lin[i1]);
                    i1++; i2++;
                }
            }
            while(i1 < labels[u].Lin.size()) merged.push_back(labels[u].Lin[i1++]);
            while(i2 < labels[v].Lin.size()) merged.push_back(labels[v].Lin[i2++]);
            labels[u].Lin = merged;
        }
    }
    
    // Now, process queries
    while(q--){
        int a, b;
        cin >> a >> b;
        int scc_a = node_SCC[a];
        int scc_b = node_SCC[b];
        // To check if there's a common node in Lout[scc_a] and Lin[scc_b]
        // Both Lout[scc_a] and Lin[scc_b] are sorted lists
        // Perform intersection of two sorted lists
        const vector<int> &La = labels[scc_a].Lout;
        const vector<int> &Lb = labels[scc_b].Lin;
        int i1 = 0, i2 = 0;
        bool found = false;
        while(i1 < La.size() && i2 < Lb.size()){
            if(La[i1] < Lb[i2]){
                i1++;
            }
            else if(La[i1] > Lb[i2]){
                i2++;
            }
            else{
                found = true;
                break;
            }
        }
        cout << (found ? "YES" : "NO") << "\n";
    }
}

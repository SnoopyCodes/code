#include <bits/stdc++.h>
 
using namespace std;
 
 
vector<vector<int>> graph;
 
vector<vector<int>> comps;
vector<int> in_comp;
 
vector<int> in_time;
vector<int> back;
stack<int> path;
 
int euler = 0, cN = 0;
 
void dfs(int u, int par) {
    back[u] = euler;
    in_time[u] = euler++;
    path.push(u);
    for (int v : graph[u]) {
        //tricky part
        if (in_time[v] == -1) { dfs(v, u); }
        if (in_comp[v] == -1) { back[u] = min(back[u], back[v]); }
    }
    if (in_time[u] != back[u]) { return; }
    comps.push_back({});
    while (in_comp[u] == -1) {
        int node = path.top();
        path.pop();
        in_comp[node] = cN;
        comps[cN].push_back(node);
    }
    cN++;
}

vector<int> comp_start;
vector<int> comp_end;

void dfs_comp(int cu) {
    comp_start[cu] = euler++;
    for (int u : comps[cu]) {
        for (int v : graph[u]) {
            int cv = in_comp[v];
            if (comp_start[cv] == -1) { dfs_comp(cv); }
        }
    }
    comp_end[cu] = euler;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //all strongly connected components toposort
    //then run a dfs
    //use dsu with rollback
    int N, M, Q; cin >> N >> M >> Q;
    graph.resize(N);
    back.resize(N);
    in_time.resize(N, -1);
    in_comp.resize(N, -1);
 
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
    }

    for (int i = 0; i < N; i++) {
        if (in_comp[i] == -1) { dfs(i, -1); }
    }
 
    //we reverse it because tarjan's gives us reverse topo order
    //i wonder does it matter if we reverse it or not?
    reverse(comps.begin(), comps.end());
    for (int i = 0; i < N; i++) {
        in_comp[i] = cN - in_comp[i] - 1;
    }
    comp_start.resize(cN, -1);
    comp_end.resize(cN, -1);
    euler = 0;
    for (int i = 0; i < cN; i++) {
        if (comp_start[i] == -1) { dfs_comp(i); }
    }
    
    for (int i = 0; i < Q; i++) {
        int u, v; cin >> u >> v; u--; v--;
        int cu = in_comp[u], cv = in_comp[v];
        if (comp_start[cu] <= comp_start[cv] && comp_end[cv] <= comp_end[cu]) { cout << "YES"; }
        else { cout << "NO"; }
        cout << "\n";
    }

}
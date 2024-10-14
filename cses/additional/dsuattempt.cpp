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
 
 
vector<int> dsu;
vector<int> sizes;
 
int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (sizes[u] < sizes[v]) { swap(u, v); }
    sizes[u] += sizes[v];
    dsu[v] = u;
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
    vector<vector<array<int, 2>>> queries(N);
 
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
    }
    for (int i = 0; i < Q; i++) {
        int u, v; cin >> u >> v; u--; v--;
        queries[v].push_back({u, i});
    }
 
    for (int i = 0; i < N; i++) {
        if (in_comp[i] == -1) { dfs(i, -1); }
    }
 
    //we reverse it because tarjan's gives us reverse topo order
    reverse(comps.begin(), comps.end());
    for (int i = 0; i < N; i++) {
        in_comp[i] = cN - in_comp[i] - 1;
    }
 
    dsu.resize(cN);
    sizes.resize(cN, 1);
    vector<bool> ans(Q);
    vector<vector<int>> direct(cN);
    for (int i = 0; i < cN; i++) { dsu[i] = i; }
 
    for (int i = 0; i < cN; i++) {
        //we must merge all the components together
        for (int v : direct[i]) {
            merge(i, v);
        }
        //now we answer all queries for this one
        for (int u : comps[i]) {
            for (auto const&[v, q] : queries[u]) {
                if (find(in_comp[v]) == find(i)) {
                    ans[q] = true;
                }
            }
            //now we go to next scc
            for (int v : graph[u]) {
                direct[in_comp[v]].push_back(find(i));
            }
        }
    }
 
    for (int i = 0; i < Q; i++) {
        cout << (ans[i] ? "YES" : "NO") << "\n";
    }
}
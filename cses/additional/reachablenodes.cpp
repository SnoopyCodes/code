#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> reachable;
vector<int> visited;
vector<int> on_stack;
void dfs(int u) {
    visited[u] = true;
    on_stack[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) { dfs(v); }
        if (!on_stack[v]) { reachable[u] += reachable[v]; }
    }
    on_stack[u] = false;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    //is this radj
    //is this dfs
    //if we dfs what happen?
    //it's a weird dp i guess
    //i believe... this is hard.
    graph.resize(N);
    reachable.resize(N, 1);
    visited.resize(N);
    on_stack.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) { dfs(i); }
        cout << reachable[i] << " \n"[i == N - 1];
    }
}
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;

vector<vector<int>> scc;
vector<int> in_scc, back;
stack<int> path;

int CN = 0, euler = 0;

void dfs(int u) {
    int in = euler;
    back[u] = euler;
    euler++;
    path.push(u);
    for (int v : graph[u]) {
        if (back[v] == -1) { dfs(v); }
        if (in_scc[v] == -1) { back[u] = min(back[u], back[v]); }
    }
    
    if (back[u] != in) { return; }
    scc.push_back({});
    while (in_scc[u] == -1) {
        int v = path.top();
        in_scc[v] = CN;
        scc[CN].push_back(v);
        path.pop();
    }
    CN++;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    graph.resize(N), in_scc.resize(N, -1), back.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
    }

    for (int i = 0; i < N; i++) {
        if (back[i] == -1) { dfs(i); }
    }

    cout << CN << "\n";
    for (int i = 0; i < N; i++) {
        cout << in_scc[i] + 1 << " \n"[i == N - 1];
    }
}
//single use
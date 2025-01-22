#include <bits/stdc++.h>

using namespace std;

struct tarjan {
    int N, NCC = 0, euler = 0;
    vector<vector<int>> G, cc, adj;
    vector<int> back, in_cc;
    stack<int> path;
    void init(vector<vector<int>> &_G) {
        N = _G.size();
        G = _G;
        back.resize(N, -1), in_cc.resize(N, -1);
        for (int i = 0; i < N; i++) {
            if (in_cc[i] == -1) { dfs(i); }
        }
        for (int i = 0; i < N; i++) {
            in_cc[i] = NCC - 1 - in_cc[i];
        }

        cc.resize(NCC);
        for (int i = 0; i < N; i++) {
            cc[in_cc[i]].push_back(i);
        }

        adj.resize(NCC);
        for (int i = 0; i < NCC; i++) {
            for (int u : cc[i]) {
                for (int v : G[u]) {
                    if (in_cc[v] == i) { continue; }
                    adj[i].push_back(in_cc[v]);
                }
            }
        }
    }
    void dfs(int u) {
        int in = back[u] = euler++;
        path.push(u);
        for (int v : G[u]) {
            if (back[v] == -1) { dfs(v); }
            if (in_cc[v] == -1) { back[u] = min(back[u], back[v]); }
        }
        if (back[u] != in) { return; }
        while (in_cc[u] == -1) {
            int v = path.top(); path.pop();
            in_cc[v] = NCC;
        }
        NCC++;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
    }
    tarjan solver; solver.init(G);
    cout << solver.NCC << "\n";
    for (int i = 0; i < N; i++) {
        cout << solver.in_cc[i] + 1 << " \n"[i == N - 1];
    }
}
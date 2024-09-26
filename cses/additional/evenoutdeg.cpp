#include <bits/stdc++.h>

using namespace std;
//pretty clean
vector<vector<int>> glaph;
vector<int> visited;
vector<array<int, 2>> edges;
int euler = 0;
bool dfs(int u, int from) {
    visited[u] = euler++;
    int cnt = 0;
    for (int v : glaph[u]) {
        if (v == from) { continue; }
        if (visited[v] != -1) {
            if (visited[u] < visited[v]) {
                cnt++;
                edges.push_back({u + 1, v + 1});
            }

        }   else {
            if (dfs(v, u)) { edges.push_back({v + 1, u + 1}); }
            else { cnt++; edges.push_back({u + 1, v + 1}); }
        }
    }
    return cnt % 2;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    glaph.resize(N);
    visited.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        glaph[u].push_back(v);
        glaph[v].push_back(u);
    }
    bool valid = true;
    for (int i = 0; i < N; i++) {
        if (visited[i] == -1) { valid &= !dfs(i, -1); }
    }
    if (valid) {
        for (auto const&[u, v] : edges) {
            cout << u << " " << v << "\n";
        }
    }
    else { cout << "IMPOSSIBLE" << endl; }
}
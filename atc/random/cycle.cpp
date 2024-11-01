#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> dist(N, -1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
    }
    queue<int> q;
    for (int v : G[0]) {
        dist[v] = 1;
        q.push(v);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << dist[0];
}
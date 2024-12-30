#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    //very obviously a bfs problem
    //how do we assign stuff though?
    vector<array<int, 2>> edges;
    vector<vector<int>> from(N+1);
    vector<int> dist(N);
    vector<int> on(N+1);
    vector<bool> visited(N);
    for (int i = 0; i < N; i++) {
        cin >> dist[i];
        if (dist[i] >= N) { cout << -1 << "\n"; return 0; }
        from[dist[i]].push_back(i);
    }
    if (from[0].size() != 1) { cout << -1 << "\n"; return 0; }
    for (int i = 0; i < N; i++) {
        int k = i == 0 ? K : K - 1;
        for (int u : from[i]) {
            if (!visited[u] && i) { cout << -1 << "\n"; return 0; }
            for (int j = 0; j < k && on[i+1] < from[i+1].size(); j++) {
                edges.push_back({u, from[i+1][on[i+1]]});
                visited[from[i+1][on[i+1]]] = true;
                on[i+1]++;
            }
        }
    }
    cout << edges.size() << "\n";
    for (auto [u, v] : edges) {
        cout << u + 1 << " " << v + 1 << "\n";
    }

}
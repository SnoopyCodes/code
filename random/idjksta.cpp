#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<array<int, 2>>> cities(N);
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        cities[u].push_back({v, d});
    }
    vector<long> dists(N, 1e18);
    vector<bool> visited(N);
    dists[0] = 0;
    priority_queue<array<long, 2>> pq;
    pq.push({0,0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();  //dont like
        d = -d;  //dont like
        pq.pop();
        if (d != dists[u]) { continue; }
        for (auto const&[v, len] : cities[u]) {
            if (dists[u] + len < dists[v]) {
                dists[v] = dists[u] + len;
                pq.push({-dists[v], v});
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << dists[i] << " \n"[i == N - 1];
    }
}
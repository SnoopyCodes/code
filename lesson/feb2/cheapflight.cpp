#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    //i do not normally do pq
    int S, E, K; cin >> S >> E >> K; S--; E--; K++;
    vector<vector<array<int, 2>>> flights(N);
    for (int i = 0; i < M; i++) {
        int u, v, c; cin >> u >> v >> c; u--; v--;
        flights[u].push_back({v, c});
        flights[v].push_back({u, c});
    }
    vector<vector<int>> cost(N, vector<int>(N + 1, 1e9)); //least dist to node i w/ j flights
    cost[S][0] = 0;
    priority_queue<array<int, 3>> pq;
    pq.push({0, 0, S});  //-price, -flights, city
    while (!pq.empty()) {
        auto [p, f, c] = pq.top(); pq.pop();
        p = -p, f = -f;
        if (f == K) { continue; }
        if (cost[c][f] != p) { continue; }
        for (auto [v, fc] : flights[c]) {
            if (p + fc < cost[v][f+1]) {
                cost[v][f+1] = p + fc;
                pq.push({-cost[v][f+1], -(f+1), v});
            }
        }
    }
    int ans = *min_element(cost[E].begin(), cost[E].end());
    if (ans == 1e9) { cout << -1 << "\n"; }
    else { cout << ans << "\n";}
}
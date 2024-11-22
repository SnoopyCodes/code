#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    int N, M, T; cin >> N >> M >> T;
    //okay well first
    //we can obviously dijkstra from one to another
    //but then we need to figure out how to quickly analyze
    //then we also want to figure out how many cows end up at each point
    vector<vector<array<int, 2>>> trails(N);
    vector<int> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        trails[u].push_back({v, d});
        trails[v].push_back({u, d});
    }
    vector<ll> dist(N, 1e18);
    vector<int> prev(N, N);
    dist[0] = 0;
    set<array<ll, 3>> s;
    s.insert({0, 0, -1});
    stack<int> order;  //the end order where we visit
    while (!s.empty()) {
        auto [d, u, p] = *s.begin();
        s.erase(s.begin());
        if (d > T) { order.push(u); }
        for (auto const& [v, to] : trails[u]) {
            if (d + to < dist[v] || d + to == dist[v] && u < prev[v]) {
                s.erase({dist[v], v, prev[v]});
                dist[v] = d + to;
                prev[v] = u;
                s.insert({dist[v], v, prev[v]});
            }
        }
    }
    ll best = 0;
    while (!order.empty()) {
        int u = order.top(); order.pop();
        best = max(best, cows[u] * (dist[u] - T));
        cows[prev[u]] += cows[u];
    }
    cout << best << "\n";
    //Ok, now figure out how many cows can pass through each point
    //wait each set can only pass through one
    //thus, everything is fine

}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    vector<vector<array<int, 2>>> city(N);
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        city[u].push_back({v, d});
    }
    multiset<array<ll, 2>> s;  //{dist, u}
    vector<priority_queue<ll>> dist(N);  //which one we're on
    s.insert({0, 0});
    dist[0].push(0);
    while (!s.empty()) {
        int u = (*s.begin())[1];
        ll d = (*s.begin())[0];
        s.erase(s.begin());
        for (auto const& [v, c] : city[u]) {
            if (dist[v].size() == K && dist[v].top() <= d + c) { continue; }
            if (dist[v].size() == K) {
                s.erase(s.find({dist[v].top(), v}));
                dist[v].pop();
            }
            dist[v].push({d + c});
            s.insert({d + c, v});
        }
    }
    vector<ll> res;
    while (!dist[N-1].empty()) { res.push_back(dist[N-1].top()); dist[N-1].pop(); }
    reverse(res.begin(), res.end());
    for (ll x : res) {
        cout << x << " ";
    }
    cout << "\n";
}
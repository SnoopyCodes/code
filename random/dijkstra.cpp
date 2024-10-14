#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<array<int, 2>>> cities(N);
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        cities[u].push_back({v, d});
    }
    vector<ll> dists(N, 1e18);
    dists[0] = 0;
    set<array<ll, 2>> s;
    s.insert({0,0});
    while (!s.empty()) {
        auto [d, u] = *s.begin();  //dont like
        s.erase(s.begin());
        for (auto const&[v, len] : cities[u]) {
            if (d + len < dists[v]) {
                s.erase({dists[v], v});
                dists[v] = d + len;
                s.insert({dists[v], v});
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << dists[i] << " \n"[i == N - 1];
    }
}
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
    auto cmp = [&](const int& u, const int& v) {
        return (dists[u] != dists[v] ? dists[u] < dists[v] : u < v);
    };
    set<int, decltype(cmp)> s(cmp);
    s.insert(0);
    while (!s.empty()) {
        int u = *s.begin();
        s.erase(s.begin());
        for (auto const&[v, len] : cities[u]) {
            if (dists[u] + len < dists[v]) {
                s.erase(v);
                dists[v] = dists[u] + len;
                s.insert(v);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << dists[i] << " \n"[i == N - 1];
    }
}
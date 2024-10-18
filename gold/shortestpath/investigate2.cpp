#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<array<int, 2>>> city(N);
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        city[u].push_back({v, d});
    }
    vector<array<ll, 4>> stats(N, {(ll)1e18, 0, (int)2e5, 0});  //dist, min, max
    stats[0] = {0, 1, 0, 0};
    auto cmp = [&](int u, int v) {
        return stats[u][0] == stats[v][0] ? u < v : stats[u][0] < stats[v][0];
    };
    set<int, decltype(cmp)> s(cmp);  //price, u, max flights, min flights
    s.insert(0);
    while (!s.empty()) {
        int u = *s.begin();
        s.erase(s.begin());
        for (auto const& [v, d] : city[u]) {
            if (stats[v][0] == d + stats[u][0]) {
                stats[v][1] = (stats[v][1] + stats[u][1]) % MOD;
                stats[v][2] = min(stats[v][2], stats[u][2] + 1);
                stats[v][3] = max(stats[v][3], stats[u][3] + 1);
            }   else if (stats[v][0] > d + stats[u][0]) {
                s.erase(v);
                stats[v][0] = d + stats[u][0];
                stats[v][1] = stats[u][1];
                stats[v][3] = stats[u][3] + 1;
                stats[v][2] = stats[u][2] + 1;
                s.insert(v);
            }
        }
    }
    cout << stats[N-1][0] << " " << stats[N-1][1] << " " << stats[N-1][2] << " " << stats[N-1][3] << "\n";
}
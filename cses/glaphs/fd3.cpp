#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<array<int, 2>>> flights(N);
    for (int i = 0; i < M; i++) {
        int u, v, c; cin >> u >> v >> c; u--; v--;
        flights[u].push_back({v, c});
    }
    vector<vector<ll>> mincost(N, vector<ll>(2, 1e18));
    set<array<ll, 3>> s;
    const int OFF = 1;  //discounted or not
    mincost[0][0] = mincost[0][1] = 0;
    s.insert({0, 0, 1});
    s.insert({0, 0, 0});
    while (!s.empty()) {
        auto [dist, u, off] = *s.begin();
        s.erase(s.begin());
        for (auto const&[v, c] : flights[u]) {
            if (dist + c < mincost[v][off]) {
                s.erase({mincost[v][off], v, off});
                mincost[v][off] = dist + c;
                s.insert({mincost[v][off], v, off});
            }
            if (!off && dist + c / 2 < mincost[v][OFF]) {
                s.erase({mincost[v][OFF], v, OFF});
                mincost[v][OFF] = dist + c / 2;
                s.insert({mincost[v][OFF], v, OFF});
            }
        }
    }
    cout << mincost[N - 1][1] << "\n";
}
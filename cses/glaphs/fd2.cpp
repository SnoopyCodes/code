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
    auto cmp = [&] (array<int, 2> a1, array<int, 2> a2) {
        if (mincost[a1[0]][a1[1]] == mincost[a2[0]][a2[1]]) {
            return a1 < a2;
        }
        return mincost[a1[0]][a1[1]] < mincost[a2[0]][a2[1]];
    };
    set<array<int, 2>, decltype(cmp)> s(cmp);
    const int OFF = 1;  //discounted or not
    mincost[0][0] = mincost[0][1] = 0;
    s.insert({0, 1});
    s.insert({0, 0});
    while (!s.empty()) {
        auto [u, off] = *s.begin();
        s.erase(s.begin());
        for (auto const&[v, c] : flights[u]) {
            if (mincost[u][off] + c < mincost[v][off]) {
                s.erase({v, off});
                mincost[v][off] = mincost[u][off] + c;
                s.insert({v, off});
            }
            if (!off && mincost[u][off] + c / 2 < mincost[v][OFF]) {
                s.erase({v, OFF});
                mincost[v][OFF] = mincost[u][off] + c / 2;
                s.insert({v, OFF});
            }
        }
    }
    cout << mincost[N - 1][1] << "\n";
}
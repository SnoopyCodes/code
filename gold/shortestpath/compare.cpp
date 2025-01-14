#include <bits/stdc++.h>
#define long int64_t
using namespace std;

/*
basically rafael saore's solution but hopefully easier to read
for some node u and color c, colcost[u][c] is the node with least price
with that color edge, that can reach u directly

then for some u trying to go to v with price p:
the price is min(colcost[u][c] + sum[u][c] - p, cost[u] + p)
the latter option is normal dijkstra (and just coloring this edge)
the former is the option of taking the distance to the parent of u, and coloring all the edges
of the edge we are considering except that edge itself
note how this avoids double counting the parent to u edge
*/

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<array<int, 3>>> cross(N);
    vector<map<int, long>> sum(N), colcost(N);
    for (int i = 0; i < M; i++) {
        int u, v, c, p; cin >> u >> v >> c >> p; u--; v--;
        cross[u].push_back({v, c, p});
        cross[v].push_back({u, c, p});
        sum[u][c] += p;
        sum[v][c] += p;
    }
    vector<long> cost(N, 1e18);
    cost[0] = 0;
    auto cmp = [&](int u, int v) {
        return cost[u] != cost[v] ? cost[u] < cost[v] : u < v;
    };
    set<int, decltype(cmp)> s(cmp);
    s.insert(0);
    while (!s.empty()) {
        int u = *s.begin();
        s.erase(s.begin());
        for (auto [v, c, p] : cross[u]) {
            if (colcost[v].find(c) == colcost[v].end()) { colcost[v][c] = cost[u]; }
            long best = cost[u];
            auto it = colcost[u].find(c);
            if (it != colcost[u].end()) { best = (*it).second; }
            long price = min(best + sum[u][c] - p, cost[u] + p);
            if (price < cost[v]) {
                s.erase(v);
                cost[v] = price;
                s.insert(v);
            }
        }
    }
    if (cost[N - 1] == 1e18) { cout << -1 << "\n"; }
    else { cout << cost[N - 1] << "\n"; }
}
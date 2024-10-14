#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<vector<array<int, 2>>> cities;
vector<vector<int>> rcities;
vector<bool> visited;
void dfs(int u) {
    visited[u] = true;
    for (int v : rcities[u]) {
        if (!visited[v]) { dfs(v); }
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // freopen("in.txt", "r", stdin);
    int N, M; cin >> N >> M;
    cities.resize(N);
    rcities.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        rcities[v].push_back(u);
        cities[u].push_back({v, d});
    }
    visited.resize(N);
    vector<ll> dists(N, 1e18);
    dists[0] = 0;
    vector<bool> in_v(N);
    set<array<ll, 2>> s;
    vector<int> count(N);
    s.insert({0, 0});
    in_v[0] = true;
    while (!s.empty()) {
        int u = (*s.begin())[1];
        s.erase(s.begin());
        in_v[u] = false;
        for (auto const&[v, d] : cities[u]) {
            if (dists[u] + d < dists[v]) {
                if (!in_v[v]) {
                    count[v]++;
                    if (count[v] >= N) { continue; }
                    in_v[v] = true;
                }
                if (count[v] >= N) { continue; }
                s.erase({dists[v], v});
                dists[v] = dists[u] + d;
                s.insert({dists[v], v});
            }
        }
    }
    bool valid = true;
    dfs(N - 1);
    for (int i = 0; i < N; i++) {
        if (count[i] >= N && visited[i]) { valid = false; }
    }
    if (valid) { cout << dists[N - 1] << "\n"; }
    else { cout << -1 << "\n"; }
    
    //for dijkstras
    // for (int i = 0; i < N; i++) {
    //     cout << dists[i] << " ";
    // }
    // cout << "\n";
}
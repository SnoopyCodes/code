#include <bits/stdc++.h>

using namespace std;
vector<vector<array<int, 2>>> network;
vector<vector<array<int, 2>>> single;
vector<vector<array<int, 3>>> two;
vector<int> dist;
vector<int> ans;
void calc_long(int u, int par, int d) {
    dist[u] = d;
    for (auto const& [v, vd] : network[u]) {
        if (v == par) { continue; }
        calc_long(v, u, d + vd);
        //i regret my variable naming
        if (single[v].size() != 0)
            single[u].push_back({single[v][0][0], v});
        else
            single[u].push_back({ dist[v], v });
        if (two[v].size() != 0) 
            two[u].push_back({two[v][0][0], v, -1});
    }
    sort(single[u].begin(), single[u].end());
    reverse(single[u].begin(), single[u].end());
    if (single[u].size() > 1) {
        two[u].push_back({single[u][0][0] + single[u][1][0] - 2 * dist[u], single[u][0][1], single[u][1][1]});
    }
    sort(two.begin(), two.end());
    reverse(two.begin(), two.end());
}
void set_ans(int u, int par, int res, int dir) {
    ans[u] = res;
    cout << u << " " << res << " " << dir << "\n";
    for (auto const&[v, vd] : network[u]) {
        if (v == par) { continue; }
        cout << v << "\n";
        vector<int> er(2);
        int cnt = 0;
        for (auto const&[x, y] : single[u]) {
            if (y == v) { continue; }
            er[cnt++] = x;
            if (cnt > 1) { break; }
        }
        int besttwo = -1;
        for (auto const&[x, y, z] : two[u]) {
            if (v == y || v == z) { continue; }
            besttwo = x; break;
        }
        cout << er[0] << " " << er[1] << "\n";
        set_ans(v, u, max(res, max(dir + er[0] - dist[u], besttwo)), max(dir, er[0] - dist[u]) + vd);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    network.resize(N), single.resize(N), dist.resize(N), ans.resize(N), two.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        network[u].push_back({v, d});
        network[v].push_back({u, d});
    }
    calc_long(0, -1, 0);
    for (int i = 0; i < N; i++) {
        cout << i << "\n";
        if (single[i].size())
        cout << single[i][0][0] << "\n";
        cout << "\n";
    }
    set_ans(0, -1, 0, 0);
    for (int q = 0; q < Q; q++) {
        int u; cin >> u; u--;
        cout << ans[u] << "\n";
    }
    
}
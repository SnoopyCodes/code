#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

vt<vt<int>> G;
int euler;
vt<int> in;
vt<bool> visited;
long long ans;
int dfs(int u, int p) {
    visited[u] = true;
    int low = in[u] = euler++;
    for (int v : G[u]) {
        if (visited[v]) {
            if (v != p) { low = min(low, in[v]); } //no multi-edges.
            continue;
        }
        low = min(low, dfs(v, u));
    }
    if (low == in[u] && u != 0) {
        int sz = euler - in[u];
        ans = min(ans, (long long) sz * (sz - 1) / 2 +
                (long long) ((int)size(G) - sz) * ((int)size(G) - sz - 1) / 2);
    }
    return low;
}

void solve() {
    int N, M ;cin >> N>> M;
    G = vt<vt<int>>(N);
    in = vt<int>(N);
    ans = (long long) N * (N - 1) / 2;
    visited = vt<bool>(N);
    while (M --> 0) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v); G[v].push_back(u);
    }
    //connected graph.
    //when we dfs, we can obtain the "subtree" given
    //we can dfs to find the component size split apart by this.
    //sure.
    dfs(0, -1);
    cout << ans << "\n";
    
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
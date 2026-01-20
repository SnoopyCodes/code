#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

vt<vt<int>> T;
vt<int> depth;
int sum = 0;
int dfs(int u, int p) {
    int maxd = depth[u];
    for (int v : T[u]) {
        if (v == p) { continue; }
        depth[v] = depth[u] + 1;
        maxd = max(maxd, dfs(v, u));
    }
    sum += maxd - depth[u] + 1;
    return maxd;
}
vt<int> pre;

void solve() {
    int N; cin >> N;
    sum = 0;
    T = vt<vt<int>>(N);
    depth = vt<int>(N);
    rep(i, 1, N) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].add(v);
        T[v].add(u);
    }
    dfs(0, -1);
    cout << sum % MOD * pre[N-1] % MOD << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    pre.resize(2e5 + 1);
    pre[0] = 1;
    rep(i, 1, 2e5 + 1) {
        pre[i] = pre[i - 1] * 2 % MOD;
    }
    int T; cin >> T; while (T--) { solve(); }
}
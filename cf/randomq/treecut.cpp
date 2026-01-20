#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

int ct = 0;
int dfs(int u, int p, vt<vt<int>> &T, int sz) {
    int subsz = 1;
    for (int v : T[u]) {
        if (v == p) {continue; }
        subsz += dfs(v, u, T, sz);
    }
    if (subsz >= sz) {
        ct++;
        subsz = 0;
    }
    return subsz;
}

void solve() {
    int N, K; cin >> N >> K;
    vt<vt<int>> T(N);
    rep(i, 1, N) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].add(v);
        T[v].add(u);
    }
    //screw it lets just binary search.
    int s = 1, e = N + 1;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        ct = 0;
        dfs(0, -1, T, m);
        if (ct >= K + 1) {
            s = m;
        }   else {
            e = m;
        }
    }
    cout << s << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
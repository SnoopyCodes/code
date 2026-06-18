#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for (auto i=a; i<(b); i++)
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N, M, K, L; cin >> N >> M >> K >> L;
    vt<vt<int>> G(N);
    vt<int> has_f(N), is_d(N);
    vt<int> field(K), dest(L);
    rep(i, 0, K) cin >> field[i], field[i]--, has_f[field[i]] = true;
    rep(i, 0, L) cin >> dest[i], dest[i]--, is_d[dest[i]] = true;
    rep(i, 0, M) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].add(v);
        G[v].add(u);
    }
    vt<vt<int>> in_depth(N), pars(N);
    in_depth[0].add(0);
    vt<int> depth(N, -2); //-2 is unseen, -1 is seen (but invalid), -3 is seen by others in same depth
    vt<int> ad(N, -1); //actual depth
    int last_f = -1;
    
    rep(d, 0, N) {
        for (int u : in_depth[d]) {
            ad[u] = d;
            if (has_f[u]) { last_f = d; }
            for (int v : G[u]) {
                if (ad[v] < 0) {
                    ad[v] = d + 1;
                    in_depth[d + 1].add(v);
                }
            }
        }
    }
    in_depth = vt<vt<int>>(N);
    in_depth[0].add(0);

    bool ok = true;
    vt<int> d_nf(N);
    rep(d, 0, N) {
        int hs = 0;
        for (int u : in_depth[d]) {
            depth[u] = -1;
            if (has_f[u]) {
                hs++;
            }
        }
        d_nf[d] = hs;
        if (hs >= 2) {
            ok = false;
            break;
        }
        if (hs == 1) {
            int u = -1;
            for (int v : in_depth[d]){
                if (has_f[v]) {
                    u = v;
                    break;
                }
            }
            in_depth[d].clear();
            in_depth[d] = { u };
        }
        for (int u : in_depth[d]) {
            depth[u] = d;
            for (int v : G[u]) {
                if (depth[v] < -1) {
                    if (depth[v] == -2) in_depth[d + 1].add(v);
                    depth[v] = -3;
                    pars[v].add(u);
                }
            }
        }
    }
    if (!ok) {
        rep(i, 0, N - 1) {
            cout << '0';
        }
        cout << "\n";
        return;
    }
    /*
    now for any "alive" destination farms that are PAST last_f
    mark paths leading to them as ALIVE
    */

    vt<bool> alive(N);
    for (int u : dest) {
        if (depth[u] >= last_f) {
            alive[u] = true;
        }
    }
    for (int d = N - 1; d > 0; d--) {
        for (int u : in_depth[d]) {
            if (alive[u]) {
                for (int v : pars[u]) {
                    alive[v] = true;
                }
            }
        }
    }
    for (int i = 1; i < N; i++) {
        cout << alive[i];
    }
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
/*
so i know the traceback logic is correct
we know that there cant /shouldnt be 2 on the same depth?
*/
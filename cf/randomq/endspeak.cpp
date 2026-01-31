#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
/*

*/
template<class T, T def, auto f> struct SegmentTree {
    vector<T> t; int N;
    SegmentTree(int n):N(n),t(2 * n, def) {}
    void upd(int i, T v) {
        t[i + N] = f(t[i + N], v);
        for (i = (i + N) / 2; i > 0; i >>= 1) {
            t[i] = f(t[i << 1], t[i << 1 | 1]);
        }
    }
    T query(int l, int r) {
        T resl = def, resr = def;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { resl = f(resl, t[l++]); }
            if (r & 1) { resr = f(t[--r], resr); }
        }
        return f(resl, resr);
    }
};

void solve() {
    int N, M; cin >> N >> M;
    vt a(N, 0LL);
    vt b(M, 0LL);
    for (int &u : a) cin >> u;
    for (int &u : b) cin >> u;

    auto merge = [](ii<2> a, ii<2> b) {
        if (a[0] == b[0]) { return ii<2>{ a[0], (a[1] + b[1]) % MOD }; }
        else { return a[0] < b[0] ? a : b; }
    };

    vt psum(N + 1, 0LL);
    vt to(N, vt(M, -1LL));
    for (int i = 0; i < N; i++) psum[i + 1] = psum[i] + a[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int s = i, e = N + 1;
            while (s + 1 < e) {
                int m = (s + e) / 2;
                if (psum[m] - psum[i] <= b[j]) {
                    s = m;
                }   else {
                    e = m;
                }
            }
            to[i][j] = s;
        }
    }
    
    vt segs(M, SegmentTree<ii<2>, ii<2>{ MOD * MOD, 0 }, merge>(N + 1));
    segs[0].upd(0, { 0, 1 });

    for (int i = 0; i < N; i++) {
        ii<2> best = { MOD * MOD, 0 };
        for (int j = 0; j < M; j++) {
            best = merge(best, segs[j].query(i, N + 1));
            segs[j].upd(to[i][j], ii<2>{ best[0] + M - j - 1, best[1] });
        }
    }

    ii<2> ans = { MOD * MOD, 0 };
    for (int i = 0; i < M; i++) {
        ans = merge(ans, segs[i].query(N, N + 1));
    }
    if (ans[0] == MOD * MOD) cout << -1 << "\n";
    else cout << ans[0] << " " << ans[1] << "\n";
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
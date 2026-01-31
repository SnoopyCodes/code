#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

//modify for range update point query
template<class T, T def, auto f> struct SegmentTree {
    vector<T> t; int N;
    SegmentTree(int n):N(n),t(2 * n, def) {}
    void update(int l, int r, T v) {
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                t[l] = f(t[l], v);
                l++;
            }
            if (r & 1) {
                t[--r] = f(t[r], v);
            }
        }
    }
    T operator[](int i) {
        T res = t[i + N];
        for (i = (i + N) / 2; i > 0; i >>= 1) {
            res = f(res, t[i]);
        }
        return res;
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

    vt dp(N + 1, vt(M, ii<2>{ MOD * MOD, 0 } )); //min cost of finishing x at index i for b
    dp[0] = vt<ii<2>>(M, { 0, 0 });
    dp[0][0][1] = 1;
    vt psum(N + 1, 0LL);
    vt to(N, vt(M, -1LL));
    for (int i = 0; i < N; i++) psum[i + 1] = psum[i] + a[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //what is 1 past the last element we eat up to?
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
    segs[0].update(0, 1, { 0, 1 });
    

    for (int i = 0; i < N; i++) { //we need to eat starting from i
        ii<2> best = { MOD * MOD, 0 };
        for (int j = 0; j < M; j++) {
            // if (segs[j][i][0] == 0 && i > 0) {
            //     cout << j << " " << i << endl;
            //     cout << segs[j][i][1] << endl;
            // }
            best = merge(best, segs[j][i]);
            best[0] += M - j - 1;
            //range update
            // if (true) {
            //     cout << i << " " << j << ": ";
            //     cout << best[0] << "_";
            //     cout << to[i][j] << "\n";
            // }
            for (int k = i + 1; k < to[i][j] + 1; k++) {
                segs[j].update(k, k + 1, best);
            }
            best[0] -= M - j - 1;
        }
    }

    ii<2> ans = { MOD * MOD, 0 };
    for (int i = 0; i < M; i++) {
        ans = merge(ans, segs[i][N]);
    }
    if (ans[0] == MOD * MOD) cout << -1 << "\n";
    else cout << ans[0] << " " << ans[1] << "\n";
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
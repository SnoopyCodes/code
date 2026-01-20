#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
#define loop(i, n) rep(i, 0, n)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

template<class T, T def, T (*f)(T, T)> struct SegmentTree {
    vector<T> t; int N;
    SegmentTree(int n):N(n),t(2 * n, def) {}
    void inc(int i, T v) {
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
int f(int a, int b) { return a + b; }

void solve() {
    int N, Q; cin >> N >> Q;
    vt<int> A(N), pos(N + 1);
    SegmentTree<int, 0, f> seg(N);
    rep(i, 0, N) {
        cin >> A[i], pos[A[i]] = i;
    }
    vt<vt<ii<2>>> queries(N);
    vt<int> ans(Q);
    rep(i, 0, Q) {
        int l, r; cin >> l >> r; l--;
        queries[l].add({ r, i });
    }

    /*
    we do problems to learn, right?
    i didn't see the condition indices in increasing order bro
    what did we learn today?
    reading is good
    and
    offline querying is very strong still
    */

    vt<int> dp(N + 1);
    for (int i = N - 1; i > -1; i--) {
        dp[A[i]] = 1;
        for (int x = A[i]; x <= N; x += A[i]) {
            if (pos.at(x) < i) { continue; }
            for (int y = x * 2; y <= N; y += x) {
                if (pos.at(y) < pos.at(x)) { continue; }
                dp[y] += dp[x];
            }
            seg.inc(pos.at(x), dp.at(x));
            dp[x] = 0;
        }

        for (auto [r, j] : queries[i]) {
            ans.at(j) = seg.query(i, r);
        }
    }
    rep(i, 0, Q) {
        cout << ans.at(i) << " ";
    }
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) { solve(); }
}
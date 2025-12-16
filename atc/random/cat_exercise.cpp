#include <bits/stdc++.h>

using namespace std;

#define long long long //necessary ish
#define rep(i, a, b) for (auto i = a; i < (b); i++) //
#define vt vector
template<int z> using ii = array<int, z>;

template<class T, T def, T (*f)(T, T)> struct SegmentTree {
    vector<T> t; int N;
    SegmentTree(int n):N(n),t(2 * n, def) {}
    void set(int i, T v) {
        t[i + N] = v;
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
int ff(int a, int b) { return max(a, b); }

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int N; cin >> N;
    vt<int> H(N);
    rep(i, 0, N) cin >> H[i], H[i]--;
    vt<int> invh(N);
    rep(i, 0, N) {
        invh[H[i]] = i;
    }

    //copied from sums of sliding windows
    auto A = H;

    vt<int> cl(N, -1), cr(N, N); //closest left(eq) larger, right larger
    for (int i = 1; i < N; i++) {
        int j = i - 1;
        while (j != -1 && A[i] > A[j]) { j = cl[j]; }
        cl[i] = j;
    }
    for (int i = N - 2; i > -1; i--) {
        int j = i + 1;
        while (j != N && A[i] >= A[j]) { j = cr[j]; }
        cr[i] = j;
    }

    SegmentTree<int, -1, ff> seg(N);
    rep(i, 0, N) seg.set(i, H[i]);
    vt lt(N, -1), rt(N, -1); //left trans, right trans
    rep(i, 0, N) {
        int l = seg.query(cl[i] + 1, i);
        if (l != -1) lt[i] = invh[l];
        int r = seg.query(i + 1, cr[i]);
        if (r != -1) rt[i] = invh[r];
    }
    vt<int> ex;

    vt dp(N, 0LL);
    rep(i, 0, N) {
        int j = invh[i];
        if (lt[j] != -1) {
            dp[i] = dp[H[lt[j]]] + j - lt[j];
        }
        if (rt[j] != -1) {
            dp[i] = max(dp[i], dp[H[rt[j]]] + rt[j] - j);
        }
    }

    cout << dp[N - 1] << "\n";
    
}
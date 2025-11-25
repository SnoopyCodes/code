#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
vector<int> seg;
int N;

int query(int l, int r) {
    int res = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { res += seg[l++]; }
        if (r & 1) { res += seg[--r]; }
    }
    return res;
}
void alter(int p, long val) {
    seg[p + N] = val;
    for (p = (p + N) / 2; p > 0; p /= 2) {
        seg[p] = min(seg[2 * p], seg[2 * p + 1]);
    }
}

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

int f(int a, int b) { return a + b; }

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> N >> Q;
    seg.resize(2 * N);
    vector<long> A(N);

    SegmentTree<int, 0, f> sumsg(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        alter(i, A[i]);
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t & 1) {
            int k, x; cin >> k >> x; k--;
            alter(k, x);
        }   else {
            int l, r; cin >> l >> r; l--;
            cout << query(l, r) << "\n";
        }
    }
}
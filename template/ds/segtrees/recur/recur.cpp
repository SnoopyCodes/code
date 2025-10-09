#include <bits/stdc++.h>

using namespace std;

template<typename T> struct SegTree {
    int N, ql, qr;
    vector<T> data;
    T def = 1e9, val;
    SegTree(int N):N(N),data(4 * N, def) {}
    T comb(T a, T b) { return min(a, b); }
    #define m ((l + r) / 2)
    T qry(int n, int l, int r) {
        if(r <= ql || qr <= l) { return def; }
        if(ql <= l && r <= qr) { return data[n]; }
        return comb(qry(2*n, l, m), qry(2*n+1, m, r));
    }
    void upd(int n, int l, int r) {
        if(l + 1 == r) { data[n] = val; return; }
        if(ql < m) { upd(2*n, l, m); }
        else { upd(2*n+1, m, r); }
        data[n] = comb(data[2*n], data[2*n+1]);
    }
    int wlk(int n, int l, int r) {
        if (data[n] < val || r <= ql || qr <= l) { return -1; }
        if (l + 1 == r) { return l; }
        if (data[2*n] >= val && ql < m) {
            int left = wlk(2*n, l, m);
            if (left != -1) { return left; }
        }
        return wlk(2*n+1, m, r);
    }
    #undef m
    T query(int l, int r) { ql = l, qr = r; return qry(1, 0, N); }
    void update(int idx, T v) { ql = idx, val = v; upd(1, 0, N); }
    int walk(T x, int l, int r) { val = x, ql = l, qr = r; return wlk(1, 0, N); }
};
//to change, change def and comb, and wlk

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    SegTree<int> seg(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        seg.update(i, x);
    }
    while (Q--) {
        int t; cin >> t;
        if (t & 1) {
            int k, x; cin >> k >> x;
            seg.update(k-1, x);
        }   else {
            int l, r; cin >> l >> r;
            cout << seg.query(l-1, r) << "\n";
        }
    }

}
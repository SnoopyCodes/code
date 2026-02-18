#include <bits/stdc++.h>

using namespace std;

template<class T, T e, auto op> struct node {
    T v = e;
    int l, r, m;
    array<node*, 2> c{};
    node(int l, int r):l(l),r(r),m((l+r)/2) {
        if (l + 1 == r) { return; }
        c[0] = new node(l, m);
        c[1] = new node(m, r);
    }
    void upd(int p, int val) {
        if (l + 1 == r) { v = val; return; }
        c[p >= m] -> upd(p, val);
        v = op(c[0]->v, c[1]->v);
    }
    T qry(int ql, int qr) {
        if (r <= ql || qr <= l) { return e; }
        if (ql <= l && r <= qr) { return v; }
        return op(c[0]->qry(ql, qr), c[1]->qry(ql, qr));
    }
};
int f(int a, int b) { return a < b ? a : b; }
const int MOD = 1e9 + 7;
#define rep(i,a,b) for (auto i=a; i<(b); i++)
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    node<int, MOD, f> seg(0, N);
    rep(i, 0, N) {
        int x; cin >> x;
        seg.upd(i, x);
    }
    rep(q, 0, Q) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            seg.upd(a - 1, b);
        }   else {
            cout << seg.qry(a - 1, b) << "\n";
        }
    }
}
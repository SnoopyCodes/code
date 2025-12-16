#include <bits/stdc++.h>

using namespace std;

//type up sparse segtree
// struct node {
//     int l, r;
//     int v;
//     array<node*, 2> c{};
//     node(int l, int r):l(l),r(r) {
//         if (l + 1 == r) { return; }
//         c[0] = new node(l, (l + r) / 2);
//         c[1] = new node((l + r) / 2, r);
//     }
//     void upd(int p, int val) {
//         if (l + 1 == r) { v = val; return; }
//         c[p < c[0]->r]->upd(p, val);
//         v = c[0]->v + c[1]->v;
//     }
//     int qry(int ql, int qr) {
//         if (r <= ql || qr <= l) { return 0; }
//         if (ql <= l && r <= qr) { return v; }
//         return c[0]->qry(ql, qr) + c[1]->qry(ql, qr);
//     }
// };

template<class T, T e, T (*op)(T, T)> struct node {
    int l, r;
    T v = e;
    array<node*, 2> c{};
    node(int l, int r):l(l),r(r) {
        if (l + 1 == r) { return; }
        c[0] = new node(l, (l + r) / 2);
        c[1] = new node((l + r) / 2, r);
    }
    void upd(int p, int val) {
        if (l + 1 == r) { v = val; return; }
        c[p < c[0]->r] -> upd(p, val);
        v = op(c[0]->v, c[1]->v);
    }
    T qry(int ql, int qr) {
        if (r <= ql || qr <= l) { return e; }
        if (ql <= l && r <= qr) { return v; }
        return op(c[0]->qry(ql, qr) + c[1]->qry(ql, qr));
    }
};
struct max_int {
    int x = 0;
};
max_int f(max_int a, max_int b) { return max_int(max(a.x, b.x)); }
int f(int a, int b) { return min(a, b); }

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    node<int, 0, f> seg(0, 5);
}
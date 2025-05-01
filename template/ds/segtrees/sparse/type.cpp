#include <bits/stdc++.h>

using namespace std;

//type up sparse segtree
struct node {
    int l, r;
    int v;
    array<node*, 2> c{};
    node(int _l, int _r):l(_l),r(_r) {
        if (l + 1 == r) { return; }
        c[0] = new node(l, (l + r) / 2);
        c[1] = new node((l + r) / 2, r);
    }
    void upd(int p, int val) {
        if (l + 1 == r) { v = val; return; }
        c[p < c[0]->r]->upd(p, val);
        v = c[0]->v + c[1]->v;
    }
    int qry(int ql, int qr) {
        if (r <= ql || qr <= l) { return 0; }
        if (ql <= l && r <= qr) { return v; }
        return c[0]->qry(ql, qr) + c[1]->qry(ql, qr);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}
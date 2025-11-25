#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct update {
    bool add = true;
    i64 val = 0;
    constexpr update(bool a, int v) { add = a; val = v; }
};
template<class V, class U, V defv, U defu, V (*comb)(V, V), U (*agg) (U, U), V (*act)(U, V)>
struct node {
    array<node*, 2> c{};
    int l, r;
    V val = defv;
    U lz = defu;
    node(int l, int r):l(l),r(r) {
        if (l + 1 == r) { return; }
        c[0] = new node(l, (l + r) / 2);
        c[1] = new node((l + r) / 2, r);
    }
    void apply(U u) {
        val = act(u, val);
        lz = agg(u, lz);
    }
    void push() {
        c[0]->apply(lz);
        c[1]->apply(lz);
        lz = defu;
    }
    V qry(int ql, int qr) {
        if (qr <= l || r <= ql) { return defv; }
        if (ql <= l && r <= qr) { return val; }
        push();
        return comb(c[0]->qry(ql, qr), c[1]->qry(ql, qr));
    }
    void upd(int ql, int qr, U u) {
        if (qr <= l || r <= ql) { return; }
        if (ql <= l && r <= qr) { return apply(u); }
        push();
        c[0]->upd(ql, qr, u);
        c[1]->upd(ql, qr, u);
        val = comb(c[0]->val, c[1]->val);
    }
};
//change: def definitions, comb, apply
i64 comb(i64 a, i64 b) { return a + b; }
update agg(update a, update b) {
    
}
i64 act(update u, i64) {

}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    node<i64, update, 0, update(false, 0), comb, agg, act>seg(0, N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        seg.upd(i, i + 1, update(false, x));
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        int l, r; cin >> l >> r; l--;
        if (t == 1) {
            int x; cin >> x;
            seg.upd(l, r, update(true, x));
        }   else if (t == 2) {
            int x; cin >> x;
            seg.upd(l, r, update(false, x));
        }   else {
            cout << seg.qry(l, r) << "\n";
        }
    }
}
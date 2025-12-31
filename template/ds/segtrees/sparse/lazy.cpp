#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct update {
    bool add = true;
    i64 val = 0;
    constexpr update(bool a, i64 v) { add = a; val = v; }
};
static char buf[40 << 20];
static size_t buf_offset = 0;

void* alloc(size_t s) {
    const size_t align = alignof(std::max_align_t);
    buf_offset = (buf_offset + align - 1) & ~(align - 1);
    if (buf_offset + s > sizeof(buf)) throw std::bad_alloc();
    void* ptr = buf + buf_offset;
    buf_offset += s;
    return ptr;
}

template<class V, class U, V defv, U defu, V (*comb)(V, V), U (*agg) (U, U), V (*act)(U, V, int l, int r)>
struct node {
    node *lc, *rc;
    int l, r;
    V val = defv;
    U lz = defu;
    node(int l, int r):l(l),r(r) {
        if (l + 1 == r) { return; }
        lc = new (alloc(sizeof(node))) node(l, (l + r) / 2);
        rc = new (alloc(sizeof(node))) node((l + r) / 2, r);
    }
    void apply(U u) {
        val = act(u, val, l, r);
        lz = agg(u, lz);
    }
    void push() {
        lc->apply(lz);
        rc->apply(lz);
        lz = defu;
    }
    V qry(int ql, int qr) {
        if (qr <= l || r <= ql) { return defv; }
        if (ql <= l && r <= qr) { return val; }
        push();
        return comb(lc->qry(ql, qr), rc->qry(ql, qr));
    }
    void upd(int ql, int qr, U u) {
        if (qr <= l || r <= ql) { return; }
        if (ql <= l && r <= qr) { return apply(u); }
        push();
        lc->upd(ql, qr, u);
        rc->upd(ql, qr, u);
        val = comb(lc->val, rc->val);
    }
};
i64 comb(i64 a, i64 b) { return a + b; }
update agg(update a, update b) {
    if (a.add == false) {
        return a;
    }
    if (a.add && !b.add) {
        return update(false, a.val + b.val);
    }
    return update(true, a.val + b.val);
}
i64 act(update u, i64 v, int l, int r) {
    if (u.add == false) {
        return (r - l) * u.val;
    }
    return v + (r - l) * u.val;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    node<i64, update, 0, update(true, 0), comb, agg, act>seg(0, N);
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
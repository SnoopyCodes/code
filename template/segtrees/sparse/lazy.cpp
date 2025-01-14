#include <bits/stdc++.h>
#define long int64_t
using namespace std;
 
struct upd {
    bool add = false;
    long val = 0;
    upd(bool a, int v) { add = a; val = v; }
};
upd defu = upd(true, 0);
long defv = 0;
template<typename V, typename U>
struct node {
    long l, r;
    node *lc = nullptr, *rc = nullptr;
    V val = defv;
    U lz = defu;
    node(long lb, long rb) { l = lb; r = rb; }
    V comb(V v1, V v2) { return v1 + v2; }
    void extend() {
        if (!lc && l + 1 < r) {
            long long m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void apply(U u) {
        if (u.add) {
            val += (r - l) * u.val;
            lz.val += u.val;
        }   else {
            val = (r - l) * u.val;
            lz = u;
        }
    }
    void push() {
        lc->apply(lz);
        rc->apply(lz);
        lz = defu;
    }
    void upd(long ql, long qr, U u) {
        if (qr <= l || r <= ql) { return; }
        extend();
        if (ql <= l && r <= qr) { apply(u); }
        else if (lc) {
            push();
            lc->upd(ql, qr, u);
            rc->upd(ql, qr, u);
            val = comb(lc->val,rc->val);
        }
    }
    V query(long ql, long qr) {
        if (qr <= l || r <= ql) { return defv; }
        if (ql <= l && r <= qr) { return val; }
        extend();
        push();
        return comb(lc->query(ql, qr),rc->query(ql, qr));
    }
    long walk(V v) {
        if (val > v) { return l - 1; }
        if (l + 1 == r) { return l; }
        extend();
        if (lc->val >= v) { return lc->walk(v); }
        return rc->walk(v);
    }
};

//change defu, defv, apply, walk, comb to needs

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    node<long, upd> *seg = new node<long, upd>(0, N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        seg->upd(i, i + 1, upd(false, x));
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        int l, r; cin >> l >> r; l--;
        if (t == 1) {
            int x; cin >> x;
            seg->upd(l, r, upd(true, x));
        }   else if (t == 2) {
            int x; cin >> x;
            seg->upd(l, r, upd(false, x));
        }   else {
            cout << seg->query(l, r) << "\n";
        }
    }
}

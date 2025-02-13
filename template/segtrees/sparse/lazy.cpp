#include <bits/stdc++.h>
#define long int64_t
using namespace std;
 //https://codeforces.com/blog/entry/136989

struct upd {
    long val = 0;
    bool add = true;
};

struct val {
    long v = 0;
};

template<typename V, typename U>
struct node {
    long l, r;
    node *lc = nullptr, *rc = nullptr;
    V val = V();
    U lz = U();
    node(long lb, long rb) { l = lb; r = rb; }
    V comb(V v1, V v2) { return V{v1.v + v2.v}; }
    //handle with care in conjunction with upd and val structs
    void apply(U u) {
        if (u.add) {
            val.v += (r - l) * u.val;
            lz.val += u.val;
        }   else {
            val.v = (r - l) * u.val;
            lz = u;
        }
    }
    void extend() {
        if (!lc && l + 1 < r) {
            long m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void push() {
        lc->apply(lz);
        rc->apply(lz);
        lz = U();
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
        if (qr <= l || r <= ql) { return V(); }
        if (ql <= l && r <= qr) { return val; }
        extend();
        push();
        return comb(lc->query(ql, qr),rc->query(ql, qr));
    }
    long walk(V v) {
        if (val.v > v.v) { return l - 1; }
        if (l + 1 == r) { return l; }
        extend();
        if (lc->val.v >= v.v) { return lc->walk(v); }
        return rc->walk(v);
    }
};

//change apply, walk, comb to needs

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    node<val, upd> *seg = new node<val, upd>(0, N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        seg->upd(i, i + 1, upd{x, false});
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        int l, r; cin >> l >> r; l--;
        if (t == 1) {
            int x; cin >> x;
            seg->upd(l, r, upd{x, true});
        }   else if (t == 2) {
            int x; cin >> x;
            seg->upd(l, r, upd{x, false});
        }   else {
            cout << seg->query(l, r).v << "\n";
        }
    }
}
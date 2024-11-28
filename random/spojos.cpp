#include <bits/stdc++.h>

using namespace std;

//could i have a moment to talk to you 
//about our lord and savior sparse segtree?

template<typename V>
struct node {
    V def = 0, val = def;
    V comb(V v1, V v2) { return v1 + v2; }
    long long l, r;
    node *lc = nullptr, *rc = nullptr;
    node(long long lb, long long rb) { l = lb, r = rb; }
    void extend() {
        if (!lc && l + 1 < r) {
            long long m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void upd(long long p, V v) {
        extend();
        if (lc) {
            if (p < lc->r) { lc->upd(p, v); }
            else { rc->upd(p, v); }
            val = comb(lc->val, rc->val);
        }   else {
            val = v;
        }
    }
    V query(long long ql, long long qr) {
        if (ql <= l && r <= qr) { return val; }
        if (l >= qr || r <= ql) { return def; }
        extend();
        return comb(lc->query(ql, qr), rc->query(ql, qr));
    }
    long long walk(V v) {
        if (v > val) { return l - 1; }
        if (l + 1 == r) { return l; }
        extend();
        if (lc->val >= v) { return lc->walk(v); }
        return rc->walk(v - lc->val);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    node<int> seg(-1e9, 1e9 + 1);
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        char c; cin >> c;
        int x; cin >> x;
        if (c == 'I') {
            seg.upd(x, 1);
        }   else if (c == 'D') {
            seg.upd(x, 0);
        }   else if (c == 'K') {
            int res = seg.walk(x);
            if (res == -1e9 - 1) { cout << "invalid" << "\n"; }
            else { cout << res << "\n"; }
        }   else {
            cout << seg.query(-1e9, x) << "\n";
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

template<typename V>
struct node {
    V def = {(int)-2e9, (int)2e9}, val = def;
    V comb(V v1, V v2) {
        return {max(v1[0], v2[0]), min(v1[1], v2[1])};
    }
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
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    //the price from the left is i - j + p
    //price from the right is j - i + p
    //so for a place i, the minimum to the left is i - max(j - p) for all j?
    //and for a place to the right is min(j + p) for all j - i ?
    node<array<int, 2>> seg(0, N);
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        seg.upd(i, {i - p, i + p});
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x; i--;
            seg.upd(i, {i - x, i + x});
        }   else {
            int i; cin >> i; i--;
            int l = seg.query(0, i)[0];
            int r = seg.query(i, N)[1];
            cout << min(i - l, r - i) << "\n";
        }
    }
}
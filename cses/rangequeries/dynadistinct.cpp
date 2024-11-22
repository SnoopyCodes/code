#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    int val = 1e9;
    node *lc = nullptr, *rc = nullptr;
    node(int lb, int rb) { l = lb, r = rb; }

    void extend() {
        if (!lc && l + 1 < r) {
            int m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void alter(int k, int x) {
        extend();
        val = min(val, x);
        if (lc) {
            if (k < lc->r) { lc->alter(k, x); }
            else { rc->alter(k, x); }
        }
    }
    int query(int ql, int qr) {
        if (ql <= l && r <= qr) { return val; }
        if (max(l, ql) >= min(r, qr)) { return 1e9; }
        extend();
        return min(lc->query(ql, qr), rc->query(ql, qr));
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    node *seg = new node(0, N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        seg->alter(i, x);
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t & 1) {
            int k, x; cin >> k >> x; k--;
            seg->alter(k, x - seg->query(k, k + 1));
        }   else {
            int l, r; cin >> l >> r; l--;
            cout << seg->query(l, r) << "\n";
        }
    }
}
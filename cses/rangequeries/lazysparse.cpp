#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
    int l, r;
    node *lc = nullptr, *rc = nullptr;
    ll lz = 0, val = 0;  //- is set, + is add, assume we did this to our value already
    node(int lb, int rb) { l = lb; r = rb; }
    void extend() {
        if (!lc && l + 1 < r) {
            int m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void apply(ll v) {
        if (v > 0) {
            val += (r - l) * v;
            if (lz < 0) { lz -= v; }
            else { lz += v; }
        }   else if (v < 0) {
            val = (r - l) * -v;
            lz = v;
        }
    }
    void push() {
        lc->apply(lz);
        rc->apply(lz);
        lz = 0;
    }
    void upd(int ql, int qr, ll v) {
        if (qr < l || ql > r) { return; }
        extend();
        if (ql <= l && r <= qr) { apply(v); }
        else if (lc) {
            push();
            lc->upd(ql, qr, v);
            rc->upd(ql, qr, v);
            val = lc->val + rc->val;
        }
    }
    ll query(int ql, int qr) {
        if (max(l, ql) >= min(r, qr)) { return 0; }
        if (ql <= l && r <= qr) { return val; }
        extend();
        push();
        return lc->query(ql, qr) + rc->query(ql, qr);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    node *seg = new node(0, N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        seg->upd(i, i + 1, x);
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        int l; cin >> l; l--;
        if (t == 1) {
            int x; cin >> x;
            seg->upd(l, l + 1, -x);
        }   else {
            int r; cin >> r;
            cout << seg->query(l, r) << "\n";
        }
    }
}
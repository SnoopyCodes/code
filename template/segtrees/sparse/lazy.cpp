#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T, typename F>
struct node {
    long long l, r;
    node *lc = nullptr, *rc = nullptr;
    T lz = 0, val = 0;  //- is set, + is add, assume we did this to our value already
    node(long long lb, long long rb) { l = lb; r = rb; }
    T comb(T t1, T t2) { return t1 + t2; }
    void extend() {
        if (!lc && l + 1 < r) {
            long long m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void apply(F v) {
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
    void upd(long long ql, long long qr, F v) {
        if (qr < l || ql > r) { return; }
        extend();
        if (ql <= l && r <= qr) { apply(v); }
        else if (lc) {
            push();
            lc->upd(ql, qr, v);
            rc->upd(ql, qr, v);
            val = comb(lc->val,rc->val);
        }
    }
    T query(long long ql, long long qr) {
        if (max(l, ql) >= min(r, qr)) { return 0; }
        if (ql <= l && r <= qr) { return val; }
        extend();
        push();
        return comb(lc->query(ql, qr),rc->query(ql, qr));
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    node<ll, ll> *seg = new node<ll, ll>(0, N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        seg->upd(i, i + 1, x);
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        int l, r; cin >> l >> r; l--;
        if (t == 1) {
            int x; cin >> x;
            seg->upd(l, r, x);
        }   else if (t == 2) {
            int x; cin >> x;
            seg->upd(l, r, -x);
        }   else {
            cout << seg->query(l, r) << "\n";
        }
    }
}
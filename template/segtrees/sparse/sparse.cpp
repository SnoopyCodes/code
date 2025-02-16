#include <bits/stdc++.h>
#define long int64_t
using namespace std;
const long INFL = 1e18;
template<typename V>
struct node {
    V def = 0, val = def;
    V comb(V v1, V v2) { return max(v1, v2); }
    long l, r;
    node *lc = nullptr, *rc = nullptr;
    node(long lb, long rb) { l = lb, r = rb; }
    void extend() {
        if (!lc && l + 1 < r) {
            long m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void upd(long p, V v) {
        extend();
        if (lc) {
            if (p < lc->r) { lc->upd(p, v); }
            else { rc->upd(p, v); }
            val = comb(lc->val, rc->val);
        }   else {
            val = v;
        }
    }
    V query(long ql, long qr) {
        if (ql <= l && r <= qr) { return val; }
        if (qr <= l || r <= ql) { return def; }
        extend();
        return comb(lc->query(ql, qr), rc->query(ql, qr));
    }
    long walk(V v, long ql = -INFL, long qr = INFL + 1) {
        if (v > val) { return -INFL - 1; }
        if (qr <= l || r <= ql) { return -INFL - 1; }
        if (l + 1 == r) { return l; }
        extend();
        if (lc->val >= v && ql < (l + r) / 2) {
            long res =  lc->walk(v, ql, qr);
            if (res != -INFL - 1) { return res; }
        }
        return rc->walk(v, ql, qr);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    node<int> *seg = new node<int>(0, N);
    for (int i = 0; i < N; i++) {
        int h; cin >> h;
        seg->upd(i, h);
    }
    for (int i = 0; i < M; i++) {
        int rooms, l, r; cin >> rooms >> l >> r; l--;
        //2 5
        long h = seg->walk(rooms, l, r);
        if (h != -INFL-1) {
            cout << h + 1 <<  " ";
            seg->upd(h, seg->query(h, h + 1) - rooms);
        }   else {
            cout << 0 << " ";
        }
    }
    cout << "\n";
}
//includes all main functionality-- i like it better than iterative for this
//comparison: without init() function of iter then iter is 33 lines vs 38 for sparse
//but init() is tricky with iter when walking on segtree
//be VERY CAREFUL with walk
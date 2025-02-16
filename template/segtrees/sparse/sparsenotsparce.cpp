#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

//for array range queries... maybe i should learn normal segtree?
template<typename V>
struct node {
    V def = 0, val = def;
    V comb(V v1, V v2) { return max(v1, v2); }
    int l, r;
    node *lc = nullptr, *rc = nullptr;
    node(int lb, int rb) { l = lb, r = rb; }
    void extend() {
        if (!lc && l + 1 < r) {
            long m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void upd(int p, V v) {
        extend();
        if (lc) {
            if (p < lc->r) { lc->upd(p, v); }
            else { rc->upd(p, v); }
            val = comb(lc->val, rc->val);
        }   else {
            val = v;
        }
    }
    V query(int ql, int qr) {
        if (ql <= l && r <= qr) { return val; }
        if (qr <= l || r <= ql) { return def; }
        extend();
        return comb(lc->query(ql, qr), rc->query(ql, qr));
    }
    int walk(V v, int ql = 0, int qr = INF + 1) {
        if (v > val) { return -1; }
        if (qr <= l || r <= ql) { return -1; }
        if (l + 1 == r) { return l; }
        extend();
        if (lc->val >= v && ql < (l + r) / 2) {
            int res =  lc->walk(v, ql, qr);
            if (res != -INFL - 1) { return res; }
        }
        return rc->walk(v, ql, qr);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}
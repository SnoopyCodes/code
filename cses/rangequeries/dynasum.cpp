#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
struct node {
    int l, r;
    ll sum = 0;
    node *lc = nullptr, *rc = nullptr;
    node(int lb, int rb) { l = lb, r = rb; }
 
    void extend() {
        if (!lc && l + 1 < r) {
            int m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);        
        }
    }
    void add(int k, ll x) {
        extend();
        sum += x;
        if (lc) {
            if (k < lc->r) { lc->add(k, x); }
            else { rc -> add(k, x); }
        }
    }

    
    ll query(int ql, int qr) {
        if (ql <= l && r <= qr) { return sum; }
        if (max(l, ql) >= min(r, qr)) { return 0; }
        extend();
        return lc->query(ql, qr) + rc->query(ql, qr);
    }
};
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    node *root = new node(0, N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        root->add(i, x);
    }
    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        if (t & 1) {
            int k, x; cin >> k >> x; k--;
            root->add(k, x - root->query(k, k + 1));
        }   else {
            int l, r; cin >> l >> r; l--;
            cout << root->query(l, r) << "\n";
        }
    }

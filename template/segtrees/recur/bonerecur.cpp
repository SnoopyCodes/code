#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int SN;
vector<long> seg;

int ind, val, ql, qr, def;
void init(int _n) {
    SN = _n;
    seg.resize(4*SN, def);
}

#define m (l + r) / 2
#define lc p * 2
#define rc p * 2 + 1

long q(int p = 1, int l=0, int r = SN) {
    if(r <= ql || qr <= l) { return def; }
    if(ql <= l && r <= qr) { return seg[p]; }
    return q(lc, l, m) + q(rc, m, r);
}

void upd(int p = 1, int l = 0, int r = SN) {
    if(l + 1 == r) { seg[p] = val; return; }
    if(ind < m) { upd(lc, l, m); }
    else { upd(rc, m, r); }
    seg[p] = seg[lc] + seg[rc];
}

long query(int l, int r) { ql = l, qr = r; return q(); }
void update(int idx, int vax) { ind = idx, val = vax; upd(); }

#undef m

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    init(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        update(i, x);
    }
    while (Q--) {
        int t; cin >> t;
        if (t & 1) {
            int k, x; cin >> k >> x;
            update(k-1, x);
        }   else {
            int l, r; cin >> l >> r;
            cout << query(l-1, r) << "\n";
        }
    }
}
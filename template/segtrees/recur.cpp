#include <bits/stdc++.h>

using namespace std;

vector<int> A;
vector<int> seg;

void build(int l = 0, int r = A.size() - 1, int i = 1) {
    if (l == r) { seg[i] = A[l]; return; }
    int m = (l + r) / 2;
    build(l, m, 2 * i);
    build(m + 1, r, 2 * i + 1);
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

void make(int p, int val, int i=1, int l=0, int r=A.size()-1) {
    if (l == r) { seg[i] = val; return; }
    int m = (l + r) / 2;
    if (p <= m) { make(p, val, 2 * i, l, m); }
    else { make(p, val, 2 * i + 1, m + 1, r); }
    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
}

int q(int ql, int qr, int i=1, int l=0, int r=A.size()-1) {
    if (r < ql || qr < l) { return 1e9; }
    if (ql <= l && r <= qr) { return seg[i]; }
    int m = (l + r) / 2;
    return min(q(ql, qr, 2 * i, l, m), q(ql, qr, 2 * i + 1, m + 1, r));
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //learn recursive
    int N, Q; cin >> N >> Q;
    seg.resize(4 * N);
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    build();
    while (Q--) {
        int t; cin >> t;
        if (t & 1) {
            int k, x; cin >> k >> x;
            make(k-1, x);
        }   else {
            int l, r; cin >> l >> r;
            cout << q(l-1, r-1) << "\n";
        }
    }
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> seg;
int SN;
void init(vector<ll>& v) {
    SN = v.size();
    seg.resize(2 * SN);
    for (int i = 0; i < v.size(); i++) { seg[i + SN] = v[i]; }
    for (int i = SN - 1; i > 0; i--) { seg[i] = min(seg[2 * i],seg[2 * i + 1]); }
}
ll query(int l, int r) {
    ll res = 1e18;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res = min(res, seg[l++]); }
        if (r & 1) { res = min(res, seg[--r]); }
    }
    return res;
}
void alter(int p, ll val) {
    seg[p + SN] = val;
    for (p = (p + SN) / 2; p > 0; p /= 2) {
        seg[p] = min(seg[2 * p], seg[2 * p + 1]);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    seg.resize(2 * N);
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    init(A);
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t & 1) {
            int k, x; cin >> k >> x; k--;
            alter(k, x);
        }   else {
            int l, r; cin >> l >> r; l--;
            cout << query(l, r) << "\n";
        }
    }
}
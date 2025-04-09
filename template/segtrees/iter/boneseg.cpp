#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
vector<int> seg;
int SN;

int query(int l, int r) {
    int res = 0;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res += seg[l++]; }
        if (r & 1) { res += seg[--r]; }
    }
    return res;
}
void alter(int p, long val) {
    seg[p + SN] = val;
    for (p = (p + SN) / 2; p > 0; p /= 2) {
        seg[p] = min(seg[2 * p], seg[2 * p + 1]);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    SN = N;
    seg.resize(2 * N);
    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        alter(i, A[i]);
    }
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
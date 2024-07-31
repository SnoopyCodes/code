#include <bits/stdc++.h>
#define ll long long
using namespace std;
//implement segtree
int N;
vector<ll> seg;
void init() {
    for (int i = N-1; i >= 1; i--) {
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }
}
void alter(int pos, int val) {
    seg[N + pos] = val;
    for (pos = (N + pos) >> 1; pos > 0; pos >>= 1) {
        seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
    }
}
ll query(int l, int r) {
    ll total = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) { total += seg[l]; l++; }
        if (r & 1) { total += seg[--r]; }
    }
    return total;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> N >> Q;
    seg.resize(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> seg[N + i];
    }
    init();
    for (int i = 0; i < Q; i++) {
        int t, k, u;
        cin >> t >> k >> u;
        if (t == 1) {
            alter(k-1, u);
        }   else {
            cout << query(k-1, u) << "\n";
        }
    }
}
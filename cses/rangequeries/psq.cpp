#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> seg;  //largest
vector<ll> bestpfx;
int N;
void modify(int p, int val) {
    seg[p + N] = val;
    bestpfx[p + N] = max(seg[p + N], 0LL);
    for (p = (p + N) / 2; p > 0; p /= 2) {
        seg[p] = seg[2 * p] + seg[2 * p + 1];
        bestpfx[p] = max(bestpfx[2 * p], seg[2 * p] + bestpfx[2 * p + 1]);
    }
}
ll query(int l, int r) {
    ll ansl = 0;
    ll suml = 0;
    ll ansr = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            ansl = max(ansl, suml + bestpfx[l]);
            suml += seg[l];
            l++;
        }
        if (r & 1) {
            r--;
            ansr = max(bestpfx[r], ansr + seg[r]);
        }
    }
    return max(ansl, suml + ansr);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> N >> Q;
    //we will maintain for each range the full sum
    //and the maximum prefix sum
    seg.resize(2 * N);
    bestpfx.resize(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> seg[i + N];
        bestpfx[i + N] = max(0LL, seg[i + N]);
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = seg[2 * i] + seg[2 * i + 1];
        //return the max pfx sum between the two segments
        bestpfx[i] = max(bestpfx[2 * i], seg[2 * i] + bestpfx[2 * i + 1]);
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int pos, val; cin >> pos >> val;
            modify(pos-1, val);
        }   else {
            int l, r; cin >> l >> r; l--;
            cout << query(l, r) << "\n";
        }
    }
}
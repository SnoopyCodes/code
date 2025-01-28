#include <bits/stdc++.h>
#define long int64_t
using namespace std;

vector<long> seg;
int N;
void upd(int p, long val) {
    seg[p + N] = val;
    for (p = (p + N) / 2; p > 0; p /= 2) {
        seg[p] = seg[2 * p] + seg[2 * p + 1];
    }
}

long query(int l, int r) {
    long res = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { res += seg[l++]; }
        if (r & 1) { res += seg[--r]; }
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> N >> Q;
    seg.resize(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> seg[i + N];
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int p, val; cin >> p >> val; p--;
            upd(p, seg[p + N] + val);
        }   else {
            int l, r; cin >> l >> r; l--;
            cout << query(l, r) << "\n";
        }
    }
}
#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int N;
vector<long> seg;

void alter(int l, int r, int val) {
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { seg[l++] += val; }
        if (r & 1) { seg[--r] += val; }
    }
}

long query(int p) {
    long res = 0;
    for (p += N; p > 0; p /= 2) {
        res += seg[p];
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> N >> Q;
    seg.resize(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> seg[N + i];
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, x; cin >> l >> r >> x; l--;
            alter(l, r, x);
        }   else {
            int i; cin >> i; i--;
            cout << query(i) << "\n";
        }
    }
}
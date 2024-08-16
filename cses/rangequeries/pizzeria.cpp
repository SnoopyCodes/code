#include <bits/stdc++.h>

using namespace std;
int N;
vector<array<int, 2>> seg;
vector<int> vals;
array<int, 2> comb(array<int, 2> i, array<int, 2> j) {
    array<int, 2> tmp;
    tmp[0] = min(i[0], j[0]);
    tmp[1] = min(i[1], j[1]);
    return tmp;
}
void modify(int p, int val) {
    seg[p + N][0] = val - p, seg[p + N][1] = val + p;
    for (p = (p + N) / 2; p > 0; p /= 2) {
        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
    }
}
array<int, 2> query(int l, int r) {
    array<int, 2> ansl{(int)2e9, (int) 2e9};
    array<int, 2> ansr{(int)2e9, (int) 2e9};
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { ansl = comb(seg[l++], ansl); }
        if (r & 1) { ansr = comb(seg[--r], ansr); }
    }
    return comb(ansl, ansr);
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> N >> Q;
    vals.resize(N);
    seg.resize(2 * N, {(int)2e9, (int)2e9});
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        seg[N + i][0] = seg[N + i][1] = vals[i];
        seg[N + i][0] -= i; seg[N + i][1] += i;
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = comb(seg[2 * i], seg[2 * i + 1]);
    }
    //we will store best index going left, and best index going right
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int k, x; cin >> k >> x; k--;
            modify(k, x);
        }   else {
            int p; cin >> p; p--;
            cout << min(query(0, p)[0] + p, query(p, N)[1] - p) << "\n";
        }
    }
}
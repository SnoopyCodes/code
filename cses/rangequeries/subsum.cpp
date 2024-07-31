#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int N;
vector<array<ll, 4>> seg;
// we want to be able to combine
// so we have like best going left=2, best going right=3
// best overall=0, overall sum=1?
// 
array<ll, 4> comb(array<ll, 4> i, array<ll, 4> j) {
    array<ll, 4> res;
    res[0] = max(max(i[0], j[0]), i[3] + j[2]);
    res[1] = i[1] + j[1];
    res[2] = max(i[2], i[1] + j[2]);
    res[3] = max(j[3], i[3] + j[1]);
    return res;
}
void modify(int p, int val) {
    seg[p + N][0] = max(val, 0);
    seg[p + N][1] = val;
    seg[p + N][2] = seg[p + N][0];
    seg[p + N][3] = seg[p + N][0];
    for (p = (p + N) / 2; p > 0; p /= 2) {
        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
    }
}
ll query(int l, int r) {
    array<ll, 4> ansl{};
    array<ll, 4> ansr{};
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { ansl = comb(ansl, seg[l++]); }
        if (r & 1) { ansr = comb(seg[--r], ansr); }
    }
    return comb(ansl, ansr)[0];
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> N >> Q;
    seg.resize(2 * N);
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        seg[i + N][0] = max(k, 0);
        seg[i + N][1] = k;
        seg[i + N][2] = seg[i + N][0];
        seg[i + N][3] = seg[i + N][0];
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = comb(seg[2 * i], seg[2 * i + 1]);
    }
    for (int q = 0; q < Q; q++) {
        int p, val; cin >> p >> val;
        modify(p-1, val);
        cout << query(0, N) << "\n";
    }
}
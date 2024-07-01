#include <bits/stdc++.h>

using namespace std;
vector<int> v;
struct Segtree{
    vector<int> seg;
    int N;
    void init() {
        N = v.size();
        seg.resize(2 * N);
        for (int i = 0; i < N; i++) {
            seg[i + N] = v[i];
            if (i + N == 9) {
            }
        }
        for (int i = N - 1; i > 0; i--) {
            seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
        }
    }
    int query(int l, int r) {
        int ans = INT_MAX;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) { ans = min(seg[l++], ans); }
            if (r & 1) { ans = min(seg[--r], ans); }
        }
        return ans;
    }
    void modify(int p, int v) {
        seg[p + N] = v;
        for (p = (p + N) / 2; p > 0; p /= 2) {
            seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    Segtree seg;
    seg.init();
    for (int q = 0; q < Q; q++) {
        int t, a, b; cin >> t  >> a >> b;
        a--;
        if (t == 1) {
            seg.modify(a, b);
        }   else {
            cout << seg.query(a, b) << "\n";
        }
    }
}
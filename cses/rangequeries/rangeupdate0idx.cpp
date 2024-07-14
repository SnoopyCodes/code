#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> seg;
int N;
void init() {
    for (int i = N - 1; i > 0; i--) {
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }
}
ll query(int r) {  //add from 0 to p, where p is right border
    int l = 0;
    ll um = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) { um += seg[l++]; }
        if (r & 1) { um += seg[--r]; }
    }
    return um;
}
void update(int l, int r, int v) {  //[l, r)
    //wait if we first push the things to update
    bool no = r == N;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        seg[l] += v;
        if (!no)
        seg[r] -= v;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> N >> Q;
    seg.resize(2 * N);
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    seg[N] = v[0];
    for (int i = 1; i < N; i++) {
        seg[i + N] = v[i] - v[i-1];
    }
    init();
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, v; cin >> a >> b >> v;
            update(a-1, b, v);
        }   else {
            int k; cin >> k;
            cout << query(k) << "\n";
        }
    }
}
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
ll query(int p) {  //this is we just run upwards
    ll um = 0;
    for (p += N; p > 0; p >>= 1) {
        um += seg[p];
    }
    return um;
}
void update(int l, int r, int v) {  //[l, r)
    //wait if we first push the things to update
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) { seg[l++] += v; }
        if (r & 1) { seg[--r] += v; }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> N >> Q;
    seg.resize(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> seg[i + N];
    }
    init();
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, v; cin >> a >> b >> v;
            update(a-1, b, v);
        }   else {
            int k; cin >> k;
            cout << query(k-1) << "\n";
        }
    }
}
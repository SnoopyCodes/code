#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> seg;
int N;
void init() {
    for (int i = N; i > 0; i--) {
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }
}
ll query(int r) {  //add from 0 to p, where p is right border
    int l = 1;
    ll um = 0;
    for (l += N+1, r += N+1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) { um += seg[l++]; }
        if (r & 1) { um += seg[--r]; }
    }
    return um;
}
void update(int l, int r, int v) {  //[l, r)
    //wait if we first push the things to update
    for (l += N+1, r += N+1; l < r; l >>= 1, r >>= 1) {
        seg[l] += v;
        seg[r] -= v;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> N >> Q;
    seg.resize(2 * (N + 1));
    int prev = 0;
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        seg[i + (N + 1)] = k - prev;
        prev = k;
    }
    init();
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, v; cin >> a >> b >> v;
            update(a, b+1, v);
        }   else {
            int k; cin >> k;
            cout << query(k+1) << "\n";
        }
    }
}
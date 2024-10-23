#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> seg;
int SN;
void init(int N) {
    SN = N;
    seg.resize(2 * SN);
}
ll query(int l, int r) {  //[l, r)
    ll res = 0;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res = max(res, seg[l++]); }
        if (r & 1) { res = max(res, seg[--r]); }
    }
    return res;
}
void alter(int p, ll val) {
    seg[p + SN] = val;
    for (p = (p + SN) / 2; p > 0; p /= 2) {
        seg[p] = max(seg[2 * p], seg[2 * p + 1]);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //for the LIS ending at every element, calculate the sum of all elements in there
    int N; cin >> N;
    vector<int> H(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i]; H[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    init(N);
    vector<int> lis(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll lis = query(0, H[i] + 1);
        alter(H[i], lis + B[i]);
    }
    cout << query(0, N) << "\n";
}
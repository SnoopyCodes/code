#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> seg;
int SN;
void init(vector<ll>& v) {
    SN = v.size();
    seg.resize(2 * SN);
    for (int i = 0; i < v.size(); i++) { seg[i + SN] = v[i]; }
    for (int i = SN - 1; i > 0; i--) { seg[i] = seg[2 * i] + seg[2 * i + 1]; }
}
ll query(int l, int r) {
    ll res = 0;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res += seg[l++]; }
        if (r & 1) { res += seg[--r]; }
    }
    return res;
}
void alter(int p, ll val) {
    seg[p + SN] = val;
    for (p = (p + SN) / 2; p > 0; p /= 2) {
        seg[p] = seg[2 * p] + seg[2 * p + 1];
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}
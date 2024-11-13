#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
vector<ll> seg;
vector<ll> make;
vector<ll> add;
int SN, H;
 
void init(vector<int>& v) {
    SN = v.size();
    H = 32 - __builtin_clz(SN);
    seg.resize(2 * SN);
    add.resize(SN);
    make.resize(SN);
    for (int i = 0; i < SN; i++) { seg[i + SN] = v[i]; }
    for (int i = SN - 1; i > 0; i--) { seg[i] = seg[2 * i] + seg[2 * i + 1]; }
}
 
void calc(int p, int len) {
    if (make[p] == 0) { seg[p] = seg[2 * p] + seg[2 * p + 1]; }
    else { seg[p] = make[p] * len; }
    seg[p] += add[p] * len;
}
void apply(int p, ll val, int len, int t) {  //t = 0 is make
    if (t == 0) {
        seg[p] = val * len;
        if (p < SN) { make[p] = val; add[p] = 0; }
    }   else {
        seg[p] += val * len;
        if (p < SN) { add[p] += val; }
    }
}
 
void climb(int p) {
    int len = 2;
    for (p = (p + SN) / 2; p >= 1; len *= 2, p /= 2) {
        calc(p, len);
    }
}
void drop(int p) {
    int lvl = H, len = 1 << (H - 1);
    for (p += SN; lvl > 0; lvl--, len /= 2) {
        int i = p >> lvl;
        if (make[i] != 0) {
            apply(2 * i, make[i], len, 0);
            apply(2 * i + 1, make[i], len, 0);
            make[i] = 0;
        }
        if (add[i] != 0) {
            apply(2 * i, add[i], len, 1);
            apply(2 * i + 1, add[i], len, 1);
            add[i] = 0;
        }
    }
}
 
void alter(int l, int r, int val, int t) {
    drop(l);
    drop(r - 1);
    int li = l, ri = r, len = 1;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2, len *= 2) {
        if (l & 1) { apply(l++, val, len, t); }
        if (r & 1) { apply(--r, val, len, t); }
    }
    climb(li);
    climb(ri - 1);
}
ll query(int l, int r) {
    drop(l);
    drop(r - 1);
    ll res = 0;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res += seg[l++]; }
        if (r & 1) { res += seg[--r]; }
    }
    return res;
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(arr);
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        int l, r; cin >> l >> r;
        l--;
        if (t == 1) {
            int inc; cin >> inc;
            alter(l, r, inc, 1);
        }   else if (t == 2) {
            int val; cin >> val;
            alter(l, r, val, 0);
        }   else {
            cout << query(l, r) << "\n";
        }
    }

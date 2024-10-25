#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> seg;
vector<int> make;
int SN, H;
void init(vector<int>& v) {
    SN = v.size();
    H = 32 - __builtin_clz(SN);
    seg.resize(2 * SN);
    make.resize(SN);
    for (int i = 0; i < SN; i++) { seg[i + SN] = v[i]; }
    for (int i = SN - 1; i > 0; i--) { seg[i] = seg[2 * i] + seg[2 * i + 1]; }
}

void calc(int p, int len) {
    if (make[p] == 0) { seg[p] = seg[2 * p] + seg[2 * p + 1]; }
    else { seg[p] = (ll) make[p] * len; }
}
void apply(int p, int val, int len) {
    seg[p] = (ll) val * len;
    make[p] = val * (p < SN);
}

void build1(int l) {
  int k = 2;
  for (l += SN; l > 1; k <<= 1) {
    l >>= 1;
    calc(l, k);
  }
}
void push1(int l) {
  int s = SN, k = 1 << (H - 1);
  for (l += SN; s > 0; --s, k >>= 1) {
    int i = l >> s;
    if (make[i] != 0) {
      apply(i << 1, make[i], k);
      apply(i << 1 | 1, make[i], k);
      make[i] = 0;
    }
  }
}
void alter(int l, int r, int value) {
  if (value == 0)
    return;
  push1(l);
  push1(r - 1);
  int l0 = l, r0 = r, k = 1;
  for (l += SN, r += SN; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l & 1)
      apply(l++, value, k);
    if (r & 1)
      apply(--r, value, k);
  }
  build1(l0);
  build1(r0 - 1);
}
int query(int l, int r) {
  int res = 0;
  for (l += SN, r += SN; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      res += seg[l++];
    if (r & 1)
      res += seg[--r];
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
            // alter(l, r, inc);
        }   else if (t == 2) {
            int val; cin >> val;
            alter(l, r, val);
        }   else {
            cout << query(l, r) << endl;
        }
    }
}

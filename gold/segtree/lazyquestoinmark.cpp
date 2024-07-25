#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> seg;
vector<ll> upd;
int N, H;
void apply(int p, ll val, int range) {
    seg[p] += val * range;
    if (p < N) { upd[p] = val; }
}
void calc(int p, int range) {
    seg[p] = seg[2 * p] + seg[2 * p + 1];
    if (upd[p] != 0) { seg[p] += upd[p] * range; }
}
void build(int l, int r) {
  int k = 2;
  for (l += N, r += N-1; l > 1; k *= 2) {
    l /= 2, r /= 2;
    for (int i = r; i >= l; --i) calc(i, k);
  }
}

void push(int l, int r) {
  int s = H, k = 1 << (H-1);
  for (l += N, r += N-1; s > 0; --s, k /= 2)
    for (int i = l >> s; i <= r >> s; ++i) if (upd[i] != 0) {
      apply(2 * i, upd[i], k);
      apply(2 * i + 1, upd[i], k);
      upd[i] = 0;
    }
}
void modify(int l, int r, int value) {
  if (value == 0) return;
  push(l, l + 1);
  push(r - 1, r);
  int l0 = l, r0 = r, k = 1;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l&1) apply(l++, value, k);
    if (r&1) apply(--r, value, k);
  }
  build(l0, l0 + 1);
  build(r0 - 1, r0);
}

int query(int l, int r) {
  push(l, l + 1);
  push(r - 1, r);
  int res = 0;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += seg[l++];
    if (r&1) res += seg[--r];
  }
  return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //sum
    int M; cin >> N >> M;
    H = 32 - __builtin_clz(N);
    seg.resize(2 * N);
    upd.resize(N);
    for (int i = 0; i < M; i++) {
        cout << i << endl;
        int t; cin >> t;
        if (t == 1) {
            int l, r, val; cin >> l >> r >> val;
            r++;
            modify(l, r, val);
        }   else {
            int l, r; cin >> l >> r;
            r++;
            cout << query(l, r) << "\n";
        }
    }
}
#include <iostream>
using namespace std;
#define int long long
const int N = 2e5;
int n;
int h;
int rsq[2 * N], lazy[N];
void calc(int p, int k) {
  if (lazy[p] == 0)
    rsq[p] = rsq[p << 1] + rsq[p << 1 | 1];
  else
    rsq[p] = lazy[p] * k;
}
void apply(int p, int value, int k) {
  rsq[p] = value * k;
  if (p < n)
    lazy[p] = value;
}
void build(int l, int r) {
  int k = 2;
  for (l += n, r += n - 1; l > 1; k <<= 1) {
    l >>= 1, r >>= 1;
    for (int i = r; i >= l; --i)
      calc(i, k);
  }
}
void build1(int l) {
  int k = 2;
  for (l += n; l > 1; k <<= 1) {
    l >>= 1;
    calc(l, k);
  }
}
void push1(int l) {
  int s = h, k = 1 << (h - 1);
  for (l += n; s > 0; --s, k >>= 1) {
    int i = l >> s;
    if (lazy[i] != 0) {
      apply(i << 1, lazy[i], k);
      apply(i << 1 | 1, lazy[i], k);
      lazy[i] = 0;
    }
  }
}
void modify(int l, int r, int value) {
  if (value == 0)
    return;
  push1(l);
  push1(r - 1);
  int l0 = l, r0 = r, k = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l & 1)
      apply(l++, value, k);
    if (r & 1)
      apply(--r, value, k);
  }
  build1(l0);
  build1(r0 - 1);
}
int get_sum(int l, int r) {
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      res += rsq[l++];
    if (r & 1)
      res += rsq[--r];
  }
  return res;
}
void solve() {
        cin.tie(0) -> sync_with_stdio(0);
  int m;
  cin >> n >> m;
  h = sizeof(int) * 8 - __builtin_clzll(n);
  for (int i = 0; i < n; i++) {
    cin >> rsq[n + i];
  }
  build(0, n);
  while (m--) {
    int t; cin >> t;
    int l, r; cin >> l >> r; l--;
    if (t == 2) {
        int val; cin >> val;
        modify(l, r, val);
    }   else if (t == 3) {
        cout << get_sum(l, r) << "\n";
    }
  }
  cout << "\n";
}
signed main() {
    solve();
}
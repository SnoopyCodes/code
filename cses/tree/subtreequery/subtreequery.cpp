#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N;
vector<vector<int>> tree;
vector<ll> val;
vector<ll> seg;
vector<int> beg;
vector<int> stop;
int vis = 0;
void dfs(int i, int from) {
    beg[i] = vis++;
    for (int x : tree[i]) {
        if (x == from) { continue; }
        dfs(x, i);
    }
    stop[i] = vis;
}
void update(int pos, int val) {
    seg[pos + N] = val;
    for (pos = (pos + N) / 2; pos > 0; pos >>= 1) {
        seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
    }
}
ll query(int l, int r) {
    ll total = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) { total += seg[l++]; }
        if (r & 1) { total += seg[--r]; }
    }
    return total;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> N >> Q;
    tree.resize(N);
    val.resize(N);
    seg.resize(2 * N);
    beg.resize(N);
    stop.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, -1);
    for (int i = 0; i < N; i++) { update(beg[i], val[i]); }
    for (int q  = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 2) {
            int x; cin >> x; x--;
            cout << query(beg[x], stop[x]) << "\n";
        }   else {
            int pos, val; cin >> pos >> val;
            pos--;
            update(beg[pos], val);
        }
    }
}
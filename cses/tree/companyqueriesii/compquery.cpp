#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> tree;
vector<int> depth;
vector<int> seg;
vector<int> newi;
vector<int> euler;
void dfs(int v, int h) {
    newi[v] = euler.size();
    depth[v] = h;
    euler.push_back(v);
    for (int i : tree[v]) {
        dfs(i, h+1);
        euler.push_back(v);
    }
}
int comp(int a, int b) {
    if (a == -1) { return b; }
    if (b == -1) { return a; }
    return (depth[a] < depth[b] ? a : b);
}
void init() {
    for (int i = 0; i < N; i++) {
        seg[i+N] = euler[i];
    }
    for (int i = N-1; i > 0; i--) {
        seg[i] = comp(seg[i << 1], seg[i << 1 | 1]);
    }
}
int query(int l, int r) {
    int m = -1;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) { m = comp(m, seg[l++]); }
        if (r & 1) { m = comp(m, seg[--r]); }
    }
    return m;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> N >> Q;
    tree.resize(N);
    depth.resize(N);
    newi.resize(N);
    for (int i = 1; i < N; i++) {
        int a; cin >> a; a--;
        tree[a].push_back(i);
    }
    dfs(0, 0);
    N = euler.size();  //do not do this
    seg.resize(2 * N + 1, -1);
    init();
    for (int q = 0; q < Q; q++) {
        int a, b; cin >> a >> b; a--; b--;
        if (newi[b] < newi[a]) { swap(a, b); }
        cout << query(newi[a], newi[b]+1)+1 << "\n";
    }
}
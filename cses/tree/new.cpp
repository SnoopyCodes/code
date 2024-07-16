#include <bits/stdc++.h>
 
using namespace std;
vector<vector<int>> tree;
vector<int> start;
vector<int> par;
vector<int> depth;
vector<int> seg;
int n;
int euler = 0;
void dfs(int v, int d) {
    start[v] = euler;
    depth[v] = d;
    euler++;
    for (int x : tree[v]) {
        dfs(x, d + 1);
    }
}
int comp(int u, int v) {
    return depth[v] < depth[u] ? v : u;
}
void init() {
    seg.resize(2 * n);
    for (int i = 0; i < n; i++) {
        seg[start[i] + n] = i;
    }
    for (int i = n - 1; i > 0; i--) {
        seg[i] = comp(seg[i * 2], seg[i * 2 + 1]);
    }
}
int query(int l, int r) {
    int ans = seg[l + n];
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) { ans = comp(ans, seg[l++]); }
        if (r & 1) { ans = comp(ans, seg[--r]); }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> n >> q;
    tree.resize(n);
    start.resize(n);
    depth.resize(n);
    par.resize(n);
    for (int i = 1; i < n; i++) {
        int b; cin >> b; b--;
        tree[b].push_back(i);
        par[i] = b;
    }
    dfs(0, 0);
    init();
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--; b--;
        if (start[b] < start[a]) { swap(a, b); }
        if (a == b) { cout << a+1 << "\n"; continue; }
        cout << par[query(start[a] + 1, start[b] + 1)] + 1 << "\n";
    }
}
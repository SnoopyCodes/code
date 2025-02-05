#include <bits/stdc++.h>
#define rsz resize
#define size sz
#define len(x) (int) (x.end() - x.begin())
#define in(x, y) bool(x.find(y) != x.end())
using namespace std;

int N;
vector<vector<int>> tree;
vector<int> depth, parent, size, in, heavy, val;
int euler = 0;

vector<int> seg;
void alter(int p, int val) {
    seg[p + N] = val;
    for (p = (p + N) / 2; p > 0; p /= 2) {
        seg[p] = max(seg[2 * p], seg[2 * p + 1]);
    }
}

int query(int l, int r) {
    int res = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { res = max(res, seg[l++]); }
        if (r & 1) { res = max(res, seg[--r]); }
    }
    return res;
}

void dfs_size(int u, int p) {
    for (int &v : tree[u]) {
        if (v == p && v != tree[u].back()) { swap(v, tree[u].back()); }
        if (v == p) { continue; }
        depth[v] = depth[u] + 1;
        parent[v] = u;
        dfs_size(v, u);
        size[u] += size[v];
        if (size[v] > size[tree[u][0]]) { swap(v, tree[u][0]); }
    }
}

void dfs_hld(int u, int p) {
    in[u] = euler++;
    alter(in[u], val[u]);
    for (int v : tree[u]) {
        if (v == p) { continue; }
        if (v == tree[u][0]) { heavy[v] = heavy[u]; }
        else { heavy[v] = v; }
        dfs_hld(v, u);
    }
}

int path(int u, int v) {
    int res = 0;
    while (heavy[u] != heavy[v]) {
        if (depth[heavy[u]] < depth[heavy[v]]) { swap(u, v); }
        res = max(res, query(in[heavy[u]], in[u] + 1));
        u = parent[heavy[u]];
    }
    if (depth[u] > depth[v]) { swap(u, v); }
    res = max(res, query(in[u], in[v] + 1));
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> N >> Q;
    tree.rsz(N), depth.rsz(N), parent.rsz(N), size.rsz(N, 1), in.rsz(N), heavy.rsz(N);
    seg.rsz(2 * N), val.rsz(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs_size(0, 0);
    //heavy[u] stores the heavy child on top of it
    //we cannot go through many heavy childs
    //our path() code is going up through them
    //by storing heavy childs as the first child,
    //we can very easily make light paths just a range from heavy[u] to u
    dfs_hld(0, 0);
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int u, x; cin >> u >> x; u--;
            val[u] = x;
            alter(in[u], x);
        }   else {
            int u, v; cin >> u >> v; u--; v--;
            cout << path(u, v) << "\n";
        }
    }

}
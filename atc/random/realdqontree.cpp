#include <bits/stdc++.h>
#define rsz resize
using namespace std;
using ll = long long;

vector<vector<array<int, 2>>> tree;
vector<int> depth, parent, in, out, euler;
vector<ll> dist;

void dfs(int u, int p, ll d) {
    in[u] = euler.size();
    parent[u] = p;
    depth[u] = depth[p] + 1;
    dist[u] = d;
    euler.push_back(u);
    for (auto [v, nd] : tree[u]) {
        if (v == p) { continue; }
        dfs(v, u, d + nd);
    }
    out[u] = euler.size();
}

vector<array<ll, 2>> seg;
int SN;
//dist query
ll query(int p) {
    ll res = 0;
    for (p += SN; p > 0; p /= 2) {
        res += seg[p][1];
    }
    return res;
}
//dist upd
void alter(int l, int r, int val) {
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { seg[l++][1] += val; }
        if (r & 1) { seg[--r][1] += val; }
    }
}
int least(int u, int v) { return depth[u] < depth[v] ? u : v; }
int lca(int l, int r) {
    if (l == r) { return l; }
    l = in[l], r = in[r];
    if (l > r) { swap(l, r); }
    l++; r++;
    int res = seg[l + SN][0];
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res = least(res, seg[l++][0]); }
        if (r & 1) { res = least(res, seg[--r][0]); }
    }
    return parent[res];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<array<int, 3>> edges;
    tree.rsz(N), depth.rsz(N), parent.rsz(N), in.rsz(N), dist.rsz(N), out.rsz(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        tree[u].push_back({v, d});
        tree[v].push_back({u, d});
        edges.push_back({u, v, d});
    }

    dfs(0, 0, 0);

    SN = N; seg.resize(2 * N);
    for (int i = 0; i < N; i++) {
        seg[in[i] + SN] = {i, dist[i]};
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = {least(seg[2 * i][0], seg[2 * i + 1][0]), 0};
    }
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int e, d; cin >> e >> d; e--;
            auto [u, v, ed] = edges[e];
            if (in[u] > in[v]) { swap(u, v); }
            int diff = d - ed;
            alter(in[v], out[v], diff);
            edges[e][2] = d;
        }   else {
            int u, v; cin >> u >> v; u--; v--;
            int anc = lca(u, v);
            cout << query(in[u]) + query(in[v]) - 2 * query(in[anc]) << "\n";
        }
    }
}
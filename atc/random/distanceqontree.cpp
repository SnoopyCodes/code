#include <bits/stdc++.h>
#define rsz resize
using namespace std;
using ll = long long;

vector<vector<array<int, 2>>> tree;

vector<int> par, pard, jump, depth;
vector<ll> jdist;
vector<vector<int>> cov;

void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    for (auto [v, d] : tree[u]) {
        if (v == p) { continue; }
        pard[v] = d;
        par[v] = u;
        if (depth[u] + depth[jump[jump[u]]] == 2 * depth[jump[u]]) {
            jump[v] = jump[jump[u]];
            jdist[v] = jdist[jump[u]] + jdist[u] + d;
            int tmp = v;
            while (tmp != jump[jump[u]]) {
                tmp = par[tmp];
                cov[tmp].push_back(v);
            }
        }   else {
            cov[u].push_back(v);
            jump[v] = u;
            jdist[v] = d;
        }
        dfs(v, u);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("hack.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N; cin >> N;
    tree.rsz(N), par.rsz(N), jdist.rsz(N), jump.rsz(N), depth.rsz(N), pard.rsz(N), cov.rsz(N);
    vector<array<int, 3>> edges;
    for (int i = 0; i < N - 1; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        edges.push_back({u, v, d});
        tree[u].push_back({v, d});
        tree[v].push_back({u, d});
    }
    dfs(0, 0);
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int e, d; cin >> e >> d; e--;
            int diff = d - edges[e][2];
            edges[e][2] = d;
            int u = edges[e][0], v = edges[e][1];
            if (depth[u] > depth[v]) { swap(u, v); }  //v is child of u
            pard[v] += diff;
            jdist[v] += diff;
            for (int w : cov[v]) {
                if (jump[w] != v)
                jdist[w] += diff;
            }
        }   else {
            int u, v; cin >> u >> v; u--; v--;
            if (depth[u] < depth[v]) { swap(u, v); }
            ll dist = 0;
            while (depth[u] > depth[v]) {
                if (depth[jump[u]] >= depth[v]) {
                    dist += jdist[u];
                    u = jump[u];
                }   else {
                    dist += pard[u];
                    u = par[u];
                }
            }
            while (u != v) {
                if (jump[u] != jump[v]) {
                    dist += jdist[u] + jdist[v];
                    u = jump[u], v = jump[v];
                }   else {
                    dist += pard[u] + pard[v];
                    u = par[u], v = par[v];
                }
            }
            cout << dist << "\n";
        }
    }
}
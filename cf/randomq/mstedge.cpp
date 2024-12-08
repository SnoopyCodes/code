#include <bits/stdc++.h>
#define rsz resize
using namespace std;
using ll = long long;

vector<int> dsu;

int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (rand() % 2) {
        dsu[u] = v;
    }   else {
        dsu[v] = u;
    }
}

vector<vector<array<int, 2>>> mst;
vector<int> depth, par, jump, jmax, parm;

void dfs(int u) {
    for (auto [v, w] : mst[u]) {
        if (v == par[u]) { continue; }
        if (depth[u] + depth[jump[jump[u]]] == 2 * depth[jump[u]]) {
            jump[v] = jump[jump[u]];
            jmax[v] = max(w, max(jmax[u], jmax[jump[u]]));
        }   else {
            jump[v] = u;
            jmax[v] = w;
        }
        depth[v] = depth[u] + 1;
        par[v] = u;
        parm[v] = w;
        dfs(v);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<array<int, 4>> edges(M);
    depth.rsz(N), dsu.rsz(N), depth.rsz(N), mst.rsz(N), par.rsz(N), jump.rsz(N), jmax.rsz(N), parm.rsz(N);
    for (int i = 0; i < N; i++) {
        dsu[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        edges[i] = {w, u, v, i};
    }
    sort(edges.begin(), edges.end());
    ll weight = 0;
    for (int i = 0; i < M; i++) {
        auto [w, u, v, j] = edges[i];
        if (find(u) != find(v)) {
            merge(u, v);
            weight += w;
            mst[u].push_back({v, w});
            mst[v].push_back({u, w});
        }
    }
    dfs(0);
    vector<ll> ans(M);
    for (int i = 0; i < M; i++) {
        auto [w, u, v, j] = edges[i];
        //lca of u and v
        if (depth[u] < depth[v]) { swap(u, v); }
        int res = 0;
        while (depth[u] > depth[v]) {
            if (depth[jump[u]] >= depth[v]) { res = max(res, jmax[u]); u = jump[u]; }
            else { res = max(res, parm[u]); u = par[u]; }
        }
        while (u != v) {
            if (jump[u] != jump[v]) {
                res = max(res, max(jmax[u], jmax[v]));
                u = jump[u], v = jump[v];
            }   else {
                res = max(res, max(parm[u], parm[v]));
                u = par[u], v = par[v];
            }
        }
        ans[j] = weight - res + w;
    }
    for (int i = 0; i < M; i++) {
        cout << ans[i] << "\n";
    }
}
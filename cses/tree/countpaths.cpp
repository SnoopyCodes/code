#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;

vector<int> depth;
vector<vector<int>> jumps;
vector<int> sub;
vector<int> add;

void dfs(int u, int p, int d) {
    depth[u] = d;
    jumps[0][u] = p;
    for (int v : tree[u]) {
        dfs(v, u, d + 1);
    }
}

vector<int> ans;

void answer(int u, int p, int amt) {
    amt += add[u];
}


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    tree.resize(N), depth.resize(N);
    ans.resize(N);
    for (int i = 0; i < N; i++) {
        int u, v; cin >> u >> v; u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int maxj = __lg(N - 1) + 1;
    jumps.resize(maxj, vector<int>(N, -1));
    dfs(0, -1, 0);
    for (int i = 1; i < maxj; i++) {
        for (int j = 0; j < N; j++) {
            if (jumps[i][j] != -1) {
                jumps[i][j] = jumps[i-1][jumps[i-1][j]];
            }
        }
    }
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        int ou = u, ov = v;
        if (depth[u] < depth[v]) { swap(u, v); swap(ou, ov); }
        int equalize = depth[v] - depth[u];
        for (int i = 0; i < maxj; i++) {
            if (equalize & 1 << i) { u = jumps[i][u]; }
        }
        if (u != v) {
            for (int i = maxj - 1; i > -1; i--) {
                if (jumps[i][u] != jumps[i][v]) { u = jumps[i][u]; v = jumps[i][v]; }
            }
        }
        int lca;
        if (ou == ov) {
            //we should not have done allat
            lca = u;
            add[lca]++;
            sub[lca]++;
        }   else if (u == v) {
            lca = ov;
            add[lca]++;
            
        }
    }

}
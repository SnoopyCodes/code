#include <bits/stdc++.h>

using namespace std;

vector<int> depth, parent, jump;
vector<vector<int>> sub;

void dfs(int u) {
    for (int v : sub[u]) {
        if (depth[u] + depth[jump[jump[u]]] == 2 * depth[jump[u]]) {
            jump[v] = jump[jump[u]];
        }   else {
            jump[v] = u;
        }
        depth[v] = depth[u] + 1;
        parent[v] = u;
        dfs(v);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    depth.resize(N), parent.resize(N), jump.resize(N), sub.resize(N);
    for (int i = 1; i < N; i++) {
        int x; cin >> x; x--;
        parent[i] = x;
        sub[x].push_back(i);
    }
    dfs(0);
    for (int q = 0; q < Q; q++) {
        int u, v; cin >> u >> v; u--; v--;
        if (depth[u] < depth[v]) { swap(u, v); }
        while (depth[u] > depth[v]) {
            if (depth[jump[u]] >= depth[v]) { u = jump[u]; }
            else { u = parent[u]; }
        }
        while (u != v) {
            if (jump[u] == jump[v]) { u = parent[u], v = parent[v]; }
            else { u = jump[u], v = jump[v]; }
        }
        cout << u + 1 << "\n";
    }
}
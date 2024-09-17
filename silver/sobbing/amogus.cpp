#include <bits/stdc++.h>

using namespace std;
vector<int> dsu;
vector<int> sizes;
int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) { return; }
    if (sizes[v] > sizes[u]) { swap(u, v); }
    sizes[u] += sizes[v];
    dsu[v] = u;
}

vector<vector<int>> graph;
vector<int> visited;
array<int, 2> dfs(int u, bool col) {  //return total component size, the initial coloring
    visited[u] = col;
    array<int, 2> res {sizes[u], sizes[u] * col};
    for (int v : graph[u]) {
        if (visited[v] == col) { res[0] = -500001; break; }  //invalid coloring
        else if (visited[v] == !col) { continue; }
        array<int, 2> adj = dfs(v, !col);
        res[0] += adj[0]; res[1] += adj[1];
    }
    return res;
}

void solve() {
    int N, Q; cin >> N >> Q;
    vector<array<int, 3>> edges(Q);
    graph.clear(); graph.resize(N);
    dsu.clear(); dsu.resize(N);
    sizes.clear(); sizes.resize(N);
    visited.clear(); visited.resize(N, -1);
    for (int i = 0; i < N; i++) {
        dsu[i] = i;
        sizes[i] = 1;
    }
    int vouches = 0;
    for (int i = 0; i < Q; i++) {
        int t, a, b; cin >> t >> a >> b; a--; b--;
        edges[i] = {t, a, b};
        vouches += t - 1;
    }
    //we want to deal with the vouches first
    /* partitition */ {
        int ti = 0;
        for (int i = 0; i < Q; i++) {
            if (edges[i][0] == 2) {
                swap(edges[i], edges[ti]);
                ti++;
            }
        }
    }

    for (int i = 0; i < vouches; i++) {
        int u = edges[i][1], v = edges[i][2];
        merge(u, v);
    }

    for (int i = vouches; i < Q; i++) {
        int u = find(edges[i][1]), v = find(edges[i][2]);
        if (u == v) { cout << -1 << "\n"; return; }
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int r = find(i);
        if (visited[r] != -1) { continue; }
        array<int, 2> res = dfs(r, 0);
        if (res[0] < 0) { cout << -1 << "\n"; return; }
        ans += max(res[1], res[0] - res[1]);
    }
    cout << ans << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}
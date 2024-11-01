#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int N;
    vector<int> root, sizes;
    void init(int _N) {
        int N = _N;
        root.resize(N);
        sizes.resize(N, 1);
        for (int i = 0; i < N; i++) { root[i] = i; }
    }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool merge(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (sizes[ru] < sizes[rv]) { swap(ru, rv); }
        sizes[ru] += sizes[rv];
        root[rv] = ru;
        return true;
    }
};

vector<vector<int>> tree;
vector<int> dist;

void dfs(int u, int par, int d) {
    dist[u] = d;
    for (int v : tree[u]) {
        if (v == par) { continue; }
        dfs(v, u, d + 1);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //i think we should use dsu of some sort!
    //start from N components
    //then we should use tree diameter
    //yeah use the two endpoints of the tree diameter to figure out when components change
    //i posit that the values only matter at the endpoints

    int N; cin >> N;
    tree.resize(N);
    dist.resize(N);
    DSU cc; cc.init(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1, 0);
    int ep1 = 0;
    for (int i = 1; i < N; i++) {
        if (dist[i] > dist[ep1]) { ep1 = i; }
    }
    
    dfs(ep1, -1, 0);
    vector<int> ep1d = dist;

    int ep2 = 0;
    for (int i = 1; i < N; i++) {
        if (dist[i] > dist[ep2]) { ep2 = i; }
    }
    dfs(ep2, -1, 0);

    int cnt = N;
    vector<int> ans(N + 1, N);
    ans[N] = N;
    cnt -= cc.merge(ep1, ep2);
    priority_queue<array<int, 2>> pq;
    for (int i = 0; i < N; i++) {
        pq.push({ep1d[i], i});
        pq.push({dist[i], i});
    }
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        cnt -= cc.merge(ep1, u);
        ans[d] = min(ans[d], cnt);
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
}
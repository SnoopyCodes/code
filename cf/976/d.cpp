#include <bits/stdc++.h>

using namespace std;
struct DSU {
    int N;
    vector<int> root;
    vector<int> sizes;
    void init(int N) {
        root.resize(N);
        sizes.resize(N, 1);
        for (int i = 0; i < N; i++) { root[i] = i; }
    }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) { return false; }
        if (sizes[u] < sizes[v]) { swap(u, v); }
        sizes[u] += sizes[v];
        root[v] = u;
        return true;
    }
};
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<array<int, 2>>> ops(N);
    DSU uf;
    uf.init(N);
    for (int i = 0; i < M; i++) {
        array<int, 3> a;
        cin >> a[0] >> a[1] >> a[2]; a[0]--;
        ops[a[0]].push_back({a[1], a[2]});
    }
    vector<vector<int>> dp(N, vector<int>(11));
    for (int i = 0; i < N; i++) {
        for (array<int, 2> a : ops[i]) {
            dp[i][a[0]] = max(dp[i][a[0]], a[1]);
        }
        for (int j = 1; j < 11 && i + j < N; j++) {
            if (!dp[i][j]) { continue; }
            uf.merge(i, i + j);
            dp[i + j][j] = max(dp[i + j][j], dp[i][j] - 1);
        }
    }
    set<int> unique;
    for (int i = 0; i < N; i++) {
        unique.insert(uf.find(i));
    }
    cout << unique.size() << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}
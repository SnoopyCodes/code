#include <bits/stdc++.h>

using namespace std;

vector<vector<array<int, 2>>> adj;
vector<bool> visited;

//returns node there is a cycle found or not
int dfs(int u, int p) {
    visited[u] = true;
    for (auto [v, c] : adj[u]) {
        if (v == p) { continue; }
        if (visited[v]) { return u; }
        int res = dfs(v, u);
        if (res != -1) { return res; }
    }
    return -1;
}

vector<double> ans;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    adj.resize(N);
    visited.resize(N);
    ans.resize(N);
    //if graph has cycles, then it is set
    //how do we optimize on a tree?
    //tree dp
    for (int i = 0; i < M; i++) {
        int u, v, c; cin >> u >> v >> c; u--; v--; c++;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    bool valid = true;
    for (int i = 0; i < N; i++) {
        if (visited[i]) { continue; }
        int node = dfs(i, -1);
        
    }
    if (valid) {
        cout << "YES" << "\n";
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " \n"[i == N - 1];
        }
    }   else {
        cout << "NO" << "\n";
    }

}
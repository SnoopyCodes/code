#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<bool> reach, in_path;
vector<int> ans;
void dfs(int u) {
    visited[u] = true;
    in_path[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) { dfs(v); }
        else if (in_path[v]) { reach[u] = true; }
        reach[u] = reach[v] | reach[u];
    }
    if (!reach[u]) { ans.push_back(u); }
    in_path[u] = false;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    adj.resize(N), visited.resize(N), reach.resize(N), in_path.resize(N);
    for (int i = 0; i < N; i++) {
        int M; cin >> M;
        for (int j = 0; j < M; j++) {
            int u; cin >> u;
            adj[i].push_back(u);
        }
    }
    //anything that reaches cycles is bad
    //we can probably do this within one dfs
    for (int i = 0; i < N; i++) {
        if (!visited[i]) { dfs(i); }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}
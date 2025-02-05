#include <bits/stdc++.h>

using namespace std;
int ans = 0;
vector<vector<int>> adj;
vector<int> type;
bool valid = true;
void dfs(int u, int t) {
    type[u] = t;
    for (int v : adj[u]) {
        if (type[v] != -1 && type[v] == t) { valid = false; continue; }
        else if (type[v] != -1) { continue; }
        dfs(v, !t);
    }
}

void solve() {
    int N; cin >> N;
    adj.clear(); type.clear(); valid = true;
    adj.resize(N), type.resize(N, -1);
    vector<int> degree(N);
    for (int i = 0; i < N; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    if (*max_element(degree.begin(), degree.end()) > 2) { return; }
    //treat the thing as a graph
    //bipartite
    //hmm
    //each node can only have 2 edges
    for (int i = 0; i < N; i++) {
        if (type[i] == -1) { dfs(i, 0); }
    }
    ans += valid;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
    cout << ans << "\n";
}
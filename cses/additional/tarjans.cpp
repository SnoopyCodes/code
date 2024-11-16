#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<array<int, 2>> bridges;
vector<int> arts;
vector<int> back;
int euler = 0;

void dfs(int u, int p) {  //returns amount passing over this one
    back[u] = euler++;
    for (int v : graph[u]) {
        if (v == p) { continue; }
        if (back[v] == -1) { dfs(v, u); }
        
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //bridges and art
    int N, M; cin >> N >> M;
    graph.resize(N), back.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    dfs(0, -1);

    cout << bridges.size() << "\n";
    for (int i = 0; i < bridges.size(); i++) {
        cout << bridges[i][0] + 1 << " " << bridges[i][1] + 1 << "\n";
    }
}
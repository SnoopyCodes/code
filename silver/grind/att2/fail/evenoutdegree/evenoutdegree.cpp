#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
void dfs(int i) {
    if (visited[i]) { return; }
    visited[i] = true;
    //what can we do in a spanning tree?
    //
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //the graph is not a tree
    //look at each connected component
    //if there are an odd number of edges then it is impossible to form anything
    //greedily choosing 2 4 or even edges is suboptimal
    int N; cin >> N;
    graph.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //greedy?
    for (int i = 0; i < N; i++) {
        if (!visited[i]) { dfs(i); }
    }
}
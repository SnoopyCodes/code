#include <bits/stdc++.h>

using namespace std;
const int tot = 1e8;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
vector<int> labels;
void dfs(int i, int f) {
    //so the problem is 
    //wtf do we do
    //imagine if we binary searched on value of the first one
    //maybe actually?
    //what to do when loop?
    //
    if (visited[i]) { return; }
    visited[i] = true;
    if (graph[i].size() == 0) { labels[i] = 0; return; }

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    graph.resize(N);
    visited.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    //dfs throuhg
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
}
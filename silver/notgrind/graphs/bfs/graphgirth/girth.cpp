#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> visited;
vector<vector<int>> graph;
int shortest = INT_MAX;
void bfs(int i) {
    queue<int> q;
    q.push(i);
    parent[i] = i;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int j : graph[x]) {
            if (j == parent[x]) { continue; }
            if (visited[j]) {
                int dist = 1;
                int par = j;
                while (par != i) {
                    dist++;
                    par = parent[par];
                }
                par = x;
                while (par != i) {
                    dist++;
                    par = parent[par];
                }
                shortest = min(shortest, dist);
                continue;
            }
            visited[j] = true;
            parent[j] = x;
            q.push(j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //so with bfs we can find cycles?
    //with dfs can we also do this?
    int n, m; cin >> n >> m;
    parent.resize(n); visited.resize(n); graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    //lets say try bfs 
    //when we come across something we've already seen, save that 
    for (int i = 0; i < n; i++) {
        parent.clear(); parent.resize(n);
        visited.clear(); visited.resize(n);
        bfs(i);
    }
    if (shortest == INT_MAX) { cout << -1 << "\n"; return 0; }
    cout << shortest << "\n";
}
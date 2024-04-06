#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
pair<int, int> rid;
vector<bool> visited;
bool valid(int i, int from) {
    if (visited[i]) { return false; }
    visited[i] = true;
    for (int x : graph[i]) {
        if (x == from) { continue; }
        if ((rid.first == i && rid.second == x) || (rid.first == x && rid.second == i)) { continue; }
        if (!valid(x, i)) { return false; }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    graph.resize(N);
    vector<pair<int, int>> edges;
    edges.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges[i].first = a;
        edges[i].second = b;
    }
    //try taking away each edge
    for (int i = N - 1; i >= 0; i++) {
        cout << i << endl;
        rid.first = edges[i].first;
        rid.second = edges[i].second;
        visited.clear(); visited.resize(N);
        if (valid(0, -1)) {
            cout << i+1 << "\n";
            return 0;
        }
    }
}
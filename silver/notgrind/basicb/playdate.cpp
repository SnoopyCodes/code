#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, int>>> paths;
vector<bool> visited;
int dfs(int s, int e) {
    if (s == e) { return 0; }
    if (visited[s]) { return INT_MIN; }
    visited[s] = true;
    int dist = INT_MIN;
    for (pair<int, int> p : paths[s]) {
        int dist = dfs(p.first, e);
        if (dist != INT_MIN) { return dist + p.second; }
    }
    return dist;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    paths.resize(N);
    //brute force
    for (int i = 0; i < N-1; i++) {
        int a, b, l; cin >> a >> b >> l; a--; b--;
        paths[a].push_back({b, l});
        paths[b].push_back({a, l});
    }
    // for (int i = 0; i < N; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < paths[i].size(); j++) {
    //         cout << paths[i][j].first << " " << paths[i][j].second << ", ";
    //     }
    //     cout << "\n";
    // }
    for (int q = 0; q < Q; q++) {
        visited.clear(); visited.resize(N);
        int s, e; cin >> s >> e;
        s--; e--;
        cout << dfs(s, e) << "\n";
    }
}
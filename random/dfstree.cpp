#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> in_time;
vector<int> art_point;
vector<array<int, 2>> bridges;
int euler = 0;
int dfs(int v, int from) {  // return number of edges going over v
    visited[v] = true;
    in_time[v] = euler;
    euler++;
    int up = 0, down = 0, overs = 0, trav = 0;
    for (int adj : graph[v]) {
        if (adj == from) { continue; }
        if (visited[adj]) {
            if (in_time[adj] > v) { down++; }
            else { up++; }
            continue;
        }
        trav++;
        int res = dfs(adj, v);
        if (res == 0) { bridges.push_back({v, adj}); }
        overs += res;
    }
    int crossed = up + overs - down;
    bool is_art = trav > 1;
    is_art |= from != -1 && overs == down && trav > 0;
    if (is_art) {
        cout << overs << " " << down << "\n";
        art_point.push_back(v);
        // you are an art point if
        // case 1: children to parent
        // you did at least one traversal (not a leaf node) &
        // you have no crosses OVER THIS POINT, and are not the root
        // this is bc if you are the root you will have no crosses
        // but you dont connect any parent above you
        // case 2
        // you did more than 1 traversal
        // this means your children arent connected without you
        // so you are
    }
    return crossed;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    graph.resize(N);
    visited.resize(N);
    in_time.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1);
    cout << "\n";
    for (auto p : bridges) {
        cout << p[0] << " " << p[1] << " ";
    }
    cout << "\n";
    sort(art_point.begin(), art_point.end());
    for (int x : art_point) {
        cout << x+1 << " ";
    }
    cout << "\n";
}
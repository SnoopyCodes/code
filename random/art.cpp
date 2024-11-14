#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> in;
vector<int> art_point;
vector<int> hits;
int euler = 0;
int dfs(int v, int from) {  // return number of edges going over v
    in[v] = euler;
    euler++;
    int up = 0, down = 0, overs = 0;
    int own = false;
    for (int adj : graph[v]) {
        if (adj == from) { continue; }
        if (in[adj] != -1) {
            if (in[adj] > in[v]) { down++; }
            else { up++; hits[adj]++; }
            continue;
        }
        hits[v] = 0;
        int res = dfs(adj, v);
        own += hits[v] == res;
        overs += res;
    }
    int crossed = up + overs - down;
    bool is_art = own - (from == -1);
    if (is_art) { art_point.push_back(v); }
    return crossed;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    graph.resize(N);
    hits.resize(N);
    in.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1);

    cout << art_point.size() << "\n";
    for (int x : art_point) {
        cout << x+1 << " ";
    }
}
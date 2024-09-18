#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> cities;
vector<bool> visited;
vector<array<int, 3>> tours;
int dfs(int u, int from) {
    //ok there are some connections upwards yes
    //and there are some connections downwards
    //"for each edge (a, b) not in the spanning tree, disconnect one endpoint"
    visited[u] = true;
    vector<int> totour;
    for (int v : cities[u]) {
        if (v == from) { continue; }
        if (visited[v]) {
            //bruh this ensures that only one will ever get toured
            //idk how people think of this
            if (u < v) { totour.push_back(v); }
        }   else if (dfs(v, u)) {
            totour.push_back(v);
        }
    }
    for (int i = 0; i < (int)totour.size() - 1; i += 2) {
        tours.push_back({totour[i], u, totour[i + 1]});
    }
    if (totour.size() % 2 == 0) { return true; }
    if (from != -1) { tours.push_back({totour.back(), u, from}); }
    return false;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    cities.resize(N);
    visited.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        cities[u].push_back(v);
        cities[v].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) { dfs(i, -1); }
    }
    cout << tours.size() << endl;
    for (auto const&[u, v, w] : tours) {
        cout << u + 1 << " " << v + 1 << " "<< w + 1 << "\n";
    }
    //uhh so
    //the central city is y
    //basically we choose 2 edges of y and eliminate them
    //and we want to be able to do this as many times as possible
    //somehow
    //yikes
    //ok wait it would be suboptimal to remove from stuff with more than indegree 1
    //ok so the answer is edges over two for some reason
    //okay if we just use a tree
    //we can find back edges
    //dude im like retardant holy crap
    //consider if it is like a tree
    //tree is quite simple actually
}
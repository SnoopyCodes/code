#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> in_time;
vector<int> art_point;
vector<array<int, 2>> bridges;
int euler = 0;

int dfs(int v, int from) {  // return number of edges going over v
    in_time[v] = euler++;
    int up = 0, down = 0, overs = 0, trav = 0;
    bool has_bridge_child = false;  // Flag to track bridge children

    for (int adj : graph[v]) {
        if (adj == from) { continue; }
        if (in_time[adj] != -1) {
            if (in_time[adj] > in_time[v]) { down++; }
            else { up++; }
            continue;
        }
        trav++;
        int res = dfs(adj, v);
        if (res == 0) { 
            bridges.push_back({v, adj}); 
            has_bridge_child = true;  // Found a bridge child
        }
        overs += res;
    }

    int crossed = up + overs - down;
    bool is_art = false;

    // Corrected root condition
    if (from == -1 && trav > 1) { 
        is_art = true; 
    }
    // Corrected non-root condition
    if (from != -1 && has_bridge_child) { 
        is_art = true; 
    }

    if (is_art) {
        art_point.push_back(v);
    }

    return crossed;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    graph.resize(N);
    in_time.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1);
    // To handle multiple components, uncomment the following:
    /*
    for(int i=0;i<N;i++) {
        if(in_time[i]==-1) dfs(i, -1);
    }
    */
    cout << art_point.size() << "\n";
    for (int x : art_point) {
        cout << x+1 << " ";
    }
}

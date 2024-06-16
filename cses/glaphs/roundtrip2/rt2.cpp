#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> cities;
vector<int> visited;  //stores previous
vector<bool> on_stack;
//i may be actually brain damaged
//we need to check whether we have visited a node or not in this dfs
bool found = false;
void dfs(int v, int prev) {
    if (found) { return; }
    if (on_stack[v]) {
        vector<int> path;
        path.push_back(v);
        while (prev != v) {
            path.push_back(prev);
            prev = visited[prev];
        }
        path.push_back(v);
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int  i = 0; i < path.size(); i++) {
            cout << path[i] + 1;
            if (i < path.size() - 1) { cout << " "; }
        }
        found = true;
        return;
    }   else if (visited[v] != -1) { return; }  //no cycle will come from here
    visited[v] = prev;
    on_stack[v] = true;
    for (int next : cities[v]) {
        dfs(next, v);
    }
    on_stack[v] = false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    cities.resize(N);
    on_stack.resize(N);
    visited.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        cities[a].push_back(b);
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] == -1) { dfs(i, -2); }
        if (found) { break; }
    }
    if (!found) { cout << "IMPOSSIBLE" << "\n"; }
    //dfs and find the first city we revisit
    
}
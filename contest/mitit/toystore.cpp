#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    int N; cin >> N;
    vector<int> next(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        next[i] = x;
    }
    //if there is no cycle (end == end) the problem is pretty trivial
    //if there is a cycle, find the cycle and then force
    //make radj lists
    //first iterate through all non cycles
    //and solve those individually
    //wait force the cycles to become non cycles
    vector<bool> visited(N);
    vector<array<int, 3>> ans;
    vector<bool> in_path(N);
    for (int i = 0; i < N; i++) {
        if (visited[i]) { continue; }
        int u = i;
        stack<int> path;
        while (!visited[u]) {
            visited[u] = true;
            path.push(u);
            in_path[u] = true;
            u = next[u];
        }
        bool out = false;
        if (u == next[u] || !in_path[u]) { out = true; }
        while (!path.empty()) {
            int v = path.top();
            in_path[v] = false;
            path.pop();
        }
        if (out) { continue; }
        //there is a cycle here, force cycle to be normal using type 2 oips
        int v = next[u];
        while (next[v] != u) {
            ans.push_back({1, v + 1, next[v] + 1});
            int w = next[v];
            next[v] = next[w];
            next[w] = w;
        }
        swap(next[v], next[u]);
        ans.push_back({1, v + 1 , u + 1});
    }
    //essentially toposort now
    vector<int> in(N);
    vector<vector<int>> radj(N);
    for (int i = 0; i < N; i++) {
        if (next[i] != i) { in[i]++; radj[next[i]].push_back(i); }
    }
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (!in[i]) { q.push(i); }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : radj[u]) {
            ans.push_back({2, u + 1 , v + 1});
            in[v]--;
            if (!in[v]) { q.push(v); }
        }
    }
    cout << ans.size() << "\n";
    for (auto [t, u, v] : ans) {
        cout << t << " " << u << " " << v << "\n";
    }
}
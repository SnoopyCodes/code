#include <bits/stdc++.h>

using namespace std;

vector<bool> visited, in_path;
vector<array<int, 3>> ans;
vector<int> trav;

int dfs(int u) {
    visited[u] = true;
    in_path[u] = true;

    if (visited[trav[u]]) {
        in_path[u] = false;
        if (!in_path[trav[u]] || trav[u] == trav[trav[u]]) { return -1; }
        ans.push_back({1, trav[u] + 1, u + 1});
        swap(trav[trav[u]], trav[u]);
        return u;
    }
    int v = dfs(trav[u]);
    in_path[u] = false;
    if (v == -1 || u == v) { return -1; }
    swap(trav[u], trav[v]);
    ans.push_back({1, u + 1, v + 1});
    return v;
}

int main() {
    int N; cin >> N;
    trav.resize(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        trav[i] = x;
    }
    visited.resize(N);
    in_path.resize(N);
    for (int i = 0; i < N; i++) {
        if (!visited[i] && i != trav[i]) { dfs(i); ans.pop_back(); }
    }
    //essentially toposort now
    vector<int> in(N);
    vector<vector<int>> radj(N);
    for (int i = 0; i < N; i++) {
        if (trav[i] != i) { in[i]++; radj[trav[i]].push_back(i); }
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
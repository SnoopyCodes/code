#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, S, F; cin >> N >> S >> F; S--; F--;
    vector<vector<int>> first(N), second(N);
    int M; cin >> M;
    set<array<int, 2>> e;
    set<array<int, 2>> same;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (u > v) { swap(u, v); }
        e.insert({u, v});
        first[u].push_back(v);
        first[v].push_back(u);
    }
    cin >> M;
    for (int i =0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (u > v) { swap(u, v); }
        if (e.count({u, v})) { same.insert({u, v}); }
        second[u].push_back(v);
        second[v].push_back(u);
    }
    //uhh
    //if there are same edges then try it
    //then if the distances are the same
    int ans = -1;
    for (auto [U, V] : same) {
        vector<int> dist1(N, 1e5), dist2(N, 1e5);
        //well, anyways
        //find shortest paths
        //i think we surely have to retraverse
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
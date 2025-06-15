#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
//sadly cannot self solve
void solve() {
    int N, M; cin >> N >> M;

    vector<std::set<int>> G(N);
    vector<array<int, 3>> ops;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (u && v) {
            if (G[0].count(u)) {
                G[0].erase(u);
                G[u].erase(0);
            }   else {
                G[0].insert(u);
                G[u].insert(0);
            }
            if (G[0].count(v)) {
                G[0].erase(v);
                G[v].erase(0);
            }   else {
                G[0].insert(v);
                G[v].insert(0);
            }
            ops.push_back({ 0, v, u });
        }   else {
            if (u > v) { swap(u, v); }
            if (G[u].count(v)) {
                G[u].erase(v);
                G[v].erase(u);
            }   else {
                G[u].insert(v);
                G[v].insert(u);
            }
        }
    }
    if (!G[0].empty()) {
        vector<bool> done(N);
        for (int u : G[0]) {
            done[u] = true;
        }
        for (int i = 1; i < N; i++) {
            if (done[i]) { continue; }
            ops.push_back({ 0, i, *G[0].begin() });
            G[0].erase(G[0].begin());
            G[0].insert(i);
        }
    }
    cout << ops.size() << "\n";
    for (auto [u, v, w] : ops) {
        cout << u + 1 << " " << v + 1 << " " << w + 1 << "\n";
    }
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }   
}
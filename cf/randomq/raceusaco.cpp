#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> islands(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        islands[u].push_back(v);
    }
    vector<int> dists(N, N - 1);
    for (int i = 0; i < N - 1; i++) {
        dists[i] = min(dists[i], i);
        for (int v : islands[i]) {
            dists[v] = min(dists[i] + 1, dists[v]);
        }
        dists[i + 1] = min(dists[i] + 1, dists[i + 1]);
    }
    int reachable = 0;
    for (int i = 0; i < N - 1; i++) {
        cout << (reachable <= i);
        for (int v : islands[i]) {
            reachable = max(reachable, v - (dists[i] + 1));
        }
    }
    cout << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int cnt = 0;
    int T; cin >> T; 
    
    while (T) { T--; solve(); cnt++;}
}
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tunnels;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    int N, K; cin >> N >> K; K--;
    tunnels.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        tunnels[u].push_back(v);
        tunnels[v].push_back(u);
    }
    //find dist from bessie to all exits
    //find for all nodes how many exits are equidistant to it?
    //for some exit, if there is another exit closer to 
    //b than itself, then it is covered
    vector<bool> visited(N);
    vector<bool> bv(N);
    queue<int> q;
    queue<int> bq; bq.push(K);
    bv[K] = true;
    visited[K] = true;
    for (int i = 0; i < N; i++) {
        if (tunnels[i].size() == 1) { visited[i] = true; q.push(i); }
    }
    int ans = 0;
    for (int t = 0; !bq.empty(); t++) {
        int amt = q.size();
        for (int u = q.front(), i = 0; i < amt; i++, q.pop(), u = q.front()) {
            for (int v : tunnels[u]) {
                if (!visited[v]) { q.push(v); visited[v] = true; }
            }
        }
        amt = bq.size();
        for (int u = bq.front(), i = 0; i < amt; i++, bq.pop(), u = bq.front()) {
            for (int v : tunnels[u]) {
                if (visited[v]) {
                    if (bv[v]) { continue; }
                    ans++;
                }   else {
                    bq.push(v); visited[v] = true; bv[v] = true;
                }
            }
        }
    }
    cout << ans << "\n";
}
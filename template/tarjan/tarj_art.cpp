#include <bits/stdc++.h>

using namespace std;
#define rsz resize

vector<vector<int>> G;
vector<int> in, art;
int euler = 0;
int dfs(int u, int p) {
    int low = in[u] = euler++, trav = 0;
    bool is = false;
    for (int v : G[u]) {
        if (v == p) { continue; }
        if (in[v] == -1) {
            int res = dfs(v, u);
            low = min(low, res);
            if (res >= in[u] && p != -1) { is = true; }
            trav++;
        }   else { low = min(low, in[v]); }
    }
    if (trav > 1 && p == -1 || is) { art.push_back(u); }
    return low;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    G.rsz(N), in.rsz(N, -1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        if (in[i] == -1) { dfs(i, -1); }
    }
    cout << art.size() << "\n";
    for (int i = 0; i < art.size(); i++) {
        cout << art[i] + 1 << " \n"[i == art.size() - 1];
    }
}
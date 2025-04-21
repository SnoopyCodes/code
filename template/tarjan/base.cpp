#include <bits/stdc++.h>

using namespace std;

#define rsz resize
#define emb emplace_back
#define pob pop_back

vector<vector<int>> G;
vector<int> in, path, in_cc;
int euler = 0, ncc = 0;
int dfs(int u) {
    int low = in[u] = euler++;
    path.emb(u);
    for (int v : G[u]) {
        if (in[v] == -1) { low = min(low, dfs(v)); }
        if (in_cc[v] == -1) { low = min(low, in[v]); }
    }
    if (in[u] != low) { return low; }
    while (in_cc[u] == -1) {
        int v = path.back(); path.pob();
        in_cc[v] = ncc;
    }
    ncc++;
    return low;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    G.rsz(N), in.rsz(N, -1), in_cc.rsz(N, -1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
    }
    cout << "\n";
    for (int i = 0; i < N; i++) {
        if (in[i] == -1) { dfs(i); }
    }
    cout << ncc << "\n";
    for (int i = 0; i < N; i++) {
        cout << in_cc[i] + 1 << " \n"[i == N - 1];
    }
}
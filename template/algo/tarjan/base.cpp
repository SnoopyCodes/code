#include <bits/stdc++.h>

using namespace std;

#define add push_back

vector<vector<int>> G;
vector<int> in, in_cc;
vector<int> path;
int euler = 0, ncc = 0;
int dfs(int u) {
    int low = in[u] = euler++;
    path.add(u);
    for (int v : G[u]) {
        if (~in_cc[v]) { continue; }
        low = min(low, ~in[v] ? in[v] : dfs(v));
    }
    if (in[u] == low) {
        while (in_cc[u] == -1) {
            in_cc[path.back()] = ncc; path.pop_back();
        }
        ncc++;
    }
    return low;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    G.resize(N), in.resize(N, -1), in_cc.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].add(v);
    }
    for (int i = 0; i < N; i++) {
        if (in[i] == -1) { dfs(i); }
    }
    cout << ncc << "\n";
    for (int i = 0; i < N; i++) {
        cout << in_cc[i] + 1 << " \n"[i == N - 1];
    }
}
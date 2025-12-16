#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for (auto i = (s); i < (e); i++)
#define rev(i, s, e) for (auto i = (s)-1; i >= (e); i--)
#define rsz resize
#define add push_back

vector<int> in, path, in_cc;
vector<vector<int>> G, bcc;
int ncc = 0, euler = 0;

int dfs(int u, int p) {
    int low = in[u] = euler++, mult = 0;
    path.add(u);
    for (int v : G[u]) {
        if (v == p && !mult) { mult++; continue; }
        if (~in_cc[v]) { continue; }
        low = min(low, ~in[v] ? in[v] : dfs(v, u));
    }
    if (in[u] == low) {
        bcc.add({});
        while (in_cc[u] == -1) {
            bcc[ncc].add(path.back());
            in_cc[path.back()] = ncc; path.pop_back();
        }
        ncc++;
    }   else { in[u] = low; }
    return low;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    G.rsz(N), in.rsz(N, -1), in_cc.rsz(N, -1);
    rep(i, 0, M) {
        int u, v; cin >> u >> v;
        G[u].add(v);
        G[v].add(u);
    }
    rep(i, 0, N) {
        if (in[i] == -1) { dfs(i, -1); }
    }
    cout << ncc << "\n";
    rep(i, 0, ncc) {
        cout << bcc[i].size() << " ";
        for (int u : bcc[i]) {
            cout << u << " ";
        }
        cout << "\n";
    }
}
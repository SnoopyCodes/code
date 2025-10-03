#include <bits/stdc++.h>

using namespace std;
#define long long long
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

vv<int> G;
vt<int> W, C;
long ans;

set<int> dfs(int u, int p) { //all the different colors.
    set<int> total;
    int done = 0;
    int col = -1;
    for (int v : G[u]) {
        if (v == p) { continue; }
        auto res = dfs(v, u);
        if (res.size() > total.size()) { swap(res, total); }
        for (int c : res) {
            if (total.find(c) != total.end() && c != col) {
                done++;
                col = c;
            }   else {
                total.insert(c);
            }
        }
        total.erase(C[u]);
    }
    bool fixed = C[u];
    if (C[u]) {
        total.insert(C[u]);
    }   else if (done) {
        C[u] = col;
    }
    ans += (done > 1 && !fixed || done && fixed) * W[u];
    return total;
}

void dfs_all(int u, int p) {
    if (p == u && !C[u]) {
        C[u] = 1;
    }   else if (!C[u]) {
        C[u] = C[p];
    }
    for (int v : G[u]) {
        if (v == p) { continue; }
        dfs_all(v, u);
    }
}

void solve() {
    int N, K; cin >> N >> K;
    ans = 0;
    G.resize(N), W.resize(N), C.resize(N);
    for (int &u : W) {
        cin >> u;
    }
    for (int &u : C) {
        cin >> u;
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, 0);
    dfs_all(0, 0);
    cout << ans << endl;
    for (int i = 0; i < N; i++) {
        cout << C[i] << " \n"[i == N - 1];
    }

    G.clear(), W.clear(), C.clear();
}

int main() {
    cin.tie(0) ->sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
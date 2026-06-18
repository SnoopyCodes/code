#include <bits/stdc++.h>


using namespace std;
template<class T> using vt = vector<T>;

const int N = 1e6;
double f[N];
int w[N], s[N];
vt<int> T[N];
bool alive[N];

namespace slow {

vt<int> S[N];

void dfs(int u) {
    if (alive[u]) w[u] = 1;
    for (int v : T[u]) {
        dfs(v);
        w[u] += w[v];
        s[u] += s[v];
        for (int x : S[v]) if (w[v]) {
            S[u].push_back(x);
        }
    }
    if (w[u] && !T[u].empty()) {
        for (int v : S[u]) if (w[v]) {
            f[u] += 1 + f[v];
        }
        f[u] /= w[u];
        f[u] += s[u] / w[u] - 1;
        w[u]++;
    }
    if (w[u]) {
        S[u].push_back(u);
    }
    s[u]++;
}


} //namespace slow


namespace fast {
double g[N];
void dfs(int u) {
    for (int v : T[u]) {
        dfs(v);
        alive[u] |= alive[v];
        w[u] += w[v] + alive[v];
        s[u] += s[v] + 1;
    }
    if (alive[u]) {
        for (int v : T[u]) if (alive[v]) {
            g[u] += (1 + g[v] * w[u] / (w[u] + 1) + f[v] / (w[u] + 1))
                * (w[v] + 1) / w[u];
        }
        if (!T[u].empty()) {
            f[u] = g[u] + (double) s[u] / w[u] - 1;
        }
        
    }
}


}


void solve() {
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        alive[i] = f[i] = w[i] = s[i] = fast::g[i] = 0;
        T[i].clear();
        slow::S[i].clear();
    }
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v ; u--; v--;
        if (u == N || v == N) {
            f[u] = 1;
            alive[u] = true;
        }   else {
            T[u].push_back(v);
        }
    }
    fast::dfs(0);
    // slow::dfs(0);
    printf("%.3f\n", f[0]);
}




signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}

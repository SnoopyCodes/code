#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}

vector<int> dsu;

int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) { return false; }
    if (rand()) { dsu[u] = v; }
    else { dsu[v] = u; }
    return true;
}

vector<vector<array<int, 2>>> con;
vector<array<int, 2>> path;

void dfs(int u, int p, int cmax, int cmin) {
    path[u] = { cmax, cmin };
    for (auto [v, w] : con[u]) {
        assert(w != 0);
        if (v == p) { continue; }
        dfs(v, u, max(w, cmax), min(w, cmin));
    }
}

void solve() {
    int N, M; cin >> N >> M;
    dsu.resize(N);
    vector<array<int, 3>> edges(M);
    std::iota(dsu.begin(), dsu.end(), 0);
    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--; edges[i][1]--;
    }
    std::sort(edges.begin(), edges.end(), [](auto a, auto b) { return a[2] < b[2]; });
    con.clear();
    con.resize(N);
    for (auto [u, v, w] : edges) {
        if (merge(u, v)) {
            con[u].emplace_back(ta(v, w));
            con[v].emplace_back(ta(u, w));
        }
    }
    path.resize(N);
    dfs(0, -1, 0, 1e9);
    int cmax = path[N - 1][0], cmin = path[N - 1][1];
    int best = cmax + cmin;
    for (int i = 0; i < N; i++) {
        best = min(best, max(cmax, path[i][0]) + min(cmin, path[i][1]));
    }
    cout << best << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
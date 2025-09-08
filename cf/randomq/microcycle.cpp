#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

#define union zzzz
struct DSU {
    int N;
    vector<int> root, size;
    DSU(int _N):N(_N), root(N), size(N, 1)
    { iota(root.begin(), root.end(), 0); }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool union(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (size[ru] < size[rv]) { swap(ru, rv); }
        size[ru] += size[rv];
        root[rv] = ru;
        return true;
    }
};
mt<int> G;
vt<int> cyc;
vt<bool> visited;
bool dfs(int u, int p, int targ) {
    visited[u] = true;
    for (int v : G[u]) {
        if (v == p) { continue; }
        if (visited[v] && v != targ) { continue; }
        else if (v == targ) {
            cyc.add(v);
            cyc.add(u);
            return true;
        }
        if (dfs(v, u, targ)) { cyc.add(u); return true; }
    }
    return false;
}

void solve() {
    int N, M; cin >> N >> M;
    vt<ii<3>> E(M);
    G = mt<int>(N);
    cyc = vt<int>();
    visited = vt<bool>(N);
    for (auto &[u, v, w] : E) {
        cin >> u >> v >> w; u--; v--;
        G[u].add(v);
        G[v].add(u);
    }
    ranges::sort(E, [](auto a, auto b) { return a[2] > b[2]; });
    int last = 0;
    DSU cc(N);
    for (int i = 0; i < M; i++) {
        auto [u, v, w] = E[i];
        if (!cc.union(u, v)) {
            last = i;
        }
    }
    int u = E[last][0], v = E[last][1];
    visited[u] = true;
    dfs(v, u, u);
    cout << E[last][2] << " " << cyc.size() << "\n";
    for (int i = 0; i < cyc.size(); i++) {
        cout << cyc[i] + 1 << " \n"[i == cyc.size() - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
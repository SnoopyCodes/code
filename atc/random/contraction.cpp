#include <bits/stdc++.h>

using std::vector, std::min, std::max;

template<size_t z> using ints = std::array<int, z>;

vector<std::set<int>> con;
vector<int> root;
vector<int> size;

#define union heyyy

int find(int u) {
    if (root[u] != u) { root[u] = find(root[u]); }
    return root[u];
}

int union(int u, int v) {
    u = find(u), v = find(v);
    if (!con[u].count(v)) { return false; }
    if (size[u] < size[v]) { std::swap(u, v); }
    int ct = 1;
    con[u].erase(v);
    for (int w : con[v]) {
        if (u == w) { continue; }
        con[w].erase(v);
        if (!con[w].count(u)) {
            con[w].insert(u);
            con[u].insert(w);
        }   else { ct++; }
    }
    size[u] += size[v];
    root[v] = u;
    return ct;
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int N, M; std::cin >> N >> M;
    root.resize(N), con.resize(N); size.resize(N, 1);
    std::iota(root.begin(), root.end(), 0);
    vector<ints<2>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v; std::cin >> u >> v; u--; v--;
        edges[i] = { u, v };
        con[u].insert(v);
        con[v].insert(u);
    }
    int Q; std::cin >> Q;
    for (int q = 0; q < Q; q++) {
        int e; std::cin >> e; e--;
        auto [u, v] = edges[e];
        M -= union(u, v);
        std::cout << M << "\n";
    }
    /*
    use dsu.
    std::set
    contract the one with a smaller set size
    */
}
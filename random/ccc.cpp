#include <bits/stdc++.h>

using std::min, std::max;

template<size_t z> using ints = std::array<int, z>;
template<class T> using list = std::vector<T>;

list<list<ints<2>>> T;

list<int> dist, in, out, par;
int euler = 0;
bool is_anc(int u, int v) { return in[u] <= in[v] && out[v] <= out[u]; }
void dfs_far(int u, int p, int d, bool e) {
    if (e) { in[u] = euler++; par[u] = p; }
    dist[u] = d;
    for (auto [v, w] : T[u]) {
        if (v == p) { continue; }
        dfs_far(v, u, d + w, e);
    }
    if (e) { out[u] = euler; }
}

std::array<list<ints<2>>, 2> from;
void dfs_dp(int u, int p, bool z) {
    int p1 = 0, p2 = 0, maxd = 0;
    for (auto [v, w] : T[u]) {
        if (v == p) { continue; }
        dfs_dp(v, u, z);
        maxd = max(from[z][v][1], maxd);
        if (from[z][v][0] + w > p1) {
            p2 = max(p1, p2);
            p1 = from[z][v][0] + w;
        }
        else if (from[z][v][0] + w > p2) { p2 = from[z][v][0] + w; }
    }
    maxd = max(maxd, p1 + p2);
    from[z][u] = { p1, maxd };
}

void solve() {
    int N, Q; std::cin >> N >> Q;
    T.clear(); T.resize(N);
    dist.resize(N); from[0].resize(N); from[1].resize(N);
    in.resize(N), out.resize(N), par.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, d; std::cin >> u >> v >> d; u--; v--;
        T[u].push_back({ v, d });
        T[v].push_back({ u, d });
    }
    
    dfs_far(0, -1, 0, true);
    int du = std::max_element(dist.begin(), dist.end()) - dist.begin();
    dfs_far(du, -1, 0, false);
    int dv = std::max_element(dist.begin(), dist.end()) - dist.begin();

    dfs_dp(du, -1, 0), dfs_dp(dv, -1, 1);
    for (int q = 0; q < Q; q++) {
        int u; std::cin >> u; u--;
        if (!is_anc(u, du) && !is_anc(u, dv)) { //don't contain either ep
            std::cout << dist[dv] << "\n";
        }   else {
            if (is_anc(u, du)) {
                std::cout << from[0][par[u]][1] << "\n";
            }   else {
                std::cout << from[1][par[u]][1] << "\n";
            }
        }
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    solve();
}
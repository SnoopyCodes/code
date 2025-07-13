#include <bits/stdc++.h>

using std::min, std::max;

template<size_t z> using ints = std::array<int, z>;
template<class T> using list = std::vector<T>;

ints<2> dfs_dp(int u, int p, list<list<int>> &T) {
    int p1 = 0, p2 = 0;
    int maxd = 0;
    for (int v : T[u]) {
        if (v == p) { continue; }
        ints<2> res = dfs_dp(v, u, T);
        maxd = max(res[1], maxd);
        if (res[0] + 1 > p1) { p1 = res[0] + 1; }
        else if (res[0] + 1 > p2) { p2 = res[0] + 1; }
    }
    maxd = max(maxd, p1 + p2);
    return { p1, maxd };
}

void solve() {
    int N; std::cin >> N;
    list<list<int>> T(N);
    list<ints<2>> E(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; std::cin >> u >> v; u--; v--;
        T[u].push_back(v);
        T[v].push_back(u);
        E[i] = { u, v };
    }
    int ans = 0;
    for (auto [u, v] : E) {
        ans = max(ans, dfs_dp(u, v, T)[0] + dfs_dp(v, u, T)[0]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
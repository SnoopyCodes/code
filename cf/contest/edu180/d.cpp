#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;
vector<vector<int>> T;
void dfs(int u, int p, int dir) { //0 is chosen, 1 is to, -1 is away, 2 is special
    if (dir < 0) { std::cout << u + 1 << " " << p + 1 << "\n"; }
    else { std::cout << p + 1 << " " << u + 1 << "\n"; }
    for (int v : T[u]) {
        if (v == p) { continue; }
        dfs(v, u, -dir);
    }
}

void solve() {
    int N; std::cin >> N;
    //there are at least N - 1
    //connections
    //therefore, we need to make sure only one has length 2
    //it probably has to be a leaf
    //idt it has to be a leaf
    //we just need a path length of 2
    T.clear();
    T.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; std::cin >> u >> v; u--; v--;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        if (T[i].size() == 2) {
            std::cout << "YES" << "\n";
            dfs(T[i][0], i, -1);
            dfs(T[i][1], i, 1);
            return;
        }
    }
    std::cout << "NO" << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
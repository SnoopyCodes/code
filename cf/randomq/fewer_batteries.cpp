#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
template<class T> void rsz(vector<T> &v, int z) { v.clear(); v.resize(z); }
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

vector<vector<ints<2>>> con;
vector<int> batteries;

void solve() {
    int N, M; std::cin >> N >> M;
    rsz(con, N), rsz(batteries, N);
    for (int i = 0; i < N; i++) {
        std::cin >> batteries[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v, w; std::cin >> u >> v >> w; u--; v--;
        con[u].push_back({ v, w });
    }
    //binary search
    //oh its fricking acyclic this is trivial
    int s = 0, e = BIG;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        vector<int> best(N, -1);
        best[0] = 0;
        for (int u = 0; u < N; u++) {
            if (best[u] == -1) { continue; }
            int cur = min(best[u] + batteries[u], m);
            for (auto [v, w] : con[u]) {
                if (cur < w) { continue; }
                best[v] = max(best[v], cur);
            }
        }
        if (best[N - 1] != -1) {
            e = m;
        }   else {
            s = m;
        }
    }
    std::cout << (e == BIG ? -1 : e) << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
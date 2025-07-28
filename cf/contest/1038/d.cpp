#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

void solve() {
    int N, M; std::cin >> N >> M;
    vector<vector<ints<2>>> con(N);
    for (int i = 0; i < M; i++) {
        int u, v, w; std::cin >> u >> v; u--; v--;
        w = 1 + con[u].size();
        con[u].push_back({v, w});
        w = 1 + con[v].size();
        con[v].push_back({u, w});
    }
    vector<vector<int>> dist(N, vector<int>(N, BIG));
    std::priority_queue<ints<3>> pq; //-dist, u, # edges crossed
    dist[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        auto [d, u, e] = pq.top(); pq.pop(); d = -d;
        if (dist[u][e] != d) { continue; }
        std::cout << d << " " << u << " " << e << "\n";
        for (auto [v, w] : con[u]) {
            if (dist[v][e + 1] > d + w) {
                dist[v][e + 1] = d + w;
                pq.push({ -dist[v][e + 1], v, e + 1});
            }
        }
    }
    int mint = BIG, minw = BIG;
    for (int i = 0; i < N; i++) {
        if (dist[N-1][i] < mint) { mint = dist[N-1][i], minw = dist[N-1][i] - i; }
        else if (dist[N-1][i] == mint) { minw = min(dist[N-1][i] - i, minw); }
    }
    std::cout << mint << " " << minw << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
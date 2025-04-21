#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int MOD = 1e9 + 7;
const i64 INF = 4e18 + 7e9;

#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<array<int, 2>>> flights(N);
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        flights[u].emb(ta(v, d));
    }
    vector<i64> dist(N, INF);
    dist[0] = 0;
    auto cmp = [&](int a, int b) { return dist[a] == dist[b] ? a < b : dist[a] < dist[b]; };
    set<int, decltype(cmp)> closest(cmp);
    closest.emp(0);
    while (!closest.empty()) {
        int u = *closest.begin(); closest.erase(u);
        for (auto const&[v, d] : flights[u]) {
            if (dist[u] + d < dist[v]) {
                closest.erase(v);
                dist[v] = dist[u] + d;
                closest.insert(v);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << dist[i] << " \n"[i == N - 1];
    }
}
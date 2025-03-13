#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;
const i64 INF = 4e18 + 7e9;

arr<int, 4> dr{-1, 1, 0, 0}, dc{0, 0, -1, 1};

template <typename T>
T multivec(T def) { return def; }

template <typename T, typename... Dims>
auto multivec(size_t first_dim, Dims... rest_dims) {
    return vec<decltype(multivec<T>(rest_dims...))>(
        first_dim, multivec<T>(rest_dims...));
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    //boring bfs
    vec<vec<char>> grid(N, vec<char>(M));
    queue<arr<int, 3>> q;
    arr<int, 2> e;
    auto dist = multivec<int>(2, N, M, int(1e9));
    rep(i, N) {
        rep(j, M) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                q.push({i, j, 0});
                q.push({i, j, 1});
                dist[0][i][j] = 0;
                dist[1][i][j] = 0;
            }   else if (grid[i][j] == 'G') {
                e = {i, j};
            }
        }
    }
    auto ob = [&](int x, int y) {
        return x < 0 || x == N || y < 0 || y == M || grid[x][y] == '#';
    };
    while (!q.empty()) {
        auto [r, c, z] = q.front(); q.pop();
        rep(d, z * 2, z * 2 + 2) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (ob(nr, nc)) { continue; }
            if (dist[!z][nr][nc] == 1e9) {
                q.push({nr, nc, !z});
                dist[!z][nr][nc] = dist[z][r][c] + 1;
            }
        }
    }
    if (dist[0][e[0]][e[1]] == 1e9 && dist[1][e[0]][e[1]] == 1e9) {
        cout << -1 << "\n";
    }   else {
        cout << min(dist[0][e[0]][e[1]], dist[1][e[0]][e[1]]) << "\n";
    }
}
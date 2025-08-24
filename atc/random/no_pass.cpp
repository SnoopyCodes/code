#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

constexpr ints<4> dr { -1, 0, 1, 0 }, dc { 0, 1, 0, -1 };

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int H, W, K; cin >> H >> W >> K;
    /*
    2nd best ok
    */
    queue<ints<2>> q;
    vv<ints<2>> dist(H, vt<ints<2>>(W, { -1, -1 }));
    vv<bool> visited(H, vt<bool>(W));
    while (K--) {
        int i, j; cin >> i >> j; i--; j--;
        q.push({ i, j });
        dist[i][j] = {};
    }
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nc < 0 || nr == H || nc == W) { continue; }
            if (dist[nr][nc][0] == -1) {
                dist[nr][nc][0] = dist[r][c][1] + 1;
            }   else if (dist[nr][nc][1] == -1) {
                dist[nr][nc][1] = dist[r][c][1] + 1;
                q.push({ nr, nc });
            }
        }
    }
    long ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (dist[i][j][1] != -1) {
                ans += dist[i][j][1];
            }
        }
    }
    cout << ans << "\n";
}
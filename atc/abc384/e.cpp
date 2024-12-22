#include <bits/stdc++.h>
#define long int64_t
#define pain __int128_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //this is scuffed
    //for each grid, maintain the minimum needed ot up and whether it is adjacent or not
    //then sort min to up and figure out which ones are possible!
    //actually just maintain the available ones

    //how check integer overflow?
    int H, W, X; cin >> H >> W >> X;
    int P, Q; cin >> P >> Q; P--; Q--;
    vector<vector<long>> grid(H, vector<long>(W));  //store the required amt
    vector<vector<bool>> visited(H, vector<bool>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            long x; cin >> x;
            grid[i][j] = x;
            if ((pain) LONG_LONG_MAX < X * (pain) grid[i][j]) { visited[i][j] = true; }
        }
    }
    priority_queue<array<long, 3>> pq;
    long cur = grid[P][Q];
    pq.push({0, P, Q});
    visited[P][Q] = true;
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    while (!pq.empty()) {
        if (cur <= -pq.top()[0] * X) { break; }
        auto [x, r, c] = pq.top(); pq.pop();
        cur += -x;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr == H || nc == W || visited[nr][nc]) { continue; }
            visited[nr][nc] = true;
            pq.push({-grid[nr][nc], nr, nc});
        }
    }
    cout << cur << "\n";
}
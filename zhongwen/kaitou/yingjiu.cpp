#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //finally a problem i can do trivially 
    vector<vector<bool>> grid(N, vector<bool>(N));
    vector<vector<int>> dist(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            grid[i][j] = c == '1';
        }
    }
    int sr, sc; cin >> sr >> sc; sr--; sc--;
    int er, ec; cin >> er >> ec; er--; ec--;
    queue<array<int, 2>> q;
    dist[sr][sc] = 0;
    q.push({sr, sc});
    vector<int> dr = {1, -1, 0, 0}, dc = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nc < 0 || nr == N || nc == N) { continue; }
            if (grid[nr][nc] || dist[nr][nc] != -1) { continue; }
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    cout << dist[er][ec] << "\n";
}
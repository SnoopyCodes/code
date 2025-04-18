#include <bits/stdc++.h>

using namespace std;

vector<int> dr{1, -1, 0, 0}, dc{0, 0, 1, -1};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    array<int, 2> s, e;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                s[0] = i, s[1] = j;
            }   else if (grid[i][j] == 'B') {
                e[0] = i, e[1] = j;
            }
        }
    }
    vector<vector<int>> dist(N, vector<int>(M, 1e9));
    dist[s[0]][s[1]] = 0;
    queue<array<int, 2>> q;
    q.push(s);
    auto ob = [&](int r, int c) {
        return r < 0 || c < 0 || r == N || c == M;
    };
    while (dist[e[0]][e[1]] == 1e9) {
        auto [r, c] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (ob(nr, nc) || grid[nr][nc] == '#') { continue; }
            if (dist[nr][nc] != 1e9) { continue; }
            q.push({nr, nc});
            dist[nr][nc] = dist[r][c] + 1;
        }
    }
    cout << dist[e[0]][e[1]] << "\n";
}
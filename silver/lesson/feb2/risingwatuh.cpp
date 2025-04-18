#include <bits/stdc++.h>

using namespace std;

const vector<int> dr{1, -1, 0, 0}, dc{0, 0, 1, -1};
bool ob(int r, int c, vector<vector<int>> &v) {
    return r < 0 || c < 0 || r == v.size() || c == v[0].size();
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //just binary search
    int N; cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int s = -1, e = N * N + 1;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        queue<array<int, 2>> q;
        vector<vector<bool>> visited(N, vector<bool>(N));
        q.push({0, 0});
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (ob(nr, nc, grid) || visited[nr][nc]) { continue; }
                if (grid[nr][nc] > m) { continue; }
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
        if (visited[N-1][N-1]) { e = m; }
        else { s = m; }
    }
    cout << e << "\n";
}
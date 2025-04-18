#include <bits/stdc++.h>
#define arr array
using namespace std;

const vector<int> dr{1, -1, 0, 0}, dc{0, 0, 1, -1};

void solve() {
    int N, M; cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    int starts = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'G') { starts++; }
        }
    }
    //we can bfs from the endpoint
    //N, M <= 50
    //we have up to 1e6 ops
    //N^4
    //just block whatever we come from basically
    //that seems pretty optimal
    vector<vector<bool>> visited(N, vector<bool>(M));
    queue<arr<int, 2>> q;
    visited[N-1][M-1] = true;
    q.push({N - 1, M - 1});
    auto ob = [&](int r, int c) {
        return r < 0 || c < 0 || r == N || c == M;
    };
    int count = 0;
    bool valid = true;
    while (!q.empty()) {
        auto [r, c] = q.front();
        count += grid[r][c] == 'G';
        q.pop();
        bool block = false;
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (ob(nr, nc)) { continue; }
            if (grid[nr][nc] == 'B') { block = true; }
        }
        if (block && grid[r][c] != 'G') { grid[r][c] = '#'; continue; }
        else if (block) { valid = false; break; }
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (ob(nr, nc) || grid[nr][nc] == '#') { continue; }
            if (visited[nr][nc]) { continue; }
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }
    cout << (valid && count == starts) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
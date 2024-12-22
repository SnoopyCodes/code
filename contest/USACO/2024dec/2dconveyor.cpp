#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> res;
int cnt = 0;

vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = { 0, 1, 0,-1};

bool ob(int r, int c) {
    return r < 0 || r >= grid.size() || c < 0 || c >= grid.size();
}

int back(int r, int c) {
    res[r][c] = true;
    int cur = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r - dy[i], nc = c - dx[i];
        if (ob(nr, nc) || res[nr][nc]) { continue; }
        if (grid[nr][nc] == i || grid[nr][nc] == -1) {
            cur += back(nr, nc);
        }
    }
    return cur;
}

int main() {
    int N, Q; cin >> N >> Q;
    grid.resize(N, vector<int>(N, -1));
    vector<array<int, 2>> edges(Q);
    res.resize(N, vector<bool>(N));
    for (int q = 0; q < Q; q++) {
        char d;
        int r, c; cin >> r >> c >> d; r--; c--;
        if (d == 'U') { d = 0; }
        else if (d == 'R') { d = 1; }
        else if (d == 'D') { d = 2; }
        else { d = 3; }
        edges[q] = {r, c};
        grid[r][c] = d;
    }
    cnt = N * N;
    auto run = [&](int r, int c) {
        for (int d = 0; d < 4; d++) {
            int nr = r - dy[d], nc = c - dx[d];
            if (!ob(nr, nc) && (grid[nr][nc] == d || grid[nr][nc] == -1) && !res[nr][nc]) {
                cnt -= back(nr, nc);
            }
        }
    };
    for (int i = 0; i < N; i++) {
        int r = i, c = -1; run(r, c);
        r = -1, c = i; run(r, c);
        r = N, c = i; run(r, c);
        r = i, c = N; run(r, c);
    }
    vector<int> ans(Q); ans[Q-1] = cnt;
    for (int q = Q - 1; q > 0; q--) {
        auto [r, c] = edges[q];
        //we can look in all directions and see if we can touch a free one
        bool able = false;
        if (res[r][c]) { ans[q-1] = cnt; continue; }
        for (int i = 0; i < 4; i++) {
            int nr = r + dy[i], nc = c + dx[i];
            if (ob(nr, nc) || res[nr][nc]) { able = true; }
        }
        grid[r][c] = -1;
        if (able) { cnt -= back(r, c); }
        ans[q-1] = cnt;
    }
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }
}
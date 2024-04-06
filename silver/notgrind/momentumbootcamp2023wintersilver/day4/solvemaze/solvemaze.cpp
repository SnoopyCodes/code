#include <bits/stdc++.h>

using namespace std;
const int GOOD = 1;
const int BAD = 2;
const int WALL = -1;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int findGood(int r, int c) {
    if (r == -1 || r == grid.size() || c == -1 || c == grid[0].size()) { return 0; }
    if (grid[r][c] == WALL) { return 0; }
    if (visited[r][c]) { return 0; }
    visited[r][c] = true;
    int cur = grid[r][c] == GOOD;
    cur += findGood(r-1,c) + findGood(r+1, c) + findGood(r, c-1) + findGood(r, c+1);
    return cur;
}
bool solve() {
    int n, m; cin >> n >> m;
    grid.clear();
    grid.resize(n, vector<int>(m));
    vector<pair<int, int>> bads;
    int goods = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') { grid[i][j] = WALL; }
            else if (s[j] == 'B') {grid[i][j] = BAD; bads.push_back(make_pair(i, j)); }  //using {i, j} instead of make_pair also works
            else if (s[j] == 'G') { grid[i][j] = GOOD; goods++; } 
        }
    }
    for (const pair<int, int> &p : bads) {
        if (p.first != 0) {
            if (grid[p.first-1][p.second] == GOOD) { return false; }
            else if (grid[p.first-1][p.second] != BAD)
            grid[p.first-1][p.second] = WALL;
        }
        if (p.first != grid.size() - 1) {
            if (grid[p.first+1][p.second] == GOOD) { return false; }
            else if (grid[p.first+1][p.second] != BAD)
            grid[p.first+1][p.second] = WALL;
        }
        if (p.second != 0) {
            if (grid[p.first][p.second-1] == GOOD) { return false; }
            else if (grid[p.first][p.second-1] != BAD) 
            grid[p.first][p.second-1] = WALL;
        }
        if (p.second != grid[p.first].size()-1) {
            if (grid[p.first][p.second+1] == GOOD) { return false; }
            else if (grid[p.first][p.second+1] != BAD) 
            grid[p.first][p.second+1] = WALL;
        }
    }
    visited.clear(); visited.resize(n, vector<bool>(m));
    return (findGood(n-1,m-1)) == goods;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int Q; cin >> Q;
    int total = 0;
    for (int q = 0; q < Q; q++) {
        total += solve();
    }
    cout << total << endl;
}
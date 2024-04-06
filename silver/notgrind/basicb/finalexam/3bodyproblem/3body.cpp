#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> grid;
vector<vector<int>> visited;
pair<int, int> flood(int r, int c) {
    if (r == -1 || r == grid.size() || c == -1 || c == grid.size() || !grid[r][c]) { return {0, 1}; }
    if (visited[r][c]) { return {0, 0}; }
    visited[r][c] = true;
    pair<int, int> p;
    p.first++;
    // p.second += r == 0 || !grid[r-1][c];  //perimeter
    // p.second += r == grid.size()-1 || !grid[r+1][c];
    // p.second += c == 0 || !grid[r][c-1];
    // p.second += c == grid.size()-1 || !grid[r][c+1];
    pair<int, int> results;
    results = flood(r-1, c); p.first += results.first; p.second += results.second;
    results = flood(r+1, c); p.first += results.first; p.second += results.second;
    results = flood(r, c-1); p.first += results.first; p.second += results.second;
    results = flood(r, c+1); p.first += results.first; p.second += results.second;
    return p;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //note that the mercator projection shouldn't be used for this
    //note also that double counting perimeter should not be happening...
    int N; cin >> N;
    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == '#') { grid[i][j]++; }
        }
    }
    int maxA = INT_MIN, minP = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && grid[i][j]) {
                pair<int, int> result = flood(i, j);
                if (maxA < result.first) {
                    maxA = result.first; minP = result.second;
                }   else if (maxA == result.first && minP > result.second) {
                    minP = result.second;
                }
            }
        }
    }
    cout << maxA << " " << minP;
}
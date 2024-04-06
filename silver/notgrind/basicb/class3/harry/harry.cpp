#include <bits/stdc++.h>

using namespace std;
const int END = 1000;
vector<vector<int>> grid;
vector<vector<int>> visited;
string pathfind(int r, int c) {
    if (visited[r][c] || grid[r][c] == -1) { return "no"; }
    visited[r][c] = true;
    if (grid[r][c] == END) { return ""; }
    string x = pathfind(r+1, c);
    if (x != "no") { return "D" + x; }
    x = pathfind(r-1, c);
    if (x != "no") { return "U" + x; }
    x = pathfind(r, c-1);
    if (x != "no") { return "L" + x; }
    x = pathfind(r, c+1);
    if (x != "no") { return "R" + x; }
    return "no";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    grid.resize(N, vector<int>(M));
    visited.resize(N, vector<int>(M));
    int r, c;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '#') { grid[i][j] = -1; }
            else if (s[j] == 'S') { r = i; c = j; }
            else if (s[j] == 'F') { grid[i][j] = END; }
        }
    }
    cout << pathfind(r, c) << "\n";
}
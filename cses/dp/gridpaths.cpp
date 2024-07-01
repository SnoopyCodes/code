#include <bits/stdc++.h>

using namespace std;
vector<vector<bool>> grid;
vector<vector<int>> pos;
const int MOD = 1e9+7;
int amt = 0;
int N;
int dp(int r, int c) {
    if (pos[r][c] != -1) { return pos[r][c]; }
    pos[r][c] = 0;
    if (r > 0 && grid[r-1][c]) { pos[r][c] = (pos[r][c] + dp(r-1, c)) % MOD; }
    if (c > 0 && grid[r][c-1]) { pos[r][c] = (pos[r][c] + dp(r, c-1)) % MOD; }
    return pos[r][c];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    grid.resize(N, vector<bool>(N));
    pos.resize(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == '.') { grid[i][j] = true; }
        }
    }
    if (!grid[N-1][N-1]) { cout << 0; return 0; }
    pos[0][0] = 1;
    dp(N - 1, N - 1);
    cout << pos[N-1][N-1];
}
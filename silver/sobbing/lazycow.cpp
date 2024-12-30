#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int N, K; cin >> N >> K;
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> rot(2 * N - 1, vector<int>(2 * N - 1));
    for (int i = 0; i < N; i++) {  //we split it like diagonally idk
        int r = i, c = N - 1 - i;
        for (int j = 0; j < N; j++) {
            rot[r][c] = grid[i][j];
            r++; c++;
        }
    }
    if (K > N) { K = N; }
    //mission accomplished now figure out the pf
    vector<vector<int>> pf(2 * N, vector<int>(2 * N));
    for (int i = 1; i < 2 * N; i++) {
        for (int j = 1; j < 2 * N; j++) {
            pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + rot[i-1][j-1];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int r = i, c = N - 1 - i;
        for (int j = 0; j < N; j++) {
            //get rect centered here
            int pr = r - K, pc = c - K;
            int rr = min(2 * N - 1, pr + 2 * K + 1), cc = min(2 * N - 1, pc + 2 * K + 1);
            pr = max(pr, 0), pc = max(pc, 0);
            
            int res = pf[rr][cc] - pf[rr][pc]
            - pf[pr][cc] + pf[pr][pc];
            ans = max(res, ans);
            r++; c++;
        }
    }
    cout << ans << "\n";
}
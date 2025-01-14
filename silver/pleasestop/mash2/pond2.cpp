#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    //? isn't this sweep over it with a gp hash map ?
    //otherwise its a pain to maintain the thing
    int med = ((K * K + 1) / 2);
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    //minimize median
    //so at least med squares are < than it
    //oh yeah you just prefix sums and gg
    int s = -1, e = 1e9 + 1;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        // cout << m << "\n";
        vector<vector<int>> pf(N+1, vector<int>(N+1));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                pf[i][j] = pf[i][j-1] + pf[i-1][j] - pf[i-1][j-1] + (grid[i-1][j-1] <= m);
            }
        }
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= N; j++) {
        //         cout << pf[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        bool valid = false;
        for (int i = 0; i <= N - K; i++) {
            for (int j = 0; j <= N - K; j++) {
                // cout << pf[i + K][j + K] - pf[i][j + K] - pf[i + K][j] + pf[i][j] << " ";
                if (pf[i + K][j + K] - pf[i][j + K] - pf[i + K][j] + pf[i][j] >= med) { valid = true; }
            }
            // cout << "\n";
        }
        // cout << "\n";
        if (valid) { e = m; }
        else { s = m; }
        // cout << "\n";
    }
    cout << e << "\n";
    //
}
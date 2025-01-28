#include <bits/stdc++.h>

using namespace std;
int ways[5001][5001][2];
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    const int MOD = 1e9 + 7;
    int N, M; cin >> N >> M;
    //dp[i][j][k] = ways to lock j in first i with the ith set to k
    ways[0][0][0] = 1;
    ways[0][1][1] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            //to set this as 1:
            ways[i][j][1] = (ways[i-1][j][0] + (j > 0 ? ways[i-1][j-1][1] : 0)) % MOD;
            //0
            ways[i][j][0] = (ways[i-1][j][0] + ways[i-1][j][1]) % MOD;
        }
    }
    cout << (ways[N-1][M][0] + ways[N-1][M][1]) % MOD << "\n";
}
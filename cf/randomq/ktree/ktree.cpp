#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
ll dp[101][102][2]{0};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K, D; cin >> N >> K >> D;
    ll total = 0;
    dp[0][0][0] = 1;
    for (int i = 0; i <= K; i++) {  //iteration
        for (int k = 0; k < 2; k++) {
    // cout << "iter" << " " << i << "\n";
            for (int j = 0; j <= N; j++) {  //possible weights, don't go over N because it's either done or something already
                // cout << dp[i][j][k] << " ";
                if (i != 0 && j == 0) { continue; }
                if (!dp[i][j][k]) {
                    continue;
                }
                for (int edge = 1; edge <= K; edge++) {  //possible adds
                    int yes = (int) (edge >= D || k);
                    int weight = j + edge;
                    if (weight > N) { break; }
                    dp[i+1][weight][yes] = (dp[i+1][weight][yes] + dp[i][j][k]) % MOD;
                }
            }
            // cout << "\n";
        }
        // cout << "\n";
    }
    for (int i = 0; i <= K; i++) {
        total = (total + dp[i][N][1]) % MOD;
    }
    cout << total << "\n";
}

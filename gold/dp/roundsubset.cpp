#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    //we need to find the maximum number of 2s and 5s
    //we can do knapsack stating that for 0...i we can create some number of 2s and 5s
    //dp[i][j][k] be number of 2s we can create from 0...i-1, with j elements, and k 5s?
    //how many 5s can we have?
    //we can have 200 * log 5 (10^18)
    //we can have 26
    //we shouldn't do min knapsack
    vector<ll> A(N);
    for (int i = 0; i < N;i++) {
        cin >> A[i];
    }
    vector<vector<int>> dp(K + 1, vector<int>(27 * N, -1));
    int maxfive = 27 * N;
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        int twos = 0, fives = 0;
        while (A[i] % 2 == 0) { A[i] /= 2; twos++; }
        while (A[i] % 5 == 0) { A[i] /= 5; fives++; }
        for (int j = K - 1; j > -1; j--) {
            for (int k = maxfive - fives - 1; k > -1; k--) {
                if (dp[j][k] == -1) { continue; }  //does not exist
                dp[j+1][k + fives] = max(dp[j][k] + twos, dp[j+1][k + fives]);
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= K; j++) {
        for (int k = 1; k < maxfive; k++) {
            ans = max(ans, min(k, dp[j][k]));
        }
    }
    cout << ans << "\n";
}
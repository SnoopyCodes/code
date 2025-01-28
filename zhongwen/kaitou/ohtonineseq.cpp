#include <bits/stdc++.h>
#define long int64_t
#define mul(x, y) ((long(x) % MOD * (y) % MOD) % MOD + MOD) % MOD
#define add(x, y) (((x) % MOD + (y) % MOD) % MOD + MOD) % MOD

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //math or dp can probably solve this
    //dp is probably cleaner
    const int MOD = 1e9 + 7;
    //0 has none, 1 has at least one 0, 2 has at least one nine, and 3 has both
    vector<vector<int>> dp(N + 1, vector<int>(4));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        //0 select 1
        dp[i+1][1] = add(dp[i+1][1], dp[i][0]);
        //0 select 9
        dp[i+1][2] = add(dp[i+1][2], dp[i][0]);
        //0 select any other
        dp[i+1][0] = mul(dp[i][0], 8);
        //1 select 9
        dp[i+1][3] = add(dp[i+1][3], dp[i][1]);
        //1 select any other
        dp[i+1][1] = add(dp[i+1][1], mul(9, dp[i][1]));
        //2 select 1
        dp[i+1][3] = add(dp[i+1][3], dp[i][2]);
        //2 select any other
        dp[i+1][2] = add(dp[i+1][2], mul(9, dp[i][2]));
        //3 select any
        dp[i+1][3] = add(dp[i+1][3], mul(10, dp[i][3]));
    }
    cout << dp[N][3] << "\n";
}
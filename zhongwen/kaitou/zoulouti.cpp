#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //probably doesn't overflow?
    //somewhat bounded
    vector<int> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] += dp[i-1];
        if (i > 1) { dp[i] += dp[i-2]; }
    }
    cout << dp[N] << "\n";
}
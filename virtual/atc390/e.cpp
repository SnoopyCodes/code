#include <bits/stdc++.h>
#define vec vector
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, X; cin >> N >> X;
    vec<vec<int>> dp(3, vec<int>(X + 1, -1));
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for (int i = 0; i < N; i++) {
        int t, a, c; cin >> t >> a >> c;
        t--;
        for (int j = X; j > -1; j--) {
            if (dp[t][j] == -1 || j + c > X) { continue; }
            dp[t][j + c] = max(dp[t][j + c], dp[t][j] + a);
        }
    }
    vec<int> pf(X + 1);
    for (int i = 1; i <= X; i++) {
        pf[i] = max(pf[i-1], dp[2][i]);
    }
    int ans = 0;
    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= X - i - 1; j++) {
            int k = X - i - j;
            int res = min(dp[0][i], min(dp[1][j], pf[k]));
            ans = max(ans, res);
        }
    }
    cout << ans << "\n";
    //knapsack always comes back to haunt me
    //lets look at f
    //wait consider making a thing like
    //knapsack based on knapsack or something
    //select two things and see if another thing exists in 
    //the last one
    //ykwim?
    //calculable with prefix maxima?
    //lowkey maybe?
    //
}
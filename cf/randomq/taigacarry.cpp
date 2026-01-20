#include <bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i, a, b) for (auto i = a; i < (b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N, K; cin >> N >> K;
    if (K > 30) {
        //collect all the bits
        cout << __builtin_popcount(N) + K - 1 << "\n";
        return;
    }
    //dp for score, on # of moves used, if we have carry on this bit from before?
    vt<ii<2>> dp(K + 1, ii<2>{ -1, -1 });
    dp[0][0] = 0;
    int ans = 0;
    rep(i, 0, 63) {
        auto prev = dp;
        dp = vt<ii<2>>(K + 1, ii<2> { -1, -1 });
        rep(j, 0, K + 1) {
            rep(k, 0, 2) {
                if (prev[j][k] == -1) {
                    continue;
                }
                int d = k + bool(N >> i & 1);
                //0: we don't do anything
                if (d == 2) {
                    dp[j][1] = max(prev[j][k] + 1, dp[j][1]);
                }   else {
                    dp[j][0] = max(prev[j][k], dp[j][0]);
                }
                //1: we do stuff
                if (j == K) {
                    continue;
                }
                d++;
                if (d >= 2) {
                    dp[j + 1][1] = max(prev[j][k] + 1, dp[j + 1][1]);
                }   else {
                    dp[j + 1][0] = max(prev[j][k], dp[j + 1][0]);
                }
            }
        }
        rep(j, 0, K + 1) {
            ans = max(ans, dp[j][0]);
        }
    }
    cout << ans << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve(); 
}
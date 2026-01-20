#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, D; cin >> N >> D;
    auto p2 = vt<int>(N + 1);
    if (N > 5000) {
        return 0;
    }
    p2[0] = 1;
    rep(i, 1, N + 1) p2[i] = p2[i - 1] * 2 % MOD;
    /*
    N^2 dp first just to understand things
    D units to the left.
    we need a trainer on the left.
    wait lets just go from the right backwards
    and bank on trainer coverage
    like * 2^(number of cows in between here and last)
    wait am i him just do that
    dp[i] = # of ways : i is the leftmost trainer
    */

    vt<ii<2>> cows(N);
    rep(i, 0, N) {
        cin >> cows[i][0] >> cows[i][1];
    }

    vt<int> dp(N);
    sort(begin(cows), end(cows));
    for (int i = N - 1; i > -1; i--) {
        if (cows[i][1] == 0) {
            continue;
        }
        int ct = 0;
        rep(j, i + 1, N) {
            if (cows[j][0] - cows[i][0] <= D && cows[j][1] == 0) {
                ct++;
            }   else if (cows[j][1] == 1) {
                //so uh += dp[j] * 2^ct?
                (dp[i] += dp[j] * p2[ct]) %= MOD;
            }
        }
        (dp[i] += p2[ct]) %= MOD;
        cout << dp[i] << "\n";
    }
    int ans = 0;
    rep(i, 0, N) {
        (ans += dp[i]) %= MOD;
    }
    cout << ans << "\n";
}
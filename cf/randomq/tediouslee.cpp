#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
const int N = 2e6 + 5;
int dp[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    /*
    parity on depths is not forced or something
    */

    //editorial :(
    //dp_i = ans for level i
    //tree i = tree i-1 + tree i-2 * 2, based on just the images shown.
    //suppose that tree i cannot be colored : root is colored
    //why is this problem so hard??
    //somehow notice that trees that require roots/dont come in modulo 3
    //or prove it
    //so hard.
    rep(i, 3, N) {
        dp[i] = (dp[i-1] + dp[i-2] * 2 % MOD + (i % 3 == 0) * 4) % MOD;
    }

   
    int T; cin >> T; while (T -- > 0) {
        int x; cin >> x;
        cout << dp[x] << "\n";
    }
}
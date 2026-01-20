#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

const int N = 5e3 + 5;
int dp[N][N];

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int nsquare; cin >> nsquare;
    vt<int> c;
    rep(i, 0, nsquare) {
        int x; cin >> x; x--;
        if (c.empty() || c.back() != x) {
            c.add(x);
        }
    }
    nsquare = size(c);
    
    dp[0][nsquare - 1] = c[0] == c[nsquare - 1];
    //amass the max amount of doubles possible
    for (int len = nsquare - 1; len > 1; len--) {
        rep(i, 0, nsquare - len + 1) {
            int j = i + len - 1;
            //if i == j then + 1 from dp[i - 1][j + 1]
            //otherwise max of (i, j + 1), (i - 1, j) and (i - 1, j + 1)
            int boost = c[i] == c[j];
            dp[i][j] = max(dp[i][j], i <= 0? 0 : dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], j >= nsquare - 1 ? 0 : dp[i][j+1]);
            dp[i][j] = max(dp[i][j], i > 0 && j < nsquare - 1? dp[i-1][j+1] + boost : boost);
        }
    }
    //
    int ans = 0;
    rep(i, 1, nsquare - 1) {
        ans = max(ans, dp[i-1][i+1]);
    }
    cout << nsquare - 1 - ans << "\n";
    
}
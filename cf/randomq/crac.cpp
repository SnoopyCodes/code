#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N, K; cin >> N >> K;
    /*
    binary search?
    if w > h swap
    we fill up by w first.
    we can invest up to a * b in each rectangle
    precompute for each rectangle size how much is needed to score x points

    now we dp on k?
    O(nk^2)?
    if n = 10, k = 100 per test case, we have 100^2 * 100 * 10
    ah i guess its fine
    */

    vt<int> dp(K + 1, MOD);
    dp[0] = 0;
    rep(i, 0, N) {
        int w, h; cin >> w >> h;
        if (w > h) { swap(h, w); }
        auto prev = dp; //who cares about constant factor
        int cost = 0;
        rep(j, 1, w + h + 1) { //# of thing we get from here
            if (j <= h - w) {
                cost += w;
            }   else {
                //we have a w * w square.
                //w + (w - 1) + (w - 1) + (w - 2) ... 1
                int amt_in = j - (h - w) - 1;
                //(a + 1) / 2 ?
                cost += w - (amt_in + 1) / 2;
            }
            rep(k, 0, K - j + 1) {
                dp[k + j] = min(dp[k + j], prev[k] + cost);
            }
        }
    }
    if (dp[K] == MOD) cout << -1 << "\n";
    else cout << dp[K] << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
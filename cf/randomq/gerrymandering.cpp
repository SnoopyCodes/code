#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

template<class T> T mvec(T def) { return def; }
template<class T, class...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
const int MOD = 1e9 + 7;
void solve() {
    int N; cin >> N;
    auto grid = mvec<bool>(2, N, false);
    auto dp = mvec<int>(N, 3, 0);  //0 means top, 1 means bottom, 2 means FLAT
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            char x; cin >> x;
            grid[i][j] = x == 'A';
        }
    }
    dp[0][0] = -MOD;
    dp[0][1] = -MOD;
    dp[0][2] = -MOD;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            int ct = grid[j][i] + grid[j][i-1] + grid[!j][i-1];
            int val = ct > 1;
            dp[i][j] = max(dp[i][j], val + (i > 1 ? dp[i-2][2] : 0));
            //forgot to add the case where it is straight line
            //this is like suddenly hard
            //surely we can just hope it doesn't matter if we don't set it
            if (i > 1) {
                ct = grid[j][i] + grid[j][i-1] + grid[j][i-2];
                //holy casework.
                val = ct > 1;
                //if we fit one here, we MUST fit another on the other side,
                //we just need to figure out where.
                dp[i][2] = max(dp[i][2], (i > 2 ? dp[i-3][2] : 0) + val + (grid[!j][i] + grid[!j][i-1] + grid[!j][i-2] > 1));
                if (i > 2) {
                    dp[i][j] = max(dp[i][j], dp[i-3][j] + val + (grid[!j][i-1] + grid[!j][i-2] + grid[!j][i-3] > 1));
                }
            }
        }
        int ct = grid[0][i] + grid[1][i];
        dp[i][2] = max((ct + grid[0][i-1] > 1) + dp[i-1][1], dp[i][2]);
        dp[i][2] = max((ct + grid[1][i-1] > 1) + dp[i-1][0], dp[i][2]);
    }
    cout << dp[N-1][2] << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
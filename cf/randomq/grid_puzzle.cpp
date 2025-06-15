#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    //in what world is it optimal to 2x2 vs. row?
    //if a row > 4
    //always color row.
    //otherwise if the next row and this <= 4 then do the thing
    //dp[3]. [0]: place at 0, [1] place at 2, [2] place row
    array<int, 3> dp { N, N, 0 };
    for (int i = 0; i < N; i++) {
        array<int, 3> ndp = dp;
        if (A[i] == 0) {
            dp[0] = dp[0] + 1;
            dp[1] = dp[1] + 1;
            continue;
        }
        if (A[i] > 4) {
            ndp[2] = *std::min_element(dp.begin(), dp.end()) + 1;
            ndp[0] = ndp[1] = min(N, dp[2] + 2);
        }   else {
            if (A[i] <= 2) {
                ndp[2] = min(dp[2] + 1, dp[0]);
                ndp[1] = min(N, dp[2] + 2);
                ndp[0] = dp[2] + 1;
            }   else {
                ndp[2] = dp[2] + 1;
                ndp[1] = min(dp[0] + 1, dp[2] + 2);
                ndp[0] = min(dp[1] + 1, dp[2] + 2);
            }
        }
        dp = ndp;
    }
    cout << *std::min_element(dp.begin(), dp.end()) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
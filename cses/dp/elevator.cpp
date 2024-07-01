#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, X; cin >> N >> X;
    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    vector<array<int, 2>> dp(1 << N);
    dp[0] = {1, 0};
    for (int s = 1; s < 1 << N; s++) {
        dp[s][0] = N + 1;
        for (int p = 0; p < N; p++) {
            if (s & (1 << p)) {  //if we have this
                auto fatso = dp[s ^ (1 << p)];  //this is where we came from
                if (fatso[1] + weights[p] <= X) {  //to get here
                    fatso[1] += weights[p];
                }   else {
                    fatso[0]++;
                    fatso[1] = weights[p];
                }
                dp[s] = min(dp[s], fatso); //why do we do this?
            }
        }
    }
    cout << dp[(1 << N) - 1][0] << "\n";
}
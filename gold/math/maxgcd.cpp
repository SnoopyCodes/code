#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    //the eeditorial was like gcd doubling is nonexistent so dp
    //then set suffix maxes ;D:D:D
    //dp[i] to contain all different gcds obtainable with this as right bound
    //hmmm
    //bruh it was what i thought it would be
    vector<int> res(N + 1);
    vector<map<int, int>> dp(N);
    dp[0][0] = A[0];
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1];
        for (auto [pos, val] : dp[i]) {
            if (gcd(val, A[i]) != val) {
                
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << res[i] << " \n"[i == N];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
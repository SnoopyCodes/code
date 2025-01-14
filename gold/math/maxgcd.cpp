#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    vector<map<int, int>> dp(N);
    vector<int> res(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        dp[i][A[i]] = 1;
        res[1] = max(res[1], A[i]);
    }
    //the eeditorial was like gcd doubling is nonexistent so dp
    //then set suffix maxes ;D:D:D
    //dp[i] to contain all different gcds obtainable with this as right bound
    //hmmm
    //bruh it was what i thought it would be
    //dp[i][len] = gcd
    //dp[i][gcd] = len
    for (int i = 1; i < N; i++) {
        for (auto [cd, len] : dp[i-1]) {
            int ccd = gcd(cd, A[i]);
            dp[i][ccd] = max(dp[i][ccd], len + 1);
            res[dp[i][ccd]] = max(res[dp[i][ccd]], ccd);
        }
    }
    for (int i = 1; i < N + 1; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    //implementation of this is not even easy- it is easier to keep dp[i][gcd]
    //
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
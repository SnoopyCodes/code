#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
vector<vector<ll>> dp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<int> arr(N+1);
    dp.resize(N+1, vector<ll>(M+2));
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] != 0)
        dp[i][arr[i]] = 1;
    }
    int end = 0;
    int base = 1;
    //base cases: 0th is 0
    if (arr[1] == 0)
    for (int i = 1; i <= M; i++) { dp[1][i] = 1; }
    //if our base is 0 then we can definitely set
    for (int i = 2; i <= N; i++) {
        if (arr[i] != 0) {
            dp[i][arr[i]] = (dp[i-1][arr[i]-1] + dp[i-1][arr[i]] + dp[i-1][arr[i]+1]) % MOD;
            continue; 
        }
        for (end = i; end <= N && arr[end] == 0; end++) {}  //awkward
        while (i < end) {
            for (int m = 1; m <= M; m++) {
                //check that [i][m] is valid
                if (end - i >= abs(m - arr[end]) || end == N + 1)  //idk if this is valid
                dp[i][m] = (dp[i-1][m-1] + dp[i-1][m] + dp[i-1][m+1]) % MOD;
            }
            i++;
        }
        i--;
    }
    if (arr[N] == 0) {
        arr[N] = M;
        for (int i = 1; i <= M - 1; i++) {
            dp[N][M] += dp[N][i];
        }
    }
    cout << dp[N][arr[N]] % MOD;
}
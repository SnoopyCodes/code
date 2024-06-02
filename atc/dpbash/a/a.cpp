#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N + 1);
    vector<int> dp(N + 1, 1e9+2);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    dp[1] = 0;
    for (int i = 1; i < N; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(v[i] - v[i+1]));
        if (i + 2 <= N) { dp[i+2] = min(dp[i+2], dp[i] + abs(v[i] - v[i+2])); }
    }
    cout << dp[N];
}
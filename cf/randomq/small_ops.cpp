#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
const int MAXV = 1e6;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> Q;
    vector<vector<array<int, 3>>> queries(MAXV + 1);
    for (int q = 0; q < Q; q++) {
        int x, y, k; cin >> x >> y >> k;
        int g = gcd(x, y);
        queries[k].push_back({ x / g, y / g, q });
    }
    vector<int> ans(Q);
    vector<int> dp(MAXV + 1, MOD);
    dp[1] = 0;
    for (int i = 1; i <= MAXV; i++) {
        for (int j = 1; i * j <= MAXV; j++) {
            dp[i * j] = min(dp[i * j], dp[j] + 1);
        }
        for (auto [a, b, q] : queries[i]) {
            if (dp[a] == MOD || dp[b] == MOD) { ans[q] = -1; }
            else { ans[q] = dp[a] + dp[b]; }
        }
    }
    for (int a : ans) {
        cout << a << "\n";
    }
}
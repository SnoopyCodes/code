#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    ll N, X; cin >> N >> X;
    vector<int> cost(N);
    vector<int> happy(N);
    int maxhappy = 0;
    for (int i = 0; i < N; i++) {
        cin >> cost[i] >> happy[i];
        maxhappy += happy[i];
    }
    //no bitmasking or anything
    //dp[i][j] = min cost for i = month, j = happiness
    //available money then is i * X lmfao
    vector<ll> best(maxhappy + 1, 1e10);
    best[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = maxhappy; j > -1; j--) {
            ll available = i * X - best[j];
            if (available >= cost[i]) {
                best[j + happy[i]] = min(best[j] + cost[i], best[j + happy[i]]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < maxhappy + 1; i++) {
        if (best[i] != 1e10) { ans = max(ans, i); }
    }
    cout << ans << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}
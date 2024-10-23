#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> sizes(N);
    vector<ll> pf(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> sizes[i];
        pf[i + 1] = pf[i] + sizes[i];
    }
    vector<vector<ll>> cost(N, vector<ll>(N));
    //the problem comes from inclusive exclusive bounding and the cost function
    //dp[j][i] = min cost to form group of [j, i]

    for (int i = 1; i < N; i++) {
        cost[i][i - 1] = sizes[i-1] + sizes[i];
        for (int j = i - 2; j > -1; j--) {  //oh joy
            //what now
            //we want to form sum from j to i
            //choose some k between them
            ll best = 1e18;
            for (int k = i - 1; k >= j; k--) {
                best = min(best, cost[k][j] + cost[i][k + 1]);
            }
            cost[i][j] = best + pf[i + 1] - pf[j];
        }
    }
    cout << cost[N - 1][0] << "\n";
}
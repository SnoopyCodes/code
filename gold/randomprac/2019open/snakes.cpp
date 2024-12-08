#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("snakes.in", "r", stdin);
    //freopen("snakes.out", "w", stdout);
    int N, K; cin >> N >> K;
    //ok doesnt look too bad
    //let dp[i][j][k] be min waste from 0...i with j used and certain size
    //dp[i][j][k] = min(dp[i][j][k-1] + )

    vector<int> snakes(N);
    for (int i = 0; i < N; i++) {
        cin >> snakes[i];
    }
    vector<vector<int>> minwaste(N, vector<int>(K + 1, 1e9));
    vector<vector<int>> prev(N, vector<int>(K, 1e9));
    //so try push dp i guess
    for (int i = 0; i <= K; i++) {
        minwaste[0][i] = 0;
        if (i != K) { prev[i][0] = 0; }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {  //size used
            if (snakes[i] > snakes[j]) {
                for (int k = 0; k < K; k++) {
                    prev[j][k] = 1e9;
                }
                continue;
            }
            //we can use this size
            //find ones to transition to here
            //we can use previously at size j, or before at size i
            
        }
    }
    int ans = 1e9;
    cout << ans << "\n";
}
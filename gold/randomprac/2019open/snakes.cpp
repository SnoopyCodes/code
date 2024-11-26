#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("snakes.in", "r", stdin);
    //freopen("snakes.out", "w", stdout);
    int N, K; cin >> N >> K;
    //ok doesnt look too bad
    //let dp[i][j][k] be min waste from 0...i with j used and certain size
    //hold on cause 1e6
    //then let it be that index that contains teh maximum
    //push dp
    //no ll issue
    //only things over this size are valid
    //time complexity issue
    //uhhhhhh im very bad at this wtrf
    vector<int> snakes(N);
    for (int i = 0; i < N; i++) {
        cin >> snakes[i];
    }
    vector<vector<int>> minwaste(N + 1, vector<int>(K + 1, 1e9));
    vector<int> before(N);  //cost from directly before
    for (int i = 0; i < N; i++) {
        minwaste[0][i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int best = 1e9;
            for (int k = 0; k < N; k++) {
                if (snakes[k] < snakes[i]) { continue; }
                
            }
        }
    }
    int ans = 1e9;
    cout << ans << "\n";
}
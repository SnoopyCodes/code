#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int N; cin >> N;
    vector<int> brokes(N);
    for (int i = 0; i < N; i++) {
        cin >> brokes[i];
    }
    vector<vector<int>> range(N, vector<int>(N));
    for (int i = 0; i < N; i++) {  //place at
        for (int j = i; j < N; j++) {  //go to
            if (j != i) { range[i][j] = range[i][j-1]; }
            if (j - i != brokes[j]) { range[i][j]++; }
        }
    }
    //breakouts at i, j
    vector<vector<int>> best(N + 1, vector<int>(N, 101));
    //go forwards
    //ok
    //so, what?
    //waht does dp[i][j] mean?
    //it means that there are j breakouts in the first i, other than the first one, and min tamperings to make this fit
    best[0][0] = 101;
    for (int i = 1; i <= N; i++) {
        best[i][0] = range[0][i-1];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            //find minimum tamperings such that there are j breakouts other than the first

            //suppose that the ith log was tampered with
            best[i+1][j] = min(best[i+1][j], best[i][j] + 1);
            //suppose that it was tampered with and there was breakout here
            if (brokes[i] != 0) {
                best[i+1][j+1] = min(best[i+1][j+1], best[i][j] + 1);
            }
            //suppose it wasnt tampered with
            //then we have it is from 
            if (brokes[i] < i) {
                best[i+1][j+1] = min(best[i+1][j+1], best[i-brokes[i]][j] + range[i - brokes[i]][i]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << best[N][i] << "\n";
    }
}
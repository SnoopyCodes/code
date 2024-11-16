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
            if (j - i == brokes[j]) { range[i][j]++; }
        }
    }

    cout << N - range[0][N - 1] << "\n";

    //breakouts at i, j
    vector<vector<int>> best(N+1, vector<int>(N, -1));
    //go forwards
    best[0][0] = range[0][0];
    for (int i = 1; i < N; i++) {
        //update all that end with this i think
        //

        for (int j = 0; j < N; j++) {

        }
    }
}
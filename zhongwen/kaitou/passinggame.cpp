#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    auto ball = [&](int i) { return (i + N) % N; };
    //?
    //this is probably simple actually
    //let dp[i][j] be ways for i to have the ball after j turns
    vector<vector<int>> ways(M + 1, vector<int>(N));
    ways[0][0] = 1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            ways[i+1][ball(j-1)] += ways[i][j];
            ways[i+1][ball(j+1)] += ways[i][j];
        }
    }
    cout << ways[M][0] << "\n";

}
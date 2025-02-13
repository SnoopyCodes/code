#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 8;  //?

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> ways(N, vector<int>(M));
    ways[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i) { ways[i][j] = ways[i-1][j]; }
            if (j) { ways[i][j] = (ways[i][j] + ways[i][j-1]) % MOD; }
        }
    }
    cout << ways[N-1][M-1];
}
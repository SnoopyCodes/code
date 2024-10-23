#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    const int MOD = 1e9 + 7;
    vector<int> candies(N);
    for (int i = 0; i < N; i++) {
        cin >> candies[i];
    }
    vector<vector<int>> ways(N + 1, vector<int>(K + 1));
    ways[0][0] = 1;
    //ways[i][j] = ways to end up at i with x candies used?
    for (int i = 0; i < N; i++) {
        vector<int> pf(K + 2);
        for (int j = 0; j < K + 1; j++) {
            pf[j+1] = (pf[j] + ways[i][j]) % MOD;
        }
        for (int j = 0; j < K + 1; j++) {  //what we are pushing to
            //eat up to j
            ways[i+1][j] = (pf[j+1] - (j - candies[i] > 0 ? pf[j - candies[i]] : 0) + MOD) % MOD;
        }
    }
    cout << ways[N][K] << "\n";
}
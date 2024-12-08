#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    //we can compute prefix sums on how long it takes to convert a subarray to some character
    //let dp[i][j] be convert 0...i into a valid sequence ending with char j, min val
    //then we can look back K and convert with pf sums, then take remainder from before
    //but wait this somewhat doesnt work
    //there can be broken sequences like aac combined with cc
    //is it possible to maintain for each index i
    //the min cost to end on char j
    //subtask time
    //N^2K?
    //the problem is we can look back farther than K
    //NK is feasible
    //
    string S; cin >> S;
    vector<int> cur(N);
    for (int i = 0; i < N; i++) {
        cur[i] = S[i] - 'a';
    }
    vector<vector<int>> cost(M, vector<int>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cost[i][j];
        }
    }
    //
}
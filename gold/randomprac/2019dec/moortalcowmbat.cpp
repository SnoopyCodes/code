#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    int N, M, K; cin >> N >> M >> K;
    //we can compute prefix sums on how long it takes to convert a subarray to some character
    //let dp[i][j] be convert 0...i into a valid sequence ending with char j, min val
    //then we can look back K and convert with pf sums, then take remainder from before
    //but wait this somewhat doesnt work
    //there can be broken sequences like aac combined with cc
    //is it possible to maintain for each index i
    //the min cost to end on char j
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
    //floyd warshall smh what an impl detail
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    //dp[i][j] = min days to convert 0...i into valid sequence
    //right do prefix sums
    //then for i and j we consider that pfx sum
    //plus the min of any "extender" sequence of [i - K][j]
    vector<vector<int>> pf(N + 1, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pf[i + 1][j] = pf[i][j] + cost[cur[i]][j];
        }
    }
    //remember to get it is pf[r + 1] - pf[l]
    vector<vector<int>> best(N, vector<int>(M));
    vector<int> extend(M);  //important part
    for (int i = K - 1; i < N; i++) {  //i think we are doing pull dp then
        int minc = 1e9;
        for (int j = 0; j < M; j++) {
            best[i][j] = pf[i + 1][j] - pf[i - (K - 1)][j] + extend[j];
            if (i - (K - 1) >= K - 1) {
                minc = min(best[i - (K - 1)][j], minc);
            }
        }
        for (int j = 0; j < M; j++) {
            if (i - (K - 1) < K - 1) {
                extend[j] = pf[i+1 - (K - 1)][j];
            }   else {
                //min cost of transforming, or just minc
                extend[j] = min(extend[j] + cost[cur[i - (K - 1)]][j], minc);
            }
        }
    }
    cout << *min_element(best[N-1].begin(), best[N-1].end()) << "\n";
}
#include <bits/stdc++.h>

using namespace std;
vector<int> coins;
vector<int> current;
vector<vector<int>> feasible;
const int MOD = 1e9+7;
void feats(int k, int x) {  //if we can construct sum x with 0... k
    feasible[0][0] = true;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= x; j++) {
            feasible[i][j] = feasible[i-1][j];
            if (j - coins[i] >= 0) {
                feasible[i][j] = (feasible[i][j] + feasible[i][j - coins[i]]) % MOD;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, X; cin >> N >>  X;
    coins.resize(N+1);
    for (int i = 0; i < N; i++) {
        cin >> coins[i+1];
    }
    feasible.resize(N+1, vector<int>(X+1));
    feats(N, X);
    cout << feasible[N][X] << "\n";
}
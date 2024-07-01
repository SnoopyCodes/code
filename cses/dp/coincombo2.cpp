#include <bits/stdc++.h>

using namespace std;
vector<int> coins;
vector<int> feasible;
const int MOD = 1e9+7;
void feats(int k, int x) {
    feasible[0] = true;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= x; j++) {
            if (j - coins[i] >= 0) {
                feasible[j] = (feasible[j] + feasible[j - coins[i]]) % MOD;
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
    feasible.resize(X+1);
    feats(N, X);
    cout << feasible[X] << "\n";
}
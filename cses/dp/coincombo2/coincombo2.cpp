#include <bits/stdc++.h>

using namespace std;
vector<int> coins;
vector<int> current;
vector<vector<int>> feasible;
int possible = 0;
const int MOD = 1e9+7;
void run(int x, int sum) {  //if a sum can be formed with the 
    if (sum == 0) { possible++; possible %= MOD; return; }
    for (int i = 0; i * coins[x] <= sum; i++) {
        if (feasible[x][sum - i * coins[x]])
        run(x-1, sum - i * coins[x]);
    }
}
void feats(int k, int x) {  //if we can construct sum x with 0... k
    feasible[0][0] = true;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= x; j++) {
            if (j - coins[i] >= 0) { feasible[i][j] |= feasible[i-1][j - coins[i]]; }
            feasible[i][j] |= feasible[i-1][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    //well this is a way
    //we need to not do any useless things though
    //okay maybe this is not a way
    //then what
    //we may say that we have a certain amount of sum that might work
    //just use the algorithm to determine whether a sum is possible without this number
    //
    int N, X; cin >> N >>  X;
    coins.resize(N+1);
    for (int i = 0; i < N; i++) {
        cin >> coins[i+1];
    }
    feasible.resize(N+1, vector<int>(X+1));
    sort(coins.begin(), coins.end());
    feats(N, X);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= X; j++) {
            cout << feasible[i][j];
        }
        cout << "\n";
    }
    run(N, X);
    cout << possible << "\n";
}
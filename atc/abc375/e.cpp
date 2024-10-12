#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //this seems hard
    //there is someone in every team
    vector<array<int, 2>> all(N);
    int sA = 0, sB = 0, sC = 0;
    int total = 0;
    for (int i = 0; i < N; i++) {
        int t, s; cin >> t >> s;
        total += s;
        all[i] = {t, s};
        if (t == 1) { sA += s; }
        else if (t == 2) { sB += s; }
        else { sC += s; }
    }
    if (total % 3 != 0) { cout << -1 << "\n"; return 0; }
    //the sum of all b <= 1500...
    int target = total / 3;
    //start with team a. set its own members as negative, and all others as positive
    //we want to find the smallest size knapsack so that sum = sA - target is fulfilled.
    //have we ever done negative knapsack tho?

    vector<vector<int>> possible(N + 1, vector<int>(3001, N + 1));
    vector<vector<int>> backtrack(N + 1, vector<int>(3001, -1));
    auto set = [&] (int i, int j, int val) {
        if (possible[i+1][j + val] > possible[i][j] + (val != 0)) {
            possible[i+1][j + val] = possible[i][j] + (val != 0);
            if (val != 0) {
                backtrack[i+1][j + val] = i;
            }   else {
                backtrack[i+1][j] = backtrack[i][j];
            }
        }
    };
    possible[0][1500] = 0;
    for (int i = 0; i < N; i++) {
        int val = all[i][1];
        if (all[i][0] == 1) { val = -val; }
        for (int j = 0; j < 3001; j++) {
            set(i, j, 0);
            if (j + val > -1 && j + val < 3001) {
                set(i, j, val);
            }
        }
    }
    cout << possible[N][target + 1500] << "\n";
}
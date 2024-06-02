#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //screw floating point error
    int N; cin >> N;
    vector<double> rng(N);
    for (int i = 0; i < N; i++) {
        cin >> rng[i];
    }
    vector<vector<double>> possible(N+1, vector<double>(N + 1));  //chance of having x heads at this time
    possible[0][0] = 1;
    //
    for (int i = 0; i < N; i++) {  //coin we consider
        for (int j = 0; j < N; j++) {
            if (possible[i][j] == 0) { continue; }
            possible[i+1][j + 1] += possible[i][j] * (rng[i]); 
            possible[i+1][j] += possible[i][j] * (1 - rng[i]);
        }
    }
    double chance = 0;
    for (int i = N / 2 + 1; i <= N; i++) {
        chance += possible[N][i];
    }
    cout << fixed;
    cout << setprecision(10);
    cout << chance << "\n";
}
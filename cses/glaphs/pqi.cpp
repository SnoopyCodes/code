#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<int> par(N);
    int max_jumps = 30;
    for (int i = 0; i < N; i++) {
        int p; cin >> p; p--;
        par[i] = p;
    }
    vector<vector<int>> jumps(max_jumps, vector<int>(N));
    for (int i = 0; i < N; i++) { jumps[0][i] = par[i]; }
    for (int i = 1; i < max_jumps; i++) {
        for (int j = 0; j < N; j++) {
            jumps[i][j] = jumps[i-1][jumps[i-1][j]];
        }
    }
    for (int q = 0; q < Q; q++) {
        int s, d; cin >> s >> d; s--;
        for (int i = 0; i < max_jumps; i++) {
            if (d & 1 << i) { s = jumps[i][s]; }
        }
        cout << s + 1 << "\n";
    }
}
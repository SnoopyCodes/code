#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<bool>> dir(N, vector<bool>(N));
    vector<int> colcost(N), rowcost(N);
    for (int i = 0; i < N; i++) {
        for (int j =0 ; j < N; j++) {
            char c; cin >> c;
            dir[i][j] = c == 'R';
        }
        cin >> colcost[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> rowcost[i];
    }
    vector<vector<int>> cows(N, vector<int>(N, 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > 0 && !dir[i-1][j]) { cows[i][j] += cows[i-1][j]; }
            if (j > 0 && dir[i][j-1]) { cows[i][j] += cows[i][j-1]; }
        }
    }
    auto calc = [&]() {
        int cost = 0;
        for (int i = 0; i < N; i++) {
            //column
            if (dir[i][N-1]) { cost += colcost[i] * cows[i][N-1]; }
            if (!dir[N-1][i]) { cost += rowcost[i] * cows[N-1][i]; }
        }
        return cost;
    };
    cout << calc() << "\n";
    int Q; cin >> Q;
    auto trav = [&](int r, int c, int delta) {
        while (r < N && c < N) {
            cows[r][c] += delta;
            if (dir[r][c]) { c++; }
            else { r++; }
        }
    };
    for (int q = 0; q < Q; q++) {
        int r, c; cin >> r >> c; r--; c--;
        if (dir[r][c]) {
            trav(r, c + 1, -cows[r][c]);
            trav(r + 1, c, cows[r][c]);
        }   else {
            trav(r + 1, c, -cows[r][c]);
            trav(r, c + 1, cows[r][c]);
        }
        dir[r][c] = !dir[r][c];
        cout << calc() << "\n";
    }
}
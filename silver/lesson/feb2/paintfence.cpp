#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    //run prefix sums for every sideways grid
    //make an offset because if things go off grid we count them still
    int L = 3001;
    vector<vector<int>> grid(L, vector<int>(L + 1));
    int off = 1000;
    for (int i = 0; i < N; i++) {
        int c, r, d; cin >> c >> r >> d; c += off, r += off;
        for (int j = 0; j < 2 * d + 1; j++) {
            //frick
            grid[r - (d - j)][c - (j > d ? 2 * d - j : j)]++;
            grid[r - (d - j)][c + (j > d ? 2 * d - j : j) + 1]--;
        }
    }
    int count = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 1; j <= L; j++) {
            grid[i][j] += grid[i][j-1];
            if (grid[i][j] == K) { count++; }
        }
    }
    cout << count << "\n";
}
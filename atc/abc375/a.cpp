#include <bits/stdc++.h>

using namespace std;
//it becomes j, N - i for i,j
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    cout << "\n";
    vector<vector<char>> ans(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //???
            //how do we say distance from the center?
            //first, i = 0, j = 0, i = N - 1, j = N - 1 is eliminated
            //then, i = 1, j = 1, i = N - 2, j = N - 2 is eliminated
            int smol = min(i, j) + 1;
            int beeg = N - max(i, j);
            int x = min(smol, beeg) % 4;
            //the problem is that ?
            int ti = i, tj = j;
            for (int k = 0; k < x; k++) {
                int tmp = ti;
                ti = tj;
                tj = N - 1 - tmp;
            }
            ans[ti][tj] = grid[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
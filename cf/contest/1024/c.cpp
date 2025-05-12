#include <bits/stdc++.h>

using namespace std;


const array<int, 4> dr{-1, 0, 1, 0}, dc{0, -1, 0, 1};

void solve() {
    int N; cin >> N;
    //trivial??
    //place them in spiral form from middle of matrix
    vector<vector<int>> grid(N, vector<int>(N));
    int cur = 0;
    int d = 0;
    int len = 1;
    int r = N / 2, c = N / 2;
    while (cur < N * N) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < len; j++) {
                if (cur == N * N) { break; }
                grid[r][c] = cur++;
                r += dr[d];
                c += dc[d];
            }
            d = (d + 1) % 4;
        }
        len++;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " \n"[j == N - 1];
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
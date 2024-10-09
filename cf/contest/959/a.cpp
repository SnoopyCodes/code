#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> m(N, vector<int>(M));
    vector<vector<int>> c(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
        }
    }
    if (N * M == 1) { cout << -1 << "\n"; return; }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            c[i][j] = m[N - i - 1][M - j - 1];
            if (c[i][j] == m[i][j]) {
                int tmp = c[i][j];
                if (i == 0) {
                    c[i][j] = c[i][j - 1];
                    c[i][j-1] = tmp;
                }   else {
                    c[i][j] = c[i-1][j];
                    c[i-1][j] = tmp;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << c[i][j];
            if (j != M - 1) { cout << " "; }
        }
        cout << "\n";
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}
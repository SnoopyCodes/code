#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            grid[i][j] = s[j] - '0';
        }
    }
    //first suppose the first bit is 0
    int ops = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((i + j) % 2 == 0 && grid[i][j] != 0) {
                ops++;
            }   else if ((i + j) % 2 == 1 && grid[i][j] != 1) {
                ops++;
            }
        }
    }
    int test2 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((i + j) % 2 == 0 && grid[i][j] != 1) {
                test2++;
            }   else if ((i + j) % 2 == 1 && grid[i][j] != 0) {
                test2++;
            }
        }
    }
    cout << min(ops, test2) << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}
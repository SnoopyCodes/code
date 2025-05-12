#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<int>> g(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = i + 1; k <= N; k++) {
                for (int l = j + 1; l <= N; l++) {
                    set<int> s;
                    for (int m = i; m < k; m++) {
                        for (int n = j; n < l; n++) {
                            s.insert(g[m][n]);
                        }
                    }
                    int at = 0;
                    for (int x : s) {
                        if (x != at) { break; }
                        at++;
                    }
                    sum += at;
                }
            }
        }
    }
    cout << sum << "\n";
}
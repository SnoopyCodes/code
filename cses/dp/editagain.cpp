#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s, t; cin >> s >> t;
    int N = s.size(), M = t.size();
    //let dp[i][j] be the edit dist
    vec<vec<int>> moves(N, vec<int>(M, INF));
    moves[0][0] = s[0] != t[0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //uhh
            if (i) { moves[i][j] = min(moves[i][j], moves[i-1][j] + 1); }
            else { moves[i][j] = min(moves[i][j], j + (s[i] != t[j])); }
            if (j) { moves[i][j] = min(moves[i][j], moves[i][j-1] + 1); }
            else { moves[i][j] = min(moves[i][j], i + (s[i] != t[j])); }
            if (i && j) { moves[i][j] = min(moves[i][j], moves[i-1][j-1] + (s[i] != t[j])); }
        }
    }
    cout << moves[N-1][M-1] << "\n";
}
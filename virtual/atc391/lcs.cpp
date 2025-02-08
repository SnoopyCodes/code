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
    //review lcs im dumb
    string s, t; cin >> s >> t;
    int N = s.size(), M = t.size();
    vec<vec<int>> best(N, vec<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            best[i][j] = s[i] == t[j];
            if (i) { best[i][j] = max(best[i-1][j], best[i][j]); }
            if (j) { best[i][j] = max(best[i][j-1], best[i][j]); }
            if (i && j) { best[i][j] = max(best[i][j], best[i-1][j-1] + (s[i] == t[j])); }
        }
    }
    cout << best[N-1][M-1] << "\n";
}
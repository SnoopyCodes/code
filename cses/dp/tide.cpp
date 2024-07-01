#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s1, s2; cin >> s1 >> s2;
    int N = s1.size(), M = s2.size();
    vector<vector<int>> edit(N+1, vector<int>(M+1));
    edit[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        edit[i][0] = edit[i-1][0]+1;
    }
    for (int j = 1; j <= M; j++) {
        edit[0][j] = edit[0][j-1]+1;
    }
    //consider what our moves are
    //at any point, our current string must match that of the previous
    //dp[i][j] should be moves to transform n.substr(0, i) into m.substr(0, j)
    //the problem is that the same letter is matching up i see
    //
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            bool same = !(s1[i-1] == s2[j-1]);
            edit[i][j] = min(edit[i-1][j], edit[i][j-1]) + 1;
            edit[i][j] = min(edit[i][j], edit[i-1][j-1] + same);
        }
    }
    cout << edit[N][M];
}
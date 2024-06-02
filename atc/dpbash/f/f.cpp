#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s, t; cin >> s >> t;
    //so we have to make a dp but what does that contain?
    //it should have the lcs in range [0, i] of s, and [0, j] of t
    //okay we should have it store pair<array<int, 2> [lastrealchar], length>
    int N = s.size(), M = t.size();
    vector<vector<array<int, 3>>> speed(N + 1, vector<array<int, 3>>(M + 1));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i != N && j != M && s[i] == t[j]) {
                if (speed[i+1][j+1][2] < speed[i][j][2] + 1) {
                    //so uh.. set i + 1 j + 1 to point back to this one?
                    speed[i+1][j+1][0] = i, speed[i+1][j+1][1] = j, speed[i+1][j+1][2] = speed[i][j][2]+1;
                }
            }   else if (i != N && j != M) {
                if (speed[i+1][j+1][2] < speed[i][j][2]) {
                    speed[i+1][j+1] = speed[i][j];
                }
            }
            if (i != N && speed[i + 1][j][2] < speed[i][j][2]) {
                speed[i+1][j] = speed[i][j];
            }
            if (j != M && speed[i][j+1][2] < speed[i][j][2]) {
                speed[i][j+1] = speed[i][j];
            }
        }
    }
    string x; x.resize(speed[N][M][2]);
    for (int i = x.size() - 1; i >= 0; i--) {
        x[i] = s[speed[N][M][0]];
        int tmp = N;
        N = speed[N][M][0];
        M = speed[tmp][M][1];
    }
    cout << x;
    //
}
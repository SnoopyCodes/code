#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);
    int N, K; cin >> N >> K;
    int maxc = 201;
    vector<vector<int>> points(maxc+1, vector<int>(maxc + 1));
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        points[x1][y1]++;
        points[x1][y2+1]--;
        points[x2+1][y1]--;
        points[x2+1][y2+1]++;
    }
    vector<vector<int>> coats(points);
    int ans = 0;
    for (int i = 0; i < maxc + 1; i++) {
        for (int j = 0; j < maxc + 1; j++) {
            if (i > 0) { coats[i][j] += coats[i-1][j]; }
            if (j > 0) { coats[i][j] += coats[i][j-1]; }
            if (i > 0 && j > 0) { coats[i][j] -= coats[i-1][j-1]; }
            ans += coats[i][j] == K;
            cout << coats[i][j] << " ";
        }
        cout << "\n";
    }

cout << "\n";
    for (int i = 0; i < maxc+1; i++) {
        for (int j = 0; j < maxc + 1; j++) {
            if (coats[i][j] == K) { coats[i][j] = -1; }
            else if (coats[i][j] == K - 1) { coats[i][j] = 1; }
            else { coats[i][j] = 0; }
        }
    }
    for (int i = 0; i < maxc + 1; i++) {
        for (int j = 0; j < maxc + 1; j++) {
            if (i > 0) { coats[i][j] += coats[i-1][j]; }
            if (j > 0) { coats[i][j] += coats[i][j-1]; }
            if (i > 0 && j > 0) { coats[i][j] -= coats[i-1][j-1]; }
            cout << coats[i][j] << " ";
        }
        cout << "\n";
    }
    //ok
    //now first solve the subproblem: in a rectangle, find the maximum that we can cover with just one
    //N^4 skul
    //so we have an N^5 solution
    //speed up to N^3
    //keep like the minimum or smth
    //draw a line
    //we can now find maximums in O(N^2) time
    //suffering
    auto sum2d = [&](int x1, int y1, int x2, int y2)  {
        return coats[x2+1][y2+1] - coats[x2+1][y1] - coats[x1][y2+1] + coats[x1][y1];
    };
    auto best = [&](int x1, int y1, int x2, int y2) {
        int res = 0;
        vector<int> least(maxc + 1);
        for (int i = 0; i < maxc + 1; i++) {

            for (int j = 0; j < maxc + 1; j++) {

            }
        }
    };
    
}
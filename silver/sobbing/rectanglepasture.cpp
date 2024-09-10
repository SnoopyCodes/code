#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //this is why i hate usaco
    //please never do this again
    //basically coord compression i guess
    int N; cin >> N;
    vector<vector<int>> yorushika(N, vector<int>(N));
    //peak
    vector<array<int, 2>> cowx(N);
    vector<array<int, 2>> cowy(N);
    vector<array<int, 2>> indices(N);
    for (int i = 0; i < N; i++) {
        cin >> cowx[i][0] >> cowy[i][0];
        cowx[i][1] = cowy[i][1] = i;
    }
    sort(cowx.begin(), cowx.end());
    sort(cowy.begin(), cowy.end());
    int dx = -1, dy = -1, lx = -1, ly = -1;  //distinct x, y; last x, y
    for (int i = 0; i < N; i++) {
        if (cowx[i][0] != lx) { dx++; lx = cowx[i][0]; }
        if (cowy[i][0] != ly) { dy++; ly = cowy[i][0]; }
        indices[cowx[i][1]][0] = dx;
        indices[cowy[i][1]][1] = dy;
    }
    for (int i = 0; i < N; i++) {
        yorushika[indices[i][0]][indices[i][1]]++;
    }
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            cout << yorushika[i-1][j-1] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    vector<vector<int>> pfx(N + 1, vector<int>(N + 1));
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            pfx[i][j] = yorushika[i-1][j-1] - pfx[i-1][j-1] + pfx[i-1][j] + pfx[i][j-1];
            cout << pfx[i][j] << " ";
        }
        cout << "\n";
    }
    int ans = 0;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (yorushika[i-1][j-1]) {
                ans += pfx[i][j];
                cout << i << " " << j << "\n";
                cout << pfx[i][j] << "\n";
            }
        }
    }
    cout << ans << "\n";
}
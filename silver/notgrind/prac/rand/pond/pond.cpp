#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> grid;
vector<vector<int>> pfx;
int N, K;
int minpass;
bool bs(int x) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pfx[i+1][j+1] = pfx[i+1][j] + pfx[i][j+1] - pfx[i][j];
            if (grid[i][j] > x) { pfx[i+1][j+1]++; }
        }
    }
    bool lol = false;
    for (int i = 0; i < N - K+1; i++) {
        for (int j = 0; j < N - K+1; j++) {
            if (pfx[i+K][j+K] - pfx[i][j+K] - pfx[i+K][j] + pfx[i][j] < minpass) {lol=true;}
        }
    }
    return lol;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    grid.resize(N, vector<int>(N));
    pfx.resize(N+1, vector<int>(N+1));
    cin >> K;
    minpass = ((K * K) / 2) + 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int s = -1, e = 1e9;
    while (e > s+1) {
        int m = (s+e) / 2;
        bool x = bs(m);
        cout << m << " " << x << "\n";
        if (x) { e = m; }
        else { cout << "hi" << "\n"; s = m; }
    }
    cout << e << "\n";
}
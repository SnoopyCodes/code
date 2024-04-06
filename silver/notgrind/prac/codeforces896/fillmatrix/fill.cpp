#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        v.resize(max(m, n), vector<int>(m));
        //so fill the matrix
        //the max value is m if n >= m
        //any extraneous n's must copy the first
        //just get the columns right
        for (int c = m-1; c >= 0; c--) {
            int col = m-1 - c;
            v[m-1][c] = m-1 - c;
            if (m > 1)
            v[m-2][c] = v[m-1][c];
            for (int r = m-3; r >= 0; r--) {
                v[r][c] = v[r+1][c]+1;
                if (v[r][c] == m) { v[r][c] = 0; }
            }
        }
        //we have guaranteed that for rows 0 to i, the mex vals will be 0 through i?
        //if n+1 >= m then our answer is literally just m.
        //if m > n+1 then we have a vector of 
        if (m == 1) { cout << 0 << "\n"; }
        else if (n+1 >= m) { cout << m << "\n"; }
        else if (m > n+1) {
            cout << n+1 << "\n";
        }
        for (int i = m; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v[i][j] = v[i-m][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }

    }
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int H, W; cin >> H >> W;
    //find minl, minu
    vector<vector<char>> grid(H, vector<char>(W));
    int l = W, r = 0, u = H, d = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                l = min(l, j);
                r = max(r, j);
                u = min(i, u);
                d = max(d, i);
            }
        }
    }
    bool valid = true;
    for (int i = u; i <= d; i++) {
        for (int j = l; j <= r; j++) {
            if (grid[i][j] == '.') { valid = false; }
        }
    }
    if (valid) { cout << "Yes" << "\n"; }
    else { cout << "No" << "\n"; }

}
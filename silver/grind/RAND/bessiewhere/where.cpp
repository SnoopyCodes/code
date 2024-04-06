#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> img;
vector<vector<bool>> visited;
struct PCL {
    int xl, xr, yl, yr;
};
vector<PCL> pcls;
void flood(int i, int j, int xl, int xr, int yl, int yr, int col) {
    if (i < xl || i == xr || j < yl || j == yr || img[i][j] != col || visited[i][j]) { return; }
    visited[i][j] = true;
    flood(i-1, j, xl, xr, yl, yr, col);
    flood(i+1, j, xl, xr, yl, yr, col);
    flood(i, j+1, xl, xr, yl, yr, col);
    flood(i, j-1, xl, xr, yl, yr, col);
}
bool is_pcl(int xl, int xr, int yl, int yr) {
    visited.clear();
    visited.resize(img.size(), vector<bool>(img.size()));
    //count num regions for color 1, color 2
    int c1 = -1, c2 = -1;
    int r1 = 0, r2 = 0;
    for (int i = xl; i < xr; i++) {
        for (int j = yl; j < yr; j++) {
            if (visited[i][j]) { continue; }
            if (c1 == -1 || img[i][j] == c1) {
                c1 = img[i][j];
                r1++;
                flood(i, j, xl, xr, yl, yr, img[i][j]);
            }   else if (c2 == -1 || img[i][j] == c2) {
                c2 = img[i][j];
                r2++;
                flood(i, j, xl, xr, yl, yr, img[i][j]);
            }   else {  //colors wrong
                return false;
            }
        }
    }
    if (!(r1 == 1 && r2 >= 2 || r2 == 1 && r1 >= 2)) {return false; }
    // cout << xl << " " << xr << " " << yl << " " << yr << "\n";
    // cout << "\n";
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int N; cin >> N;
    img.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            img[i][j] = s[j] - 'A';
        }
    }
    for (int i = 0; i < N; i++) {  //xl
        for (int j = 0; j < N; j++) {  //yl
            for (int k = i+1; k <= N; k++) {  //xr
                for (int l = j+1; l <= N; l++) {  //yr
                    if (is_pcl(i, k, j, l)) {
                        pcls.push_back({i, k, j, l});
                    }
                }
            }
        }
    }
    int tot = pcls.size();
    for (int j = 0; j < pcls.size(); j++) {
        PCL c = pcls[j];
        for (int i = 0; i < pcls.size(); i++) {
            if (i == j) { continue; }
            PCL p = pcls[i];
            if (p.xl <= c.xl && p.xr >= c.xr && p.yl <= c.yl && p.yr >= c.yr) { tot--; break; }
        }
    }
    cout << tot;
    //O(N^6) if N^4 to choose a rect, N^2 to check if pcl
    //how check if already in bounds of another?
    //we have the pcl thing set up
    //umm ok so check the pcls i guess
}
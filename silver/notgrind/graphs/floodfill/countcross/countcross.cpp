#include <bits/stdc++.h>

using namespace std;
struct field {
    bool visited;
    bool cow;
    bool xl, xr, yd, yu;
};
vector<vector<field>> fields;
int floodfill(int x, int y) {
    if (x == -1 || x == fields.size() || y == -1 || y == fields.size()) { return 0; }
    if (fields[x][y].visited) { return 0; }
    fields[x][y].visited = true;
    int count = fields[x][y].cow;
    if (count) { fields[x][y].cow = false; }
    if (!fields[x][y].xl) { count += floodfill(x-1, y); }
    if (!fields[x][y].xr) { count += floodfill(x+1, y); }
    if (!fields[x][y].yu) { count += floodfill(x, y+1); }
    if (!fields[x][y].yd) { count += floodfill(x, y-1); }
    return count;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    int N, K, R;
    cin >> N >> K >> R;
    fields.resize(N, vector<field>(N));
    vector<pair<int, int>> cows;
    for (int i = 0; i < R; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        if (x2 != x1) {
            if (x1 < x2) {
                fields[x1][y1].xr = true;
                fields[x2][y2].xl = true;
            }   else {
                fields[x1][y1].xl = true;
                fields[x2][y2].xr = true;
            }
        }   else {
            if (y1 < y2) {
                fields[x1][y1].yu = true;
                fields[x2][y2].yd = true;
            }   else {
                fields[x1][y1].yd = true;
                fields[x2][y2].yu = true;
            }
        }
    }
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cows.push_back({x, y});
        fields[x][y].cow = true;
    }
    vector<int> groups;
    for (int i = 0; i < cows.size(); i++) {
        if (fields[cows[i].first][cows[i].second].cow) {
            groups.push_back(floodfill(cows[i].first, cows[i].second));
        }
    }
    int ans = 0;
    for (int i = 0; i < groups.size(); i++) {
        for (int j = i+1; j < groups.size(); j++) {
            ans += groups[i] * groups[j];
        }
    }
    cout << ans;
}
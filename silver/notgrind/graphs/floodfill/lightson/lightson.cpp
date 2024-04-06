#include <bits/stdc++.h>

using namespace std;

struct Room {
    int redo = -1;
    bool visited, lit;
    vector<pair<int, int>> swithc;
};

vector<vector<Room>> barn;
int re = 1;

int floodfill(int r, int c) {
    if (!barn[r][c].lit) { return 0; }
    if (barn[r][c].redo == re) { return 0; }  //no change so far, so no need to do aynthign
    int count = !barn[r][c].visited;
    if (count != 0) {  //if we haven't visited this place before, light rooms up
        barn[r][c].visited = true;
        for (pair p : barn[r][c].swithc) {
            if (!barn[p.first][p.second].lit) {
                barn[p.first][p.second].lit = true;
                re++;
            }
        }
    }
    barn[r][c].redo = re;
    if (r != 0) { count += floodfill(r-1, c); }
    if (r != barn.size()-1) { count += floodfill(r+1, c); }
    if (c != 0) { count += floodfill(r, c-1); }
    if (c != barn.size()-1) { count += floodfill(r, c+1); }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    barn.resize(N, vector<Room>(N));
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        barn[x1][y1].swithc.push_back({x2, y2});
    }
    barn[0][0].lit = true;
    floodfill(0, 0);
    cout << re;
}
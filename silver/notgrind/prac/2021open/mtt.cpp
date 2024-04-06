#include <bits/stdc++.h>

using namespace std;
struct tt {
    int first, second;
    bool b;
    int visited;
};
vector<vector<vector<int>>> grids;
vector<vector<int>> grid(3, vector<int>(3));  //2 == M, 1 == O, 0 == none
tt maze[25][25];
int N;
int visited;
int most;
bool checkgrid() {
    cout << "hi" << "\n";
    bool works = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    for (int i = 0; i < 3; i++) {  // check rows, cols
        if (grid[i][0] == 2) {
            if (grid[i][1] == 1 && grid[i][2] == 1) { works = true; break; }
        }
        if (grid[i][2] == 2) {
            if (grid[i][1] == 1 && grid[i][0] == 1) { works = true; break; }
        }
        if (grid[0][i] == 2) {
            if (grid[1][i] == 1 && grid[2][i] == 1) { works = true; break; }
        }
        if (grid[2][i] == 2) {
            if (grid[1][i] == 1 && grid[0][i] == 1) { works = true; break; }
        }
    }
    if (grid[0][0] == 2) {
        if (grid[1][1] == 1 && grid[2][2] == 1) { works = true; }
    }
    if (grid[2][2] == 2) {
        if (grid[1][1] == 1 && grid[0][0] == 1) { works = true; }
    }
    if (grid[2][0] == 2) {
        if (grid[1][1] == 1 && grid[0][2] == 1) { works = true; }
    }
    if (grid[0][2] == 2) {
        if (grid[1][1] == 1 && grid[2][0] == 1) { works = true; }
    }
    if (!works) { return false; }
    for (int m = 0; m < grids.size(); m++) {
        bool same = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grids[m][i][j] != grid[i][j]) {
                    same = false;
                }
            }
        }
        if (same) { cout << "rip" << "\n"; return false; }
    }
    vector<vector<int>> add(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            add[i][j] = grid[i][j];
        }
    }
    grids.push_back(add);
    return true;
}
void floodfill(int r, int c) {
    cout << r << " " << c << "\n";
    bool before;
    if (maze[r][c].visited == 0) { visited++; }  //the idea is that visited counts how many overall squares the floodfill has been to. 
    maze[r][c].visited++; //how many times floodifll has been here- if more than 5, we don't really need to be here anymore
    if (maze[r][c].visited > 5) { maze[r][c].visited--; return; }
    if (visited == most) { maze[r][c].visited--; return; }
    int rc = maze[r][c].first; int cc = maze[r][c].second;
    if (rc < 3) {
        if (grid[rc][cc] == 0) {
            grid[rc][cc] = maze[r][c].b ? 2 : 1;
            if (checkgrid()) { return; }
        }   else { before = true; }
    }
    if (r + 1 != N && maze[r+1][c].first >= 0) {
        floodfill(r+1, c);
    }
    if (r - 1 != 0 && maze[r-1][c].first >= 0) {
        floodfill(r-1, c);
    }
    if (c + 1 != N && maze[r][c+1].first >= 0) {
        floodfill(r, c+1);
    }
    if (c - 1 != 0 && maze[r][c-1].first >= 0) {
        floodfill(r, c-1);
    }
    if (rc != 3 && !before) {
        grid[rc][cc] = 0;
    }
    visited--;
    maze[r][c].visited--; 
    //cant infinite loop. so overall its the order of those accessible that matters
}
int main() {
    cout << maze[0][0].first << "\n";
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    int sr, sc;
    most = N * N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            string sub = s.substr(j * 3, 3);
            if (sub[0] == '#') { maze[i][j].first = -1; maze[i][j].second = -1;  most--; }
            else if (sub[0] == 'B') { sr = i; sc = j; }
            else if (sub[0] == '.') { maze[i][j].first = 3; maze[i][j].second = 3; }
            else {
                if (sub[0] == 'M') { maze[i][j].b = true; }
                maze[i][j].first = sub[1] - '1';
                maze[i][j].second = sub[2] - '1';
            }
        }
    }
    floodfill(sr, sc);
    for (int k = 0; k < grids.size(); k++) {
        cout << "\n";
        for (int i = 0; i < grids[k].size(); i++) {
            for (int j = 0; j < grids[0][i].size(); j++) {
                cout << grids[0][i][j];
            }
            cout << "\n";
        }
    }

}
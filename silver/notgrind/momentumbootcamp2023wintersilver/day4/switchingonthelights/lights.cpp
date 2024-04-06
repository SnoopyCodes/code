#include <bits/stdc++.h>

using namespace std;
struct Room {
    int r, c;
    bool lit, vis;
    vector<Room> toggle;
};
vector<vector<Room>> barns;
int N;
int cnt = 1;
void light(int r, int c) {
    if (r == -1 || r == N || c == -1 || c == N) { return; }
    if (!barns[r][c].lit) { return; }  //if not lit leave
    cout << r << " " << c << "\n";
    if (barns[r][c].vis) { return; }  //if we visited already
    barns[r][c].vis = true;
    for (Room &x : barns[r][c].toggle) {
        if (barns[x.r][x.c].lit) { continue; }
        barns[x.r][x.c].lit = true;
        cnt++;
        bool possible = false;  //if we can visit this one immediately
        if (x.r != 0 && barns[x.r-1][x.c].vis) { possible = true; }
        else if (x.r != N-1 && barns[x.r+1][x.c].vis) { possible = true; }
        else if (x.c != 0 && barns[x.r][x.c-1].vis) { possible = true; }
        else if (x.c != N-1 && barns[x.r][x.c+1].vis) { possible = true; }
        cout << possible << " " << x.r << " " << x.c << "\n";
        if (possible) { light(x.r, x.c); }
    }
    light(r-1, c);
    light(r+1, c);
    light(r, c-1);
    light(r, c+1);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int M; cin >> N >> M;
    barns.resize(N, vector<Room>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            barns[i][j].r = i;
            barns[i][j].c = j;
        }
    }
    for (int i = 0; i < M; i++) {
        int r1, c1; cin >> r1 >> c1; r1--; c1--;
        int r2, c2; cin >> r2 >> c2; r2--; c2--; 
        barns[r1][c1].toggle.push_back(barns[r2][c2]);
    }
    
    barns[0][0].lit = true;
    light(0, 0);
    cout << barns[0][1].lit << "\n";
    cout << cnt << "\n";
}
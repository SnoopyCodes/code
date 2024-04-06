#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> grid;
vector<vector<bool>> visited;
map<int, int> sizes;
int absmax = 0;
int soloflood(int i, int j) {

}  //we want flood to just return the closest and stuff
int friendfill(int i, int j, int f1, int f2) {

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("multimoo.in", "r", stdin);
    //freopen("multimoo.out", "w", stdout);
    int N; cin >> N;
    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    //this is very challenging
    //indeed
    //start with one team
    //if we are adjacent to another team work with that team
    //can we just go down and to the right? thats not possible we have to check all 4 directions :c
    //after we run an "allied" we should run normally our other ally
    //how about we do 2: one for solo regions
    //and then we go for one with teams
    //how to do the one with teams?
    //start wiht 0 0 and work to adjacents
    //at adjacents friend adjacents
    //another flodfill
    //then run adjacent normally
    //so basically just brute force
}
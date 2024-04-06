#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> col;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("art.in", "r", stdin);
    //freopen("art.out", "w", stdout);
    cin >> N;
    col.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> col[i][j];
        }
    }
    //any color not shown could have been painted first
    //when is a color definitely used?
    //the idea of impossible comes from if a color's rectangle sits on top of another color's largest possible rectangle
    //so record for each color the largest possible rectangle
    //and record which colors overlap on it?
    //so it is needed to detect 
    //okay usaco guided it its uh prefix sums
    //oh you just assume its the smallest because duh
    //oh
    //okay
    //okay sure
    //
}
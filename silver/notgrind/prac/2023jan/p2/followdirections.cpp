#include <bits/stdc++.h>
#define ll long long

using namespace std;
using namespace std::chrono;

//if we do as said and only look at 
vector<vector<bool>> grid;  //if r true if d false
vector<vector<int>> cows;  //how many cows go to each square
vector<int> vcost;
vector<int> hcost;
int total = 0;
void comptotal() {
    total = 0;
    for (int i = 0; i < hcost.size(); i++) {
        total += grid[i][hcost.size()-1] * cows[i][hcost.size()-1] * vcost[i];  //if the grid on left goes right then add cows * cost
    }
    for (int i = 0; i < vcost.size(); i++) {
        total += !grid[vcost.size()-1][i] * cows[vcost.size()-1][i] * hcost[i];  //if grid on top goes down then add cows * cost
    }
}
void flood(int r, int c) {
    cows[r][c] = 1;
    if (r != 0 && !grid[r-1][c]) { cows[r][c] += cows[r-1][c]; }
    if (c != 0 && grid[r][c-1]) { cows[r][c] += cows[r][c-1]; }
    if (!grid[r][c] && r != grid.size()-1) { flood(r+1, c); }
    if (grid[r][c] && c != grid.size()-1) { flood(r, c+1); }
}

int main() {
    auto start = high_resolution_clock::now();

    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int N; cin >> N;
    vcost.resize(N);
    hcost.resize(N);
    cows.resize(N, vector<int>(N));
    grid.resize(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        string dir;
        int cost;
        cin >> dir >> cost;
        for (int j = 0; j < N; j++) {
            if (dir[j] == 'R') { grid[i][j] = true; }
        }
        vcost[i] = cost;
    }
    for (int i = 0; i < N; i++) {
        int cost;
        cin >> cost;
        hcost[i] = cost;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cows[i][j] = 1;
            if (i != 0 && !grid[i-1][j]) { cows[i][j] += cows[i-1][j]; }
            if (j != 0 && grid[i][j-1]) { cows[i][j] += cows[i][j-1]; }
        }
    }
    comptotal();

    cout << total << "\n";
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        grid[r][c] = !grid[r][c];
        if (r != N-1) { flood(r+1, c); }
        if (c != N-1) { flood(r, c+1); }
        comptotal();
        cout << total << "\n";
    }
//     auto stop = high_resolution_clock::now();
// auto duration = duration_cast<microseconds>(stop - start);
// cout << duration.count() << endl;
}
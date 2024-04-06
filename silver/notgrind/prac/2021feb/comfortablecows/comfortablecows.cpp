#include <bits/stdc++.h>
#define ll long long

using namespace std;
bool grid [3000][3000];
bool visited [3000][3000];
int added = 0;
bool comfy(int x, int y) {
    return grid[x+1][y] + grid[x-1][y] + grid[x][y-1] + grid[x][y+1] == 3;
}
void flood(int x, int y) {
    if (!grid[x][y]) { return; }
    if (comfy(x, y)) {
        if (!grid[x+1][y]) { grid[x+1][y] = true; flood(x+1, y); }
        else if (!grid[x-1][y]) { grid[x-1][y] = true; flood(x-1, y); }
        else if (!grid[x][y+1]) { grid[x][y+1] = true; flood(x, y+1); }
        else { grid[x][y-1] = true; flood(x, y-1); }
        added++;
    }
    if (comfy(x+1, y)) { flood(x+1, y); }
    if (comfy(x-1, y)) { flood(x-1, y); }
    if (comfy(x, y+1)) { flood(x, y+1); }
    if (comfy(x, y-1)) { flood(x, y-1); }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x += 1000, y += 1000;
        if (grid[x][y]) { cout << --added << "\n"; continue; }  //it has already been added before and therefore must be comfortable; also fn doesnt have to 
        //add another here so
        //if a cow is comfortable then we absolutely must fill in whatever other space is around it to make it uncomfortable
        grid[x][y] = true;
        flood(x, y);
        cout << added << "\n";
    }
}
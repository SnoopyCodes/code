#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, W; cin >> N >> W;
    //in this case our goal is to see if a certain value sum is possible
    //welp help
    vector<int> possible(N * 1000 + 1, W + 1);
    vector<array<int, 2>> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i][0] >> items[i][1];
    }
    
    //okay so how do we perform dp so that we can get the maximum possible?
    //if we say consider taking this card
    int mx = 0;
    possible[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int v = N * 1000; v >= 0; v--) {
            if (possible[v] == W + 1) { continue; }
            if (possible[v] + items[i][0] <= W) {
                possible[v + items[i][1]] = min(possible[v + items[i][1]], possible[v] + items[i][0]);
                mx = max(mx, v + items[i][1]);
            }
        }
    }
    cout << mx << "\n";
}
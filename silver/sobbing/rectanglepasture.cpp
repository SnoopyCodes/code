#include <bits/stdc++.h>

using namespace std;
bool cmp(array<int, 2> a1, array<int, 2> a2) {
    if (a1[1] == a2[1]) { return a1[0] < a2[0]; }
    return a1[1] < a2[1];
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //this is why i hate usaco
    //please never do this again
    //basically coord compression i guess
    int N; cin >> N;
    vector<array<int, 2>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i][0] >> cows[i][1];
    }
    sort(cows.begin(), cows.end());
    for (int i = 0; i < N; i++) { cows[i][0] = i; }
    sort(cows.begin(), cows.end(), cmp);
    for (int i = 0; i < N; i++) { cows[i][1] = i; }
    vector<vector<int>> pasture(N, vector<int>(N));
    vector<vector<int>> pfx(N + 1, vector<int>(N + 1));
    for (int i = 0; i < N; i++) {
        pasture[cows[i][0]][cows[i][1]]++;
    }
    //all x-coords are distinct, y-coords also
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            pfx[i][j] = pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1] + pasture[i-1][j-1];
            // cout << pasture[i-1][j-1] << " ";
        }
        // cout << "\n";
    }
    // cout << "\n";
    // for (int i = 1; i < N + 1; i++) {
    //     for (int j = 1; j < N + 1; j++) {
    //         cout << pfx[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    long long ans = 0;
    //essentially, because all points have distinct x-coords and y-coords, 
    //we can get all useful rectangles-- everything else will give the same results
    auto get_pref_sum = [&](array<int, 2> p1, array<int, 2> p2) {
        //p2 is more left and down than p1
        return pfx[p2[0]][p2[1]] - pfx[p1[0]-1][p2[1]] - pfx[p2[0]][p1[1]-1] + pfx[p1[0]-1][p1[1]-1];
    };
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j <= i; j++) {
            ans += (get_pref_sum({1, j},{min(cows[i-1][0], cows[j-1][0]) + 1, i}))
                    * (get_pref_sum({max(cows[i-1][0], cows[j-1][0]) + 1, j},{N, i}));
        }
    }
    cout << ans + 1 << "\n";
}
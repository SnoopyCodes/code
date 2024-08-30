#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("cowpatability.in", "r", stdin);
    //freopen("cowpatability.out", "w", stdout);
    //we should try to like combine stuff
    //bind everything on one color to like
    //the xth of the first element on there
    //everything in there are combined
    //first try it with 1
    //then 2 i guess
    //what the hell is a PIE
    //count everything added up
    //count the intersections?
    //ok then do the compatible ones
    int N; cin >> N;
    vector<array<int, 5>> faves(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> faves[i][j];
        }
        sort(faves.begin(), faves.end());
    }
    map<vector<int>, int> m;  //count the number of these of size 3
    for (int i = 0; i < N; i++) {
        
    }

}
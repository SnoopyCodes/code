#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> list(N);
    ll total = 0;
    for (int i = 0; i < N; i++) {
        cin >> list[i];
        total += list[i];
    }
    //each player has a score
    //each player at every turn gets 2 choices
    //assume that we shall take the maximum
    //obviously taking the maximum does not work
    //i dont think we can define playing optimally by saying theres a 
    //least pointdiff between the two
    //our dp probably starts at <0,0> at [0][N] for starting and ending point
    //okay so its basically we can never find a globally optimal substructure 
    //by iterating forward; instead we must go backward
    //
    vector<vector<ll>> scores(N, vector<ll>(N));
    for (int l = N - 1; l >= 0; l--) {
        for (int r = l; r < N; r++) {
            if (l == r) { scores[l][r] = list[l]; continue; }
            //we can select l
            ll leftScore = list[l] - scores[l+1][r];
            ll rightScore = list[r] - scores[l][r-1];
            scores[l][r] = max(leftScore, rightScore);
        }
    }
    cout << (scores[0][N-1] + total) / 2 << "\n";
}
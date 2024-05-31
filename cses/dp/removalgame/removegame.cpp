#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> list(N);
    for (int i = 0; i < N; i++) {
        cin >> list[i];
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
    ll best = 0;
    vector<vector<array<ll, 2>>> scores(N + 1, vector<array<ll, 2>>(N+1));
    //
    cout << best << "\n";
}
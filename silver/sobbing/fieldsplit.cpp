#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<array<int, 2>> cows;
int N;
int ymin, ymax;
ll solve() {
    ll smol = LONG_LONG_MAX;
    vector<int> back(N);  //if we move backwards, what size y do we get
    ymin = cows[N - 1][1], ymax = cows[N - 1][1];
    for (int i = N - 2; i > 0; i--) {
        ymin = min(ymin, cows[i][1]);
        ymax = max(ymax, cows[i][1]);
        back[i] = ymax - ymin;
    }

    int xs = cows[0][0]; //starting s
    ymin = cows[0][1], ymax = cows[0][1];
    for (int i = 0; i < N - 1; i++) {
        ymax = max(ymax, cows[i][1]);
        ymin = min(ymin, cows[i][1]);
        ll r1 = (ll(cows[i][0] - xs)) * (ymax - ymin);
        ll r2 = (ll(cows[N - 1][0] - cows[i+1][0])) * back[i+1];
        smol = min(smol, r1 + r2);
    }
    //what is happening
    return smol;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    cin >> N;
    cows.resize(N);
    ymin = 1e9, ymax = 0;
    for (int i = 0; i < N; i++) {
        cin >> cows[i][0] >> cows[i][1];
        ymin = min(ymin, cows[i][1]);
        ymax = max(ymax, cows[i][1]);
    }
    sort(cows.begin(), cows.end());
    ll init = (ll)(cows[N - 1][0] - cows[0][0]) * (ymax - ymin);
    //what is the most optimal way to split it?
    //there needs to be like a blank in the middle or something
    //i think we iterate through the "blank" for both x and y
    //that should probably give us an answer
    ll smol = solve();
    for (int i = 0; i < N; i++) {
        swap(cows[i][0], cows[i][1]);
    }
    sort(cows.begin(), cows.end());
    smol = min(smol, solve());
    //the issue then is that smol isn't being compared or somethnig
    cout << init - smol << "\n";
}
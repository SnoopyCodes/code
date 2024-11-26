#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int L, N, fspeed, bspeed; cin >> L >> N >> fspeed >> bspeed;
    vector<array<int, 2>> yum(N);
    for (int i = 0; i < N; i++) {
        cin >> yum[i][0] >> yum[i][1];
    }

    vector<bool> stop(N);
    int large_back = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (large_back < yum[i][1]) { stop[i] = true; large_back = yum[i][1]; }
    }

    ll yum_score = 0;
    ll stopped = 0;  //how long bessie has stopped

    for (int i = 0; i < N; i++) {
        if (!stop[i]) { continue; }
        ll t = stopped + yum[i][0] * (ll) bspeed;  //time it takes to get here
        ll catchup = (ll) yum[i][0] * fspeed - t;
        yum_score += catchup * yum[i][1];
        stopped += catchup;
    }
    cout << yum_score << "\n";
}
#include <bits/stdc++.h>

using namespace std;
vector<int> weights;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, X; cin >> N >> X;
    weights.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    //define our dp to be [bitmask] holding {rides, weight thus far}
    //yee haw
    vector<array<int, 2>> rides(1 << N, {INT_MAX, -1});
    rides[0] = {1, 0};
    for (int mask = 0; mask < 1 << N; mask++) {
        for (int b = 0; b < N; b++) {
            if (!(mask & (1 << b))) { continue; }
            int from = mask ^ 1 << b;
            //ok rip
            auto change = rides[from];
            if (change[1] + weights[b] > X) { change[1] = weights[b]; change[0]++; }
            else { change[1] += weights[b]; }
            rides[mask] = min(rides[mask], change);
        }
    }
    cout << rides[(1 << N) - 1][0];
}
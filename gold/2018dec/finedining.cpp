#include <bits/stdc++.h>

using namespace std;
vector<vector<array<int, 2>>> pastures;
vector<int> yums;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    int N, M, K; cin >> N >> M >> K;
    pastures.resize(N);
    yums.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int a, b, t; cin >> a >> b >> t; a--; b--;
        pastures[a].push_back({b, t});
        pastures[b].push_back({a, t});
    }
    for (int i = 0; i < K; i++) {
        int v, val; cin >> v >> val; v--;
        yums[v] = max(yums[v], val);
    }
    priority_queue<array<int, 2>> closest;
    vector<int> dists(N, 1e9+1);
    dists[N-1] = 0;
    closest.push({0, N-1});
    while (!closest.empty()) {
        int close = closest.top()[1];
        int dist = -closest.top()[0];
        closest.pop();
        if (dists[close] != dist) { continue; }
        for (auto const&[near, direct] : pastures[close]) {
            if (direct + dist < dists[near]) {
                dists[near] = direct + dist;
                closest.push({-(direct + dist), near});
            }
        }
    }
    vector<int> origin = dists;
    priority_queue<array<int, 3>> powered;
    vector<int> reached(N, -1);  //the power we reach with
    for (int i = 0; i < N; i++) {
        if (yums[i] == -1) { continue; }
        reached[i] = yums[i];
        powered.push({yums[i], i, yums[i]});  //max heap this time
    }
    while (!powered.empty()) {
        int v = powered.top()[1];
        int powuh = powered.top()[0];
        int src = powered.top()[2];
        powered.pop();
        if (reached[v] != powuh) { continue; }
        for (auto const&[near, direct] : pastures[v]) {
            if (src - (direct + dists[v] - origin[near]) > reached[near]) {
                dists[near] = direct + dists[v];
                reached[near] = src - (direct + dists[v] - origin[near]);
                powered.push({reached[near], near, src});
            }
        }
    }
    for (int i = 0; i < N - 1; i++) {
        cout << (reached[i] >= 0) << "\n";
    }
}
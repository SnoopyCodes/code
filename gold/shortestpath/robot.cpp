#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<vector<array<int, 3>>> cross;  //to, color, cost
vector<ll> dists;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    cross.resize(N);
    dists.resize(N, 1e18);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        int c, p; cin >> c >> p;
        cross[a].push_back({b, c, p});
        cross[b].push_back({a, c, p});
    }
    //dijkstras
    //obviously include the source and if we changed it and stuff
    //uhhhh wait
    //yeah don't ever double count this source bruh
    //that'd be stupid
    priority_queue<array<ll, 3>> pq;
    dists[0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        ll d = -pq.top()[0];
        int u = pq.top()[1];
        int changed = pq.top()[2];
        if (d != dists[u]) { continue; }
        map<int, vector<array<int, 2>>> cols;
        for (auto const&[v, c, p] : cross[u]) {
            if (v == changed) { continue; }
            cols[c].push_back({v, p});
        }
        for (auto const&[col, dests] : cols) {

        }
    }
}
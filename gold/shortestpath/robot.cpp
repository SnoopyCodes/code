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
    //run a modified dijkstras.
    //if we arrive at a crossing with a certain color wait it doesnt matter does it
    //the cost to move somewhere is just like
    //whether we should change this crossing or all the other crossings
    //damn okay the trouble is that if we modify an edge to something else 
    //then that edge shouldnt be considered as a like another thing
    priority_queue<array<ll, 2>> pq; //its time to suffer
    pq.push({0, 0});
    dists[0] = 0;
    while (!pq.empty()) {
        ll dist = -pq.top()[0], c = pq.top()[1];
        pq.pop();
        if (dist != dists[c]) { continue; }
        cout << c << " " << dists[c] << "\n";
        map<int, vector<array<int, 2>>> m; //color, to, dist
        for (auto const&[to, col, price] : cross[c]) {
            m[col].push_back({to, price});
        }
        for(auto const&[col, dests] : m) {
            ll total = 0;
            for (auto x : dests) {
                total += x[1];
            }
            for (auto x : dests) {
                ll ndist = min(ll(x[1]), total - x[1]);
                if (ndist + dist < dists[x[0]]) {
                    dists[x[0]] = ndist + dist;
                    pq.push({-dists[x[0]], x[0]});
                }
            }
        }
    }
    if (dists[N-1] == 1e18) { cout << -1 << "\n"; }
    else{ cout << dists[N - 1] << "\n"; }
}
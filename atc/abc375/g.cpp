#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<array<int, 3>> edges(M);
    vector<vector<array<int, 2>>> cities(N);
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        cities[u].push_back({v, d});
        cities[v].push_back({u, d});
        edges[i] = {u, v, d};
    }
    vector<ll> dist_beg(N, 1e18);
    vector<ll> hit_beg(N);
    dist_beg[0] = 0;
    const int MOD = 998244353;
    priority_queue<array<ll, 3>> pq;
    pq.push({0, 0, 1});
    while (!pq.empty()) {
        ll d = -pq.top()[0];
        int u = pq.top()[1];
        if (d != dist_beg[u]) { pq.pop(); continue; }
        hit_beg[u] = (hit_beg[u] + pq.top()[2]) % MOD;
        pq.pop();
        if (!pq.empty() && -pq.top()[0] == d) { continue; }
        for (auto const&[v, dir] : cities[u]) {
            if (dist_beg[v] >= dir + d) {
                dist_beg[v] = dir + d;
                pq.push({-dist_beg[v], v, hit_beg[u]});
            }
        }
    }
    //idk rlly how to lambda this so ill just copy paste xd
    vector<ll> dist_end(N, 1e18);
    vector<ll> hit_end(N);
    dist_end[N - 1] = 0;
    pq.push({0, N - 1, 1});
    while (!pq.empty()) {
        ll d = -pq.top()[0];
        int u = pq.top()[1];
        if (d != dist_end[u]) { pq.pop(); continue; }
        hit_end[u] = (hit_end[u] + pq.top()[2]) % MOD;
        pq.pop();
        if (!pq.empty() && -pq.top()[0] == d) { continue; }
        for (auto const&[v, dir] : cities[u]) {
            if (dist_end[v] >= dir + d) {
                dist_end[v] = dir + d;
                pq.push({-dist_end[v], v, hit_end[u]});
            }
        }
    }
    ll def_dist = dist_beg[N - 1];
    for (int i = 0; i < M; i++) {
        auto &[u, v, d] = edges[i];
        //we need to see if these nodes lie on shortest path from 1 to N
        if (dist_beg[u] + dist_end[v] + d != def_dist
        && dist_beg[v] + dist_end[u] + d != def_dist) { cout << "No" << "\n"; continue; }
        if (dist_beg[u] + dist_end[v] + d != def_dist) { swap(u, v); }
        //so these do lie on a shortest path from 1 to N
        //if shortest paths to v are more than shortest paths to u then it's not different
        if (hit_beg[u] != hit_beg[v]
        || (hit_end[v] * hit_beg[v]) % MOD != hit_beg[N - 1]) { cout << "No" << "\n"; }
        else { cout << "Yes" << "\n"; }
        //ok so there might be like another shortest path..
        //ways from v to end is hit_end
        //total ways to end is hit_beg[end]
        //hit_beg[u] == hit_beg[v]
        //there are some shortest paths from end to v, and start to v
        //if these multiplied together comprise all shortest paths, then it will change
        //
        
    }
}
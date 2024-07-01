#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<array<int, 2>>> flights;  //<dist, index>
vector<ll> disu;
vector<ll> ndisu;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    flights.resize(N);
    disu.resize(N, LONG_LONG_MAX);
    ndisu.resize(N, LONG_LONG_MAX);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        flights[a].push_back({c, b});
    }
    priority_queue<array<ll, 3>> pq; //< -dist, index, used >
    disu[0] = 0;
    ndisu[0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        ll v = pq.top()[1];
        bool use = pq.top()[2];
        ll dist = -pq.top()[0];
        pq.pop();
        if (!use && dist != ndisu[v]) { continue; }
        if (use && dist != disu[v]) { continue; }
        for (auto adj : flights[v]) {
            if (use && disu[adj[1]] > dist + adj[0]) {
                disu[adj[1]] = dist + adj[0];
                pq.push({-disu[adj[1]], adj[1], use});
            }
            if (!use && ndisu[adj[1]] > dist + adj[0]) {
                ndisu[adj[1]] = dist + adj[0];
                pq.push({-ndisu[adj[1]], adj[1], use});
            }
            if (!use && disu[adj[1]] > dist + adj[0] / 2) {
                disu[adj[1]] = dist + adj[0] / 2;
                pq.push({-disu[adj[1]], adj[1], !use});
            }
        }
    }
    //oh this does not quite work bruh
    //we actually need to use booleans i cant bruh
    cout << disu[N-1];
}
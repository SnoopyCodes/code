#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<array<int, 2>>> graph;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    graph.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b, d; cin >> a >> b >> d; a--; b--;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    vector<ll> dists(N, 1e18);
    priority_queue<array<ll, 2>> pq;
    vector<int> last(N, -1);
    dists[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        ll dist = -pq.top()[0];
        int v = pq.top()[1];
        pq.pop();
        if (dist != dists[v]) { continue; }
        for (auto const& [u, d] : graph[v]) {
            if (dists[u] > d + dist) {
                dists[u] = d + dist;
                pq.push({-dists[u], u});
                last[u] = v;
            }
        }
    }
    vector<int> path;
    int x = N - 1;
    while (x != -1) {
        path.push_back(x);
        x = last[x];
    }
    if (path.size() == 1) { cout << -1 << "\n"; }
    else {
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout << path[i]+1;
            if (i != path.size() - 1) { cout << " "; }
        }
        cout << "\n";
    }
    // in this dijkstra we need to store the last one we went to
    
}
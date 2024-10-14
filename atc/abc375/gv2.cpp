#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<array<int, 3>>> cities(N);
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        cities[u].push_back({v, d, i});
        cities[v].push_back({u, d, i});
    }

    vector<ll> dist_beg(N, 1e18);
    dist_beg[0] = 0;
    priority_queue<array<ll, 2>> pq;
    vector<int> order;
    vector<vector<array<int, 2>>> optimal(N);
    pq.push({0, 0});
    while (!pq.empty()) {
        ll d = -pq.top()[0];
        int u = pq.top()[1];
        pq.pop();
        if (d != dist_beg[u]) { continue; }
        order.push_back(u);
        for (auto const&[v, dir, i] : cities[u]) {
            if (dist_beg[v] > dir + d) {
                dist_beg[v] = dir + d;
                pq.push({-dist_beg[v], v});
            }
        }
    }

    pq.push({0, N - 1});
    vector<bool> visited(N);
    while (!pq.empty()) {
        ll d = -pq.top()[0];
        int u = pq.top()[1];
        pq.pop();
        for (auto const&[v, dir, i] : cities[u]) {
            if (dist_beg[v] + dir + d == dist_beg[N - 1]) {
                optimal[v].push_back({u, i});
                if (!visited[v]) {
                    pq.push({-(d + dir), v});
                    visited[v] = true;
                }
            }
        }
    }

    vector<bool> ans(M);
    set<int> s;
    for (int i = 0; i < order.size(); i++) {
        if (s.find(order[i]) != s.end()) { s.erase(order[i]); }
        if (optimal[order[i]].size() == 1 && s.empty()) { ans[optimal[order[i]][0][1]] = true; }
        for (auto const&[v, j] : optimal[order[i]]) {
            s.insert(v);
        }
    }
    
    for (int i = 0; i < M; i++) {
        if (ans[i]) { cout << "Yes" << "\n"; }
        else { cout << "No" << "\n"; }
    }
}
#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
#define pq priority_queue

using namespace std;

void solve() {
    int N; cin >> N;
    int S1, S2; cin >> S1 >> S2; S1--; S2--;
    //always a path
    //if there are edges that are the same
    //2d dijkstras ;_;
    set<arr<int, 2>> e;
    vec<bool> ep(N);
    vec<vec<int>> g_one(N), g_two(N);
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (u > v) { swap(u, v); }
        e.insert({u, v});
        g_one[u].push_back(v), g_one[v].push_back(u);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (u > v) { swap(u, v); }
        if (e.count({u, v})) {
            ep[u] = ep[v] = true;
        }
        g_two[u].push_back(v);
        g_two[v].push_back(u);
    }
    vec<vec<int>> dist(N, vec<int>(N, 1e9));
    dist[S1][S2] = 0;
    pq<arr<int, 3>> close;
    close.push({0, S1, S2});
    while (!close.empty()) {
        auto [d, u1, u2] = close.top(); close.pop();
        d = -d;
        if (d != dist[u1][u2]) { continue; }
        for (int v1 : g_one[u1]) {
            for (int v2 : g_two[u2]) {
                int c = abs(v1 - v2);
                if (d + c < dist[v1][v2]) {
                    dist[v1][v2] = d + c;
                    close.push({-dist[v1][v2], v1, v2});
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
        if (ep[i]) {
            ans = min(ans, dist[i][i]);
        }
    }
    if (ans == 1e9) { cout << -1 << "\n"; }
    else { cout << ans << "\n"; }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
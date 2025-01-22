#include <bits/stdc++.h>
#define vec vector
#define arr array
#define pb push_back
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M, Q; cin >> N >> M >> Q;
    
    vec<vec<arr<int, 2>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    //O((N + M) log max W) per query
    while (Q--) {
        int U, V, K; cin >> U >> V >> K; U--; V--;
        int s = 0, e = 1e9 + 1;
        while (s + 1 < e) {
            int m = (s + e) / 2;
            deque<int> q;
            vec<int> dist(N, N);
            dist[U] = 0;
            q.pb(U);
            while (!q.empty()) {
                int u = q.front(); q.pop_front();
                for (auto [v, w] : G[u]) {
                    if (w <= m) {
                        if (dist[u] < dist[v]) {
                            dist[v] = dist[u];
                            q.push_front(v);
                        }
                    }   else {
                        if (dist[u] + 1 < dist[v]) {
                            dist[v] = dist[u] + 1;
                            q.pb(v);
                        }
                    }
                }
        }
        if (dist[V] < K) { e = m; }
        else { s = m; }
    }
    cout << e << "\n";
    }
}
#include <bits/stdc++.h>
#define vec vector
#define arr array
using namespace std;

void solve() {
    //editorial problem lmfao
    int N, M, Q; cin >> N >> M >> Q;
    //find if kth max <= x
    //split into 0-1 bfs
    //suppose that the shortest path from u to v dist >= k
    //then it must be higher than this
    //otherwise it is lower
    //okay
    //dist[k][i][j] = shortest pa th where first k smallest edges are set to 0
    //then it is possible to perform binary search
    //this is a very interesting idea application wtf
    //
    vec<vec<vec<int>>> dist(M + 1, vec<vec<int>>(N, vec<int>(N, 1e9)));
    for (int i = 0; i < N; i++) {
        dist[0][i][i] = 0;
    }
    vec<arr<int, 3>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        edges[i] = {u, v, w};
        dist[0][u][v] = dist[0][v][u] = 1;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[0][i][j] = min(dist[0][i][j], dist[0][i][k] + dist[0][k][j]);
            }
        }
    }

    sort(edges.begin(), edges.end(), [](auto u, auto v) { return u[2] < v[2]; });
    for (int e = 0; e < M; e++) {
        auto [u, v, w] = edges[e];
        //u, v = good stuff i think
        //set this edge to become 0 and fix stuff from there
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[e+1][i][j] = min(dist[e][i][j], dist[e][i][u] + dist[e][v][j]);
                dist[e+1][i][j] = min(dist[e+1][i][j], dist[e][i][v] + dist[e][u][j]);
            }
        }
    }

    for (int q = 0; q < Q; q++) {
        int u, v, k; cin >> u >> v >> k; u--; v--;
        int s = 0, e = M;
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (dist[m][u][v] < k) { e = m; }
            else { s = m; }
        }
        cout << edges[s][2] << " \n"[q == Q - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
#include <bits/stdc++.h>
#define vec vector
#define arr array
using namespace std;

struct DSU {
    int N;
    vector<int> root, sizes;
    void init(int _N) {
        int N = _N;
        root.resize(N);
        sizes.resize(N, 1);
        for (int i = 0; i < N; i++) { root[i] = i; }
    }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool merge(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (sizes[ru] < sizes[rv]) { swap(ru, rv); }
        sizes[ru] += sizes[rv];
        root[rv] = ru;
        return true;
    }
};

void solve() {
    //editorial problem lmfao
    int N, M, Q; cin >> N >> M >> Q;
    DSU con; con.init(N);
    //find if kth max <= x
    //split into 0-1 bfs
    //suppose that the shortest path from u to v dist >= k
    //then it must be higher than this
    //otherwise it is lower
    //okay
    //dist[k][i][j] = shortest path where first k smallest edges are set to 0
    //then it is possible to perform binary search
    //this is a very interesting idea application wtf
    //very hard
    
    //there is a way without binary search AND ONLINE QUERIES, seen by ugly2333
    //simply create a vector for each pair storing the mins
    //literal brute force suffices

    //ok now then how do we figure out hard version
    //we require n^3
    //so *consider when an edge actually matters*
    //due to 0-1 bfs, connecting 0 connected segments does nothing

    vec<vec<vec<int>>> dist(N + 1, vec<vec<int>>(N, vec<int>(N, 1e9)));
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
    vec<int> val(N);
    int cur = 0;
    for (int e = 0; e < M; e++) {
        auto [u, v, w] = edges[e];
        //u, v = good stuff i think
        //set this edge to become 0 and fix stuff from there
        if (con.merge(u, v)) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[cur+1][i][j] = min(dist[cur][i][j], dist[cur][i][u] + dist[cur][v][j]);
                    dist[cur+1][i][j] = min(dist[cur+1][i][j], dist[cur][i][v] + dist[cur][u][j]);
                }
            }
            val[cur++] = w;
        }
    }

    for (int q = 0; q < Q; q++) {
        int u, v, k; cin >> u >> v >> k; u--; v--;
        int s = 0, e = N;
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (dist[m][u][v] < k) { e = m; }
            else { s = m; }
        }
        cout << val[s] << " \n"[q == Q - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
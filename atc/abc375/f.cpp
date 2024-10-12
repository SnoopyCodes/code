#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<ll>> dists(N, vector<ll>(N, 1e18));
    for (int i = 0; i < N; i++) {
        dists[i][i] = 0;
    }
    //hm
    //we can try floyd warshall first
    //but it is not viable to brute force floyd warshall each time
    //what if we like run a dijkstras from the 2 that are closed
    //what does this do
    //what if we reverse the queries
    //does that make it easier
    vector<array<int, 4>> edges;    
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        edges.push_back({u, v, d, 1});
    }
    vector<array<int, 3>> queries;
    for (int i = 0; i < Q; i++) {
        int a, b, c; cin >> a >> b;
        b--;
        if (a == 2) { cin >> c; c--; }
        else { edges[b][3] = 0; }
        queries.push_back({a, b, c});
    }
    for (int i = 0; i < M; i++) {
        if (edges[i][3]) {
            dists[edges[i][0]][edges[i][1]] = edges[i][2];
            dists[edges[i][1]][edges[i][0]] = edges[i][2];
        }
    }
    //FLOYD WARSHALL MY GOAT RAAAAAAAAAAAAAAAAAAHHHHHHHHHH
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (dists[i][j] > dists[i][k] + dists[k][j]) {
                    dists[i][j] = dists[i][k] + dists[k][j];
                    dists[j][i] = dists[i][j];
                }
            }
        }
    }
    vector<ll> answers;
    for (int i = Q - 1; i > -1; i--) {
        if (queries[i][0] == 2) {
            int u = queries[i][1], v = queries[i][2];
            ll dist = dists[u][v];
            if (dist == 1e18) { dist = -1; }
            answers.push_back(dist);
        }   else {
            int e = queries[i][1];
            int u = edges[e][0], v = edges[e][1], d = edges[e][2];
            dists[u][v] = min(dists[u][v], (ll) d);
            dists[v][u] = dists[u][v];
            for (int x : {u, v}) {
                for (int i = 0; i < N; i++) {
                    for (int j = i + 1; j < N; j++) {
                        if (dists[i][j] > dists[i][x] + dists[x][j]) {
                            dists[i][j] = dists[i][x] + dists[x][j];
                            dists[j][i] = dists[i][j];
                        }
                    }
                }
            }
        }
    }
    for (int i = answers.size() - 1; i > -1; i--) {
        cout << answers[i] << "\n";
    }
}
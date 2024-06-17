#include <bits/stdc++.h>

using namespace std;
//implement BOTH kruskals and prims
vector<array<int, 3>> edges;
vector<int> dsu;
int find(int v) {
    if (dsu[v] != v) {
        dsu[v] = find(dsu[v]);
    }
    return dsu[v];
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (rand() % 2) {
        dsu[u] = v;
    }   else {
        dsu[v] = u;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    
    edges.resize(M);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        edges[i][1] = a, edges[i][2] = b, edges[i][0] = c;
    }
    dsu.resize(N);
    for (int i = 0; i < N; i++) {
        dsu[i] = i;
    }
    sort(edges.begin(), edges.end());
    long long cost = 0;
    for (int i = 0; i < M; i++) {
        if (find(edges[i][1]) == find(edges[i][2])) { continue; }
        cost += edges[i][0];
        merge(edges[i][1], edges[i][2]);
    }
    for (int i = 1; i < N; i++) {
        if (find(i) != find(0)) {
            cout << "IMPOSSIBLE" << "\n"; return 0;
        }
    }
    cout << cost << "\n";
}
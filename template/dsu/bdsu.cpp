#include <bits/stdc++.h>

using namespace std;

vector<int> dsu;

int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) { return; }
    if (rand()) { dsu[u] = v; }
    else { dsu[v] = u; }
}
//to initialize:
//dsu.resize(N);
//for (int i = 0; i < N; i++) {
//  dsu[i] = i;
//}
//doesnt track component sizes or anything, just merge stuff

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    dsu.resize(N);
    for (int i = 0; i < N; i++) {
        dsu[i] = i;
    }
    for (int i = 0; i < Q; i++) {
        int t, u, v; cin >> t >> u >> v;
        if (t) {
            cout << (find(u) == find(v)) << "\n";
        }   else {
            merge(u, v);
        }
    }
}
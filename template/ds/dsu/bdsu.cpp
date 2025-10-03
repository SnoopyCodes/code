#include <bits/stdc++.h>

using namespace std;
vector<int> dsu;
//O(n lg n / lg lg n)
//~O(n * 4.29) ~ O(n) (trust)
void init(int N) { dsu.resize(N); while (N--) dsu[N] = N; }
int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) { return; }
    if (rand() & 1) { swap(u, v); }
    dsu[v] = u;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    init(N);
    for (int i = 0; i < Q; i++) {
        int t, u, v; cin >> t >> u >> v;
        if (t) {
            cout << (find(u) == find(v)) << "\n";
        }   else {
            unite(u, v);
        }
    }
}
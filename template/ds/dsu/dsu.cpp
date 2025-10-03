#include <bits/stdc++.h>

using namespace std;
struct DSU {
    int N;
    vector<int> par, size;
    DSU(int _N):N(_N), par(N), size(N, 1)
    { iota(par.begin(), par.end(), 0); }
    int find(int u) {
        if (par[u] != u) { par[u] = find(par[u]); }
        return par[u];
    }
    bool unite(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (size[ru] < size[rv]) { swap(ru, rv); }
        size[ru] += size[rv];
        par[rv] = ru;
        N--;
        return true;
    }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    DSU cc(N);
    for (int i = 0; i < Q; i++) {
        int t, u, v; cin >> t >> u >> v;
        if (t) {
            cout << (cc.find(u) == cc.find(v)) << "\n";
        }   else {
            cc.unite(u, v);
        }
    }
}
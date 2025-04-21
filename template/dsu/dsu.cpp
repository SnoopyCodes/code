#include <bits/stdc++.h>

using namespace std;
struct DSU {
    int N;
    vector<int> root, size;
    DSU(int _N):N(_N), root(N), size(N, 1)
    { iota(root.begin(), root.end(), 0); }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool merge(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (size[ru] < size[rv]) { swap(ru, rv); }
        size[ru] += size[rv];
        root[rv] = ru;
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
            cc.merge(u, v);
        }
    }
}
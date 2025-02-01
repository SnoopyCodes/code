#include <bits/stdc++.h>

using namespace std;
struct DSU {
    int N;
    vector<int> root, size;
    void init(int _N) {
        int N = _N;
        root.resize(N);
        size.resize(N, 1);
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
        if (size[ru] < size[rv]) { swap(ru, rv); }
        size[ru] += size[rv];
        root[rv] = ru;
        return true;
    }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    DSU cc; cc.init(N);
    for (int i = 0; i < Q; i++) {
        int t, u, v; cin >> t >> u >> v;
        if (t) {
            cout << (cc.find(u) == cc.find(v)) << "\n";
        }   else {
            cc.merge(u, v);
        }
    }
}
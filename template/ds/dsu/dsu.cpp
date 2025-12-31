#include <bits/stdc++.h>

using namespace std;
struct DSU {
    int N;
    vector<int> p, s;
    DSU(int n):N(n), p(N), s(N, 1) { while (n--) p[n] = n; }
    int find(int u) {
        if (p[u] != u) { p[u] = find(p[u]); }
        return p[u];
    }
    bool unite(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) { return false; }
        if (s[ru] < s[rv]) { swap(ru, rv); }
        s[ru] += s[rv];
        p[rv] = ru;
        return N--;
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
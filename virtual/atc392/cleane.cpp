#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

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
        if (ru > rv) { swap(ru, rv); }
        size[ru] += size[rv];
        root[rv] = ru;
        return true;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    int comps = N;
    vec<arr<int, 3>> extra;
    DSU cc; cc.init(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (!cc.merge(u, v)) {
            extra.push_back({u, v, i});
        }   else {
            comps--;
        }
    }
    cout << comps - 1 << endl;
    set<int> active;
    for (int i = 0; i < N; i++) {
        if (cc.root[i] != i) { continue; }
        active.insert(i);
    }
    for (auto [u, z, e] : extra) {
        if (active.size() == 1) { break; }
        active.erase(cc.find(u));
        int v = *active.begin();
        cout << e + 1 << " " << u + 1 << " " << v + 1 << "\n";
        cc.merge(u, v);
        active.erase(active.begin());
        active.insert(cc.find(u));
    }
}
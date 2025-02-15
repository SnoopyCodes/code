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
    vec<vec<int>> extra;
    void init(int _N) {
        int N = _N;
        root.resize(N);
        size.resize(N, 1);
        extra.resize(N);
        for (int i = 0; i < N; i++) { root[i] = i; }
    }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool merge(int u, int v, int e) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) {
            extra[ru].push_back(e);
            return false;
        }
        //wait we have root compression no one cares
        //always push left
        if (ru > rv) { swap(ru, rv); }
        for (int x : extra[rv]) { extra[ru].push_back(x); }
        size[ru] += size[rv];
        root[rv] = ru;
        return true;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vec<arr<int, 2>> edges(M);
    int comps = N;
    DSU cc; cc.init(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        edges[i] = {u, v};
        comps -= cc.merge(u, v, i);
    }
    cout << comps - 1 << endl;
    set<int> need, has;
    for (int i = 0; i < N; i++) {
        if (cc.root[i] != i) { continue; }
        if (cc.extra[i].size()) { has.insert(i); }
        else { need.insert(i); }
    }
    while (need.size() + has.size() > 1) {
        int v;
        if (need.empty()) {
            v = *has.begin();
            has.erase(has.begin());
        }   else {
            v = *need.begin();
            need.erase(need.begin());
        }
        int u = *has.begin();
        has.erase(has.begin());
        int e = cc.extra[u].back();
        cc.extra[u].pop_back();
        cout << e + 1 << " ";
        cout << edges[e][0] + 1 << " " << v + 1 << "\n";
        cc.merge(u, v, -1);
        if (cc.extra[cc.find(u)].size()) { has.insert(cc.find(u)); }
        else { need.insert(cc.find(u)); }
    }
}
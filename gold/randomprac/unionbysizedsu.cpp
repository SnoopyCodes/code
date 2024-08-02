#include <bits/stdc++.h>

using namespace std;
struct DSU {
    int N;
    vector<int> par, sz;
    DSU(int siz) {
        N = siz;
        par = vector<int>(N);
        for (int i = 0; i < N; i++) { par[i] = i; }
        sz = vector<int>(N, 1);
    }
    int find(int v) {
        if (par[v] < 0) { return v; }
        par[v] = find(par[v]);
        return par[v];
    }
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) { return; }
        if (sz[v] > sz[u]) {  //v-comp size > u-comp size
            sz[v] += sz[u];
            par[u] = v;
        }   else { 
            sz[u] += sz[v];
            par[v] = u;
        }
    }
    bool same(int u, int v) { return find(u) == find(v); }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    DSU cc = DSU(N);
    int maxsize = 1;
    int components = N;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        if (!cc.same(a, b)) {
            cc.merge(a, b);
            maxsize = max(maxsize, cc.sz[cc.find(a)]);
            components--;
        }
        cout << components << " " << maxsize << "\n";
    }
    
}
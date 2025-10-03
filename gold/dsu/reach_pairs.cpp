#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

struct DSU {
    vector<int> par, size;
    long pairs = 0;
    DSU(int N): par(N), size(N) { while (N--) par[N] = N; }
    int find(int u) {
        if (par[u] != u) { par[u] = find(par[u]); }
        return par[u];
    }
    void add(int u) {
        u = find(u);
        pairs += size[u];
        size[u]++;
    }
    bool unite(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) { return false; }
        pairs += (long) size[ru] * size[rv];
        size[ru] += size[rv];
        par[rv] = ru;
        return true;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vt<bool> type(N);
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        type[i] = c == '1';
    }
    mt<int> G(N);
    DSU cc(N);
    while (M--) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].add(v);
        G[v].add(u);
    }
    for (int i = 0; i < N; i++) {
        if (type[i]) {
            for (int v : G[i]) {
                if (v > i && type[v]) { cc.unite(v, i); }
            }
        }
    }
    vt<long> ans(N);
    for (int u = N - 1; u > -1; u--) {
        cc.add(u);
        for (int v : G[u]) {
            if (u < v || type[v]) { cc.unite(u, v); }
        }
        ans[u] = cc.pairs;
    }
    for (long x : ans) {
        cout << x << "\n";
    }
}
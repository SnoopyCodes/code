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
#define long long long
template<int MOD> struct mint {
	int v;
	mint():v(0) {}
	mint(long _v):v(int(_v % MOD)) { v += (v < 0) * MOD; }
	friend mint operator+(mint a, const mint& b) { return a.v + b.v; }
	friend mint operator-(mint a, const mint& b) { return a.v - b.v; }
	friend mint operator*(mint a, const mint& b) { return (long)a.v*b.v; }
	friend mint operator/(mint a, const mint& b) { return a * inv(b); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mint inv(const mint& a) { return pow(a, MOD-2); }
};
using mi = mint<998244353>;

void solve() {
    int N, S; cin >> N >> S;
    vector<array<int, 3>> edges(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        edges[i] = { u, v, w };
    }
    sort(edges.begin(), edges.end(), [](auto a, auto b) { return a[2] < b[2]; });
    DSU cc(N);
    mi ans = 1;
    for (auto const&[u, v, w] : edges) {
        int u_size = cc.size[cc.find(u)];
        int v_size = cc.size[cc.find(v)];
        //for the edges between this component and the other
        int available = S - w;
        //there are available^(pairs - 1) edges
        ans = ans * pow(mi(available + 1), (long) u_size * v_size - 1);
        cc.merge(u, v);
    }
    cout << ans.v << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
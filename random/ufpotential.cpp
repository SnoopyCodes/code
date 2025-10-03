#include <bits/stdc++.h>
#define long long long
using namespace std;

template<int MOD> struct mint {
	#define fmo(o, z) friend mint operator o (const mint &a, const mint &b) { return z; }
	#define mo(o,p) mint& operator o (const mint &x) { return (*this) = (*this) p x; }
	int v; mint(long _v = 0):v(_v % MOD) { v += (v < 0) * MOD; }
	fmo(+, a.v + b.v) fmo(-, a.v - b.v) fmo(*, a.v * (long) b.v) fmo(/, a * pow(b, MOD - 2))
	mo(+=, +) mo(-=, -) mo(*=, *) mo(/=, /)
	friend mint pow(mint x, long p) { return p ? pow(x * x, p / 2) * (p & 1 ? x : 1) : 1; }
	#undef fmo
	#undef mo
};
using mi = mint<998244353>;

vector<int> dsu;
vector<int> sizes;
vector<mi> diff;

int find(int u) {
    if (dsu[u] != u) {
        int orig = dsu[u];
        dsu[u] = find(dsu[u]);
        diff[u] = (diff[orig] + diff[u]);
    }
    return dsu[u];
}
bool merge(int u, int v, int x) {
    int ru = find(u);
    int rv = find(v);
    if (ru == rv) { return (diff[u] - diff[v]).v == x; }
    if (sizes[ru] < sizes[rv]) { swap(ru, rv); x = -x; swap(u, v); }
    sizes[ru] += sizes[rv];
    diff[rv] = mi(-x) + diff[u] - diff[v];
    dsu[rv] = ru;
    return true;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    dsu.resize(N), sizes.resize(N, 1), diff.resize(N);
    for (int i = 0; i < N; i++) { dsu[i] = i; }
    for (int q = 0; q < Q; q++) {
        int t, u, v; cin >> t >> u >> v;
        if (t) {
            if (find(u) == find(v)) { cout << (diff[u] - diff[v]).v << "\n"; }
            else { cout << -1 << "\n"; }
        }   else {
            int x; cin >> x;
            cout << merge(u, v, x) << "\n";
        }
    }
}
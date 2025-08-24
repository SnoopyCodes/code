#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

template<int MOD> struct mint {
	int v; mint(long _v = 0):v(_v % MOD) { v += (v < 0) * MOD; }
	mint operator+(mint x) { return v + x.v; }
	mint operator-(mint x) { return v - x.v; }
	mint operator*(mint x) { return (long) v * x.v; }
	mint operator/(mint x) { return (*this) * pow(x, MOD - 2); }
	mint& operator+=(mint x) { return (*this) = (*this) + x; }
	mint& operator-=(mint x) { return (*this) = (*this) - x; }
	mint& operator*=(mint x) { return (*this) = (*this) * x; }
	mint& operator/=(mint x) { return (*this) = (*this) / x; }
	friend mint pow(mint x, long p) { return p ? pow(x * x, p / 2) * (p & 1 ? x : 1) : 1; }
};
using mi = mint<998244353>;

struct DSU {
    int N;
    vector<int> root, size;
    DSU(int _N):N(_N), root(N), size(N, 1)
    { iota(root.begin(), root.end(), 0); }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    #define union owiefjaiosdcjxzvoi
    bool union(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (size[ru] < size[rv]) { swap(ru, rv); }
        size[ru] += size[rv];
        root[rv] = ru;
        return true;
    }
};

void solve() {
    int N; cin >> N;
    vt<int> P(N), C(N), inv(N);
    DSU cc(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i]; P[i]--;
        inv[P[i]] = i;
    }
    for (int &u : C) {
        cin >> u;
    }
    mi ans = 1;
    for (int i = 0; i < N - 1; i++) {
        if (C[i] == C[i + 1]) {
            cc.union(i, i + 1);
        }
    }
    for (int i = 0; i < N; i++) {
        
    }
    cout << ans.v << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
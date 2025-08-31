#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

template<int MOD> struct mint {
	int v; mint(long _v = 0):v(_v % MOD) { v += (v < 0) * MOD; }
	mint operator+(mint x) { return v + x.v; }
	mint operator-(mint x) { return v - x.v; }
	mint operator*(mint x) { return (long) v * x.v; }
	mint operator/(mint x) { return (*this) * pow(x, MOD - 2); }
	friend mint pow(mint x, long p) { return p ? pow(x * x, p / 2) * (p & 1 ? x : 1) : 1; }
};
using mi = mint<998244353>;

template<class T> void add(vt<T> &v, T e) { v.push_back(e); }

mt<int> T, in_depth;
vt<bool> in_chain;
vt<int> par;
vt<mi> ans;

void solve_chain(int u) {
    vt<int> chain {u};
    vt<mi > coeff {0};
    u = par[u];
    while (!in_chain[u]) {
        in_chain[u] = true;
        add(chain, u);
        add(coeff, mi(1) / 2 / (mi(1) - coeff.back() / 2));
        u = par[u];
    }
    add(chain, u);
    add(coeff, mi(0));
    for (int i = chain.size() - 1, j = chain.size() - 2; j > 0; i--, j--) {
        ans[chain[j]] = ans[chain[i]] * coeff[j];
    }
}

void solve() {
    int N; cin >> N;
    in_depth = T = mt<int>(N);
    in_chain = vt<bool>(N);
    par = vt<int>(N, -1);
    ans = vt<mi>(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        add(T[v], u);
        add(T[u], v);
    }
    add(in_depth[0], 0);
    ans[0] = 1;
    in_chain[0] = true;
    for (int i = 0; i < N; i++) { //wow what a bfs
        for (int u : in_depth[i]) {
            for (int v : T[u]) {
                if (v == par[u]) { continue; }
                par[v] = u;
                add(in_depth[i + 1], v);
                if (T[v].size() == 1) {
                    solve_chain(v);
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i].v << " \n"[i == N - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
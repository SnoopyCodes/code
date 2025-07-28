#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;
template<class T> void rsz(vector<T> &v, int z, T def = T{}) { v.clear(); v.resize(z, def); }

template<int MOD> struct mint {
	int v; mint(long _v = 0):v(int(_v % MOD)) { v += (v < 0) * MOD; }
	mint operator+(mint x) { return mint(v + x.v); }
	mint operator-(mint x) { return mint(v - x.v); }
	mint operator*(mint x) { return mint((long)v * x.v); }
	mint operator/(mint x) { return mint((*this) * inv(x)); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mint inv(mint a) { return pow(a, MOD-2); }
};
using mi = mint<int(998244353)>;

int N, M;
vector<vector<ints<2>>> seg;
vector<mi> dp, pf;

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    std::cin >> M >> N;
    rsz(seg, N), rsz(dp, N + 1);  //probability all the ones before i are covered.
    rsz(pf, N + 1, mi(1)); //probability no segments before i exist.
    for (int i = 0; i < M; i++) {
        int l, r; std::cin >> l >> r; l--; r--;
        mi p, q; std::cin >> p.v >> q.v;
        seg[l].push_back({ r, (p / q).v });
        pf[l + 1] = pf[l + 1] * (mi(1) - (p / q));
    }
    for (int i = 0; i < N; i++) {
        pf[i + 1] = pf[i] * pf[i + 1];
    }
    auto query = [&](int l, int r) {  //that none in the range [l, r] begin.
        return pf[r + 1] / pf[l];
    };
    dp[0] = 1;

    //we need all the ones that are in the range to not appear.
    //sort the segments and find the range multiplication

    for (int i = 0; i < N; i++) {
        for (auto [r, pv] : seg[i]) {
            dp[r + 1] = dp[r + 1] + mi(pv) * dp[i] * query(i, r) / mi(1 - pv);
        }
    }
    std::cout << dp[N].v << "\n";
}
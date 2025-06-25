#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

template<int MOD> struct mint {
	int v;
	mint(long v = 0):v(int(v % MOD)) { v += (v < 0) * MOD; }
	friend mint operator+(mint a, mint b) { return a.v + b.v; }
	friend mint operator-(mint a, mint b) { return a.v - b.v; }
	friend mint operator*(mint a, mint b) { return (long)a.v*b.v; }
	friend mint operator/(mint a, mint b) { return a * inv(b); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mint inv(mint a) { return pow(a, MOD-2); }
};
using mi = mint<998244353>;

vector<mi> fax;

void spit_fax(int N) {
	fax.resize(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        fax[i] = fax[i-1] * i;
    }
}

mi choose(int n, int r) {
    if (r > n) { return 0; }
    return fax[n] / fax[r] / fax[n-r];
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T;
    spit_fax(60);
    //is this lowkey what we were doing before anyways
    //we will fix the first some bits
    //and then
    //when we find a set bit 
    //go to the last one and before the last one
    //we can calculate stuff
    while (T--) {
        long N, K; std::cin >> N >> K;
        int nbits = __builtin_popcountll(N);
        mi ans = 0;
        int last = __builtin_popcountll(N & -N);
        for (int b = 0; b < 61; b++) {
            if (N & 1LL << b) {
                N ^= 1LL << b;
                ans = ans + N * choose(b, K - nbits);
            }
        }
        std::cout << ans.v << "\n";
    }
}
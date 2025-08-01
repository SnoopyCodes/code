//im bored
#include <bits/stdc++.h>

using namespace std;

#define long long long

template<int MOD> struct mint {
	int v; mint(long _v = 0):v(_v % MOD) { v += (v < 0) * MOD; }
	mint operator+(mint x) { return v + x.v; }
	mint operator-(mint x) { return v - x.v; }
	mint operator*(mint x) { return (long) v * x.v; }
	mint operator/(mint x) { return (*this) * pow(a, MOD - 2); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
};
using mi = mint<int(1e9 + 7)>;

vector<mi> fax;

void spit_fax(int N) {
	fax.resize(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        fax[i] = fax[i-1] * i;
    }
}

mi choose(int n, int r) {
    return fax[n] / fax[r] / fax[n-r];
}
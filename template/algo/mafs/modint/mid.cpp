//im bored
#include <bits/stdc++.h>

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
using mi = mint<int(1e9 + 7)>;
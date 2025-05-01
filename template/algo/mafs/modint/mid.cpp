//im bored
#include <bits/stdc++.h>

using namespace std;
#define long long long

template<int MOD> struct mint {
	int v;
	mint():v(0) {}
	mint(long _v):v(int(_v % MOD)) { v += (v < 0) * MOD; }
	friend mint operator+(mint a, const mint& b) { return a.v + b.v; }
	friend mint operator-(mint a, const mint& b) { return a.v - b.v; }
	friend mint operator*(mint a, const mint& b) { return (long)a.v*b.v); }
	friend mint operator/(mint a, const mint& b) { return a * inv(b); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mint inv(const mint& a) { return pow(a, MOD-2); }
};
using mi = mint<int(1e9 + 7)>;
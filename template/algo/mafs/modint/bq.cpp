//no root cause idk fft /shrug
//a few things: p in power >= 0
//must never be 0 when doing inverse
//use c++ 20 for <=> comparisons
//this is a little more inefficient than others b/c it does modulo op each time?
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
template<int MOD> struct mint {
	int v;
	mint():v(0) {}
	mint(i64 _v):v(int(_v % MOD)) { v += (v < 0) * MOD; }
   
	friend mint operator+(mint a, const mint& b) { return a.v + b.v; }
	friend mint operator-(mint a, const mint& b) { return a.v - b.v; }
	friend mint operator*(mint a, const mint& b) { return (i64)a.v*b.v); }
	friend mint operator/(mint a, const mint& b) { return a * inv(b); }
	friend mint pow(mint a, i64 p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mint inv(const mint& a) { return pow(a, MOD-2); }
		
	mint& operator+=(const mint& o) { return (*this) = (*this) + o; }
	mint& operator-=(const mint& o) { return (*this) = (*this) - o; }
	mint& operator*=(const mint& o) { return (*this) = (*this) * o; }
	mint& operator/=(const mint& o) { return (*this) = (*this) / o; }

	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }

    friend ostream& operator<<(ostream& os, const mint& a){ os << a.v; return os; }
    friend istream& operator>>(istream& is, mint& a) { i64 x; is >> x; a = x; return is; }

    auto operator<=>(const mint&) const = default;

    explicit operator int() const { return v; } // explicit -> don't silently convert to int
};
using mi = mint<int(1e9 + 7)>;
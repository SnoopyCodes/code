//benq, with minor changes
using i64 = long long;
struct mi {
    static const int MOD = 1e9 + 7;
    int v;
    mi() : v(0) {}
	mi(i64 _v):v(int(_v % MOD)) { v += (v < 0) * MOD; }
	friend mi operator+(mi a, const mi& b) { return a.v + b.v; }
	friend mi operator-(mi a, const mi& b) { return a.v - b.v; }
	friend mi operator*(mi a, const mi& b) { return (i64)a.v*b.v; }
	friend mi operator/(mi a, const mi& b) { return a * inv(b); }
	friend mi pow(mi a, i64 p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mi inv(const mi& a) { return pow(a, MOD-2); }
	mi& operator+=(const mi& o) { return (*this) = (*this) + o; }
	mi& operator-=(const mi& o) { return (*this) = (*this) - o; }
	mi& operator*=(const mi& o) { return (*this) = (*this) * o; }
	mi& operator/=(const mi& o) { return (*this) = (*this) / o; }
    auto operator<=>(const mi&) const = default;
};
//benq, with minor changes
struct mi {
    static const int MOD = 1e9 + 7;
    int v;
    mi() : v(0) {}
    mi(long long _v) : v(int(_v % MOD)) { if (v < 0) { v += MOD; } }

	mi& operator+=(const mi& o) { 
		v -= ((v += o.v) >= MOD) * MOD; return *this;
    }
	mi& operator-=(const mi& o) { 
		v += ((v -= o.v) < MOD) * MOD; return *this;
    }
	mi& operator*=(const mi& o) { 
		v = int((long long) v * o.v % MOD); return *this;
    }
	mi& operator/=(const mi& o) { return (*this) *= inv(o); }
    friend mi pow(mi a, long long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
    friend mi inv(mi a) { return pow(a, MOD - 2); }
    friend mi operator+(mi a, mi b) { return a += b; }
    friend mi operator-(mi a, mi b) { return a -= b; }
    friend mi operator*(mi a, mi b) { return a *= b; }
    friend mi operator/(mi a, mi b) { return a /= b; }
    auto operator<=>(const mi&) const = default;
};
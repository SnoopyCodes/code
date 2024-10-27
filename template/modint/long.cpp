struct mi {
    static const int MOD = 1e9 + 7;
    int v;
    
    mi() : v(0) {}
    mi(long long _v) : v(int(_v % MOD)) {
        if (v < 0) v += MOD;
    }

    mi& operator+=(mi x) {
        v += x.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    mi& operator-=(mi x) {
        v -= x.v;
        if (v < 0) v += MOD;
        return *this;
    }
    mi& operator*=(mi x) {
        v = int((long long)v * x.v % MOD);
        return *this;
    }
    friend mi operator+(mi a, mi b) { return a += b; }
    friend mi operator-(mi a, mi b) { return a -= b; }
    friend mi operator*(mi a, mi b) { return a *= b; }
    friend bool operator==(mi a, mi b) { return a.v == b.v; }
    friend bool operator!=(mi a, mi b) { return a.v != b.v; }
};
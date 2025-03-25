#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
using i64 = long long;

struct mi {
    static const int MOD = 1e9 + 7;
    int v;
    mi() { v = 0; }
    mi(i64 _v) {
        _v %= MOD;
        v = _v + (_v < 0) * MOD;
    }
    friend mi operator+(mi a, const mi& b) { return mi(a.v + b.v); }
    friend mi operator-(mi a, const mi& b) { return mi(a.v - b.v); }
    friend mi operator*(mi a, const mi& b) { return mi((i64) a.v * b.v); }
    friend mi operator/(mi a, const mi& b) { return a * inv(b); }
    friend mi pow(mi x, i64 p) { return p ? pow(x * x, p / 2) * (p & 1 ? x : 1) : 1; }
    friend mi inv(mi x) { return pow(x, MOD - 2); }
};

const int MAXV = 1e6;
vec<mi> facs(MAXV + 1);
void spit_fax() {
    facs[0] = 1;
    rep(i, 1, MAXV + 1) {
        facs[i] = facs[i-1] * i;
    }
}

mi choose(int n, int r) {
    return facs[n] / facs[r] / facs[n - r];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int K, N; cin >> K >> N;
    i64 L; cin >> L;
    string s; cin >> s;
    spit_fax();
    //can always decomp
    //ignore L for now
    //iterate backwards from end to start
    //when we hit a thing we can "choose" K things
    //and then remove and keep going?
    //just try it, write modint
    int cnt = 0;
    mi ways = 1;
    rep(i, -N) {
        if (s[i] == 'O') { cnt++; }
        else {
            ways = ways * choose(cnt, K);
            cnt -= K;
        }
    }
    cout << pow(ways, L).v << "\n";
}
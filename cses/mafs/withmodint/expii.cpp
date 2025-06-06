#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;

template<int MOD> struct mint {
	int v;
	mint():v(0) {}
	mint(i64 _v):v(int(_v % MOD)) { v += (v < 0) * MOD; }
   
	friend mint operator+(mint a, const mint& b) { return mint(a.v + b.v); }
	friend mint operator-(mint a, const mint& b) { return mint(a.v - b.v); }
	friend mint operator*(mint a, const mint& b) { return mint((i64)a.v*b.v); }
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
    friend istream& operator>>(istream& is, mint& a) { i64 x; is >> x; a = mint(x); return is; }

    auto operator<=>(const mint&) const = default;

    explicit operator int() const { return v; } // explicit -> don't silently convert to int
};
using mb = mint<int(1e9 + 7)>;
using me = mint<int(1e9 + 6)>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    rep(i, N) {
        mb a; cin >> a;
        me b; cin >> b;
        int c; cin >> c;
        cout << pow(a, int(pow(b, c))) << "\n";
    }
}
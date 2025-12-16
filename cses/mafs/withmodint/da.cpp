#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
#define long long long

template<int MOD> struct mint {
	long v; mint(long _v = 0):v(_v % MOD) { v += (v < 0) * MOD; }
	#define fmo(o, c, z) friend mint operator o (mint a, mint b) { return a.v z c.v; }
	fmo(+, b, +) fmo(-, b, -) fmo(*, b, *) fmo(/, pow(b, MOD - 2), *)
	friend mint pow(mint x, long p) { return p ? pow(x * x, p / 2) * (p & 1 ? x : 1) : 1; }
	#define mo(o, z) mint& operator o (mint x) { return (*this) = (*this) z x; }
	mo(+=, +) mo(-=, -) mo(*=, *) mo(/=, /)
};
using mi = mint<int(1e9 + 7)>;
using me = mint<int(1e9 + 6)>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    long N; cin >> N;
	mi ndiv = 1, sdiv = 1, pdiv = 1;
	me prev_nd = 1;
	rep(i, N) {
		mi x; cin >> x.v;
		long p; cin >> p;
		sdiv *= (pow(x, p + 1) - 1) / (x - 1);
		//product of divisors? each factor is multiplied
		//by x^arithmetic sum of p?
		//p^0 * f0 * p^0 * f1...
		me np = p * (p + 1) / 2;
		np *= prev_nd;
		pdiv = pow(x, np.v) * pow(pdiv, p + 1);
		ndiv *= p + 1;
		prev_nd *= p + 1;
	}
	cout << ndiv.v << " " << sdiv.v << " " << pdiv.v << "\n";
}
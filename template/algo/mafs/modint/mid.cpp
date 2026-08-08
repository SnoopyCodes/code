//im bored
#include <bits/stdc++.h>

using namespace std;

#define long long long

template<int MOD> struct mint {
	long v; mint(long _v = 0):v(_v % MOD) { v += (v < 0) * MOD; }
	#define fmo(o, c, z) friend mint operator o (mint a, mint b) { return a.v z c.v; }
	fmo(+, b, +) fmo(-, b, -) fmo(*, b, *) fmo(/, b.pow(MOD - 2), *)
	mint pow(long p, mint c = 1) { return p ? mint(v * v).pow(p / 2, c * (p & 1 ? v : 1)) : c; }
	#define mo(o, z) mint& operator o (mint x) { return (*this) = (*this) z x; }
	mo(+=, +) mo(-=, -) mo(*=, *) mo(/=, /)
};
using mi = mint<int(1e9 + 7)>;
#undef fmo
#undef mo
/*
design a tail call recursive version for pow
*/
mi exp(mi a, int p, mi cur) {
	if (!p) {
		return cur;
	}
	if (p & 1) {
		cur *= a;
	}
	return exp(a * a, p / 2, cur);
}
//while (p > 0) c *= (p & 1) ? a : 1, a *= a, p /= 2;
// for (int i = 0; i < 64; i++, a *= 2) if (i & 1) c *= a;
// mi exp(a, p, c=0) { return p ? exp(a * a, p / 2, c *(p & 1 ? a : 1)) : cur; }

vector<mi> fax, ifax;

void spit_fax(int N) {
	fax = vector<mi>(N + 1);
	ifax = vector<mi>(N + 1);
	fax[0] = 1;
    for (int i = 1; i <= N; i++) {
        fax[i] = fax[i-1] * i;
    }
	ifax[N] = 1 / fax[N];
	for (int i = N - 1; i > -1; i--) {
		ifax[i] = ifax[i + 1] * (i + 1);
	}
}

mi choose(int n, int r) {
    return n < r ? 0 : fax[n] * ifax[r] * ifax[n-r];
}

mi big_choose(int n, int r) {
	if (n < r) { return 0; }
	mi res = ifax[r];
	r = n - r;
	while (n > r) { res *= n--; }
	return res;
}

int main() {
	mi a = 2;
	cout << (1 / a).v << "\n";
}
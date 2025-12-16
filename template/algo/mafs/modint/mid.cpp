//im bored
#include <bits/stdc++.h>

using namespace std;

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
#undef fmo
#undef mo

vector<mi> fax;

void spit_fax(int N) {
	fax = vector<mi>(N + 1);
	fax[0] = 1;
    for (int i = 1; i <= N; i++) {
        fax[i] = fax[i-1] * i;
    }
}

mi choose(int n, int r) {
    return n < r ? 0 : fax[n] / fax[r] / fax[n-r];
}

mi big_choose(int n, int r) {
	if (n < r) { return 0; }
	r = min(r, n - r);
	mi res = 1 / fax[r];
	r = n - r;
	while (n > r) { res *= n--; }
	return res;
}

int main() {
	
}
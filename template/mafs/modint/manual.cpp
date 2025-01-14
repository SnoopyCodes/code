#include <bits/stdc++.h>
#define long int64_t
using namespace std;

const int MOD = 1e9 + 7;

#define add(x, y) (((x) % MOD + (y) % MOD) % MOD + MOD) % MOD
#define sub(x, y) add((x), -(y))
#define mul(x, y) ((long(x) % MOD * (y) % MOD) % MOD + MOD) % MOD
#define div(x, y) long(x) * inv(y) % MOD

long exp(long x, int p) {
	long res = 1;
	while (p > 0) {
		if (p % 2 & 1) { res = mul(res, x); }
		x = mul(x, x);
		p /= 2;
	}
	return res;
}

long inv(long x) {
    return exp(x, MOD - 2);
}

const int MAXV = 1e6;
vector<long> fac;

long choose(int n, int r) {
    return div(div(fac[n], fac[r]), fac[n - r]);
}


int main() {
    cin.tie(0) -> sync_with_stdio(0);
	fac.resize(MAXV + 1);
	fac[0] = 1;
    for (int i = 1; i < MAXV + 1; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
}
//ok!
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int MOD = 1e9 + 7;

#define add(x, y) (((x) % MOD + (y) % MOD) % MOD + MOD) % MOD
#define sub(x, y) add((x), -(y))
#define mul(x, y) ((x % MOD * (y) % MOD) % MOD + MOD) % MOD
#define div(x, y) x * inv(y) % MOD

i64 exp(i64 x, int p) {
	i64 res = 1;
	while (p > 0) {
		if (p % 2 & 1) { res = mul(res, x); }
		x = mul(x, x);
		p /= 2;
	}
	return res;
}

i64 inv(i64 x) {
    return exp(x, MOD - 2);
}

const int MAXV = 1e6;
vector<i64> fac;

void spit_fax() {
	fac.resize(MAXV + 1);
	fac[0] = 1; //lets go math
	for (int i = 1; i < MAXV + 1; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
}

i64 choose(int n, int r) {
    return div(div(fac[n], fac[r]), fac[n - r]);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

}
//ok!
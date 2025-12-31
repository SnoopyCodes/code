#include <bits/stdc++.h>
#define long int64_t
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long uld(long a, long b) { return uniform_int_distribution<long>(a, b)(rng); }

const int MOD = 7;

int qp(int x, int p = MOD - 2) { return x ? 1ll*(x & 1 ? x : 1) * qp(1ll*x * x % MOD, p >> 1) % MOD : 1; }

vector<long> fac, ifac;

int choose(int n, int r) { return n < r ? 0 : fac[n] * ifac[r] % MOD * ifac[n - r] % MOD; }

void prec(int n) {
	fac.resize(n + 1), ifac.resize(n + 1);
	fac[0] = 1;
    for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
	ifac[n] = qp(fac[n]);
	for (int i = n - 1; i > -1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	}
}

int main() {
	
}
using ll = long;
#define M 998244353
#define mxN 1000000
ll inv(ll a) {
    return a<=1 ? a: M - (ll)(M/a) * inv(M%a) % M;
}
ll fact[mxN];
ll inv_fact[mxN];
void calc_fact() {
    fact[0] = 1;
    for (int i=1; i<mxN; i++) {
        fact[i] = fact[i-1]*i % M;
    }
    inv_fact[mxN-1] = inv(fact[mxN-1]);
    for (int i=mxN-1; i>=1; i--) {
        inv_fact[i-1] = inv_fact[i]*i%M;
    }
}
 
ll nCr(int n, int k) {
    if (k>n) return 0;
    return fact[n] * inv_fact[k]%M*inv_fact[n-k] % M;
}


//declare a mod before using
//filong up fac
//FLT: n^(p-1) === n mod p
//none of this matters if you don't know how to do math!
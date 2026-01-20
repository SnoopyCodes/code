#include <bits/stdc++.h>
#define long int64_t
#define func(f) [](auto a, auto b) { return f; }
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long uld(long a, long b) { return uniform_int_distribution<long>(a, b)(rng); }

const int MOD = 7;

int qp(int x, int p = MOD - 2) { return p ? (p & 1 ? x : 1) * qp(x * x % MOD, p / 2) % MOD : 1; }

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

int inv(int a) { return a<=1 ? a : MOD - (MOD/a) * inv(MOD % a) % MOD; }


//declare a mod before using
//filong up fac
//FLT: n^(p-1) === n mod p
//none of this matters if you don't know how to do math!
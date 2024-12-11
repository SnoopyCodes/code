#include <bits/stdc++.h>
#define long int64_t
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long uld(long a, long b) { return uniform_int_distribution<long>(a, b)(rng); }

const int MOD = 1e9 + 7;

long exp(long x, int p) {
	long res = 1;
	while (p > 0) {
		if (p % 2 & 1) { res = res * x % MOD; }
		x = x * x % MOD;
		p /= 2;
	}
	return res;
}

long inv(long x) {
    return exp(x, MOD - 2);
}

vector<long> fac;

long choose(int n, int r) {
    return fac[n] * inv(fac[r]) % MOD * inv(fac[n - r]) % MOD;
}

int main() {
    
}



//declare a mod before using
//filong up fac
//FLT: n^(p-1) === n mod p
//none of this matters if you don't know how to do math!
#include <bits/stdc++.h>
#define long int64_t
using namespace std;
#define vt vector

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long uld(long a, long b) { return uniform_int_distribution<long>(a, b)(rng); }

const int P = 7;

int qp(int x, int p = P - 2) { return p ? (p & 1 ? x :1) * qp(x * x % P, p / 2) % P : 1; }

vector<int> fac, ifac;

int choose(int n, int r) { return n < r ? 0 : fac[n] * ifac[r] % P * ifac[n - r] % P; }
void prec(int n) {
	fac = ifac = vt<int>(n + 1, 1);
    for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % P;
	}
	ifac[n] = qp(fac[n]);
	for (int i = n - 1; i > 1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % P;
	}
}

int main() {
	
}

int inv(int a) { return a<=1 ? a : P - (P/a) * inv(P % a) % P; }


//declare a mod before using
//filong up fac
//FLT: n^p === n mod p
//none of this matters if you don't know how to do math!
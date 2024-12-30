#include <bits/stdc++.h>
#define long int64_t
using namespace std;

const int MOD = 998244353;

long mul(long a, long b) {
	return ((a % MOD * b % MOD) % MOD + MOD) % MOD;
}

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
    return mul(mul(fac[n], inv(fac[r])), inv(fac[n - r]));
}

void solve() {
    int N; cin >> N;
    long ans = 0;
    for (int i = 1; i < 2; i++) { cout << 0 << " "; }
    for (int i = 2; i <= (N + 1) / 2; i++) {
        //the sequence consists of 1...i-1 and i+1...2 * i - 1
        //the remaining numbers are N - (2 * (i - 1)) to be put as needed
        //ensure everything is in bounds!
        //finally, run the thing
        //wait choose 3 in 6
        //1-2, 4-5, 6, 3
        //1-2, 4-6, 5, 3
        //
        //24 * 6, basically
        //oh wait i cannot count bro its so over
        //it doesn't have to be i + 1 ... 2 * i - 1 it only needs i + 1 and some others
        //so its choose i - 2
        //1,
        cout << mul(mul(fac[N - 2 * (i - 1) + 1], fac[2 * (i - 1)]), choose(N - (i + 1), i - 2)) << " ";
    }
    for (int i = (N + 1) / 2 + 1; i <= N; i++) { cout << 0 << " \n"[i == N]; }
}


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    fac.resize(MAXV + 1);
	fac[0] = 1;
    for (int i = 1; i < MAXV + 1; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
    int T; cin >> T; while(T--) { solve(); }
}
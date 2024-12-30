#include <bits/stdc++.h>
#define long int64_t
using namespace std;

const int MOD = 1e9 + 7;

long add(long a, long b) {
	return ((a % MOD + b % MOD) % MOD + MOD) % MOD;
}

long sub(long a, long b) {
	return add(a, -b);
}

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

const int MAXV = 2e6;
vector<long> fac;

long choose(int n, int r) {
    return fac[n] * inv(fac[r]) % MOD * inv(fac[n - r]) % MOD;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    fac.resize(MAXV + 1);
	fac[0] = 1;
    for (int i = 1; i <= MAXV; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
    int K; cin >> K;
    string s; cin >> s;
    int N = s.size();
    //so uh
    //how many strings are there of length K + N that don't have the original as a subsequence?
    //suppose that only strings with some prefix of S are allowed to exist
    //oh shoot yeah this makes sense omg
    //this is such a cool problem

    long ans = exp(26, N + K);
    //only s[0:i] are legal
    //after the first appearance of s[0:i], only ones without char i after can be there
    for (int i = 0; i < N; i++) {
        ans = sub(ans, exp(25, N + K - i) * choose(N + K, i));
    }
    cout << ans << "\n";
}
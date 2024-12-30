#include <bits/stdc++.h>
#define long int64_t
using namespace std;

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
    cin.tie(0) -> sync_with_stdio(0);
    fac.resize(2e6 + 2);
    fac[0] = 1;
    for (int i = 1; i < 2e6 + 2; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
    int N; cin >> N;
    long ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = (ans + choose(N + i + 1, i + 1)) % MOD;
    }
    cout << ans << "\n";
}
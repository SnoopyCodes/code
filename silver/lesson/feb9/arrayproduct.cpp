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

const int MAXV = 2e4;
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
    int N, K; cin >> N >> K;
    //count by length, split into primes
    //for each prime we give it some choices
    //i highly feel this won't tle b/c log k
    vector<array<int, 2>> facrize;
    //just don't even sieve im lazy
    for (int i = 2; i * i <= K; i++) {
        if (K % i != 0) { continue; }
        int cnt = 0;
        while (K % i == 0) { K /= i; cnt++; }
        facrize.push_back({i, cnt});
    }
    if (K != 1) { facrize.push_back({K, 1}); }
    long answer = 1;
    for (auto [p, k] : facrize) {
        //how many ways are there to split k into 
        //i buckets?
        //stars and bars
        //C(i + k - 1, i - 1)
        //... i'm using my math templates
        answer = answer * choose(N + k - 1, N - 1) % MOD;
    }
    //bounds check: N should go up to 1e6, K to 1e9
    cout << answer << "\n";
}
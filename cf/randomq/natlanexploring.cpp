#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> pretty(N);
    int maxa = 0;
    for (int i = 0; i < N; i++) {
        cin >> pretty[i];
        maxa = max(maxa, pretty[i]);
    }

    //sieve store 每element的divisors
    vector<int> sieve(maxa + 1);
    for (int i = 2; i <= maxa; i++) {
        if (sieve[i]) { continue; }
        for (int j = i; j <= maxa; j += i) {
            sieve[j] = i;  //largest prime divisor
        }
    }

    const int MOD = 998244353;
    vector<int> ways(N);
    ways[0] = 1;
    vector<int> m(1e6 + 1);
    for (int i = 0; i < N; i++) {
        vector<int> primes;
        int e = pretty[i];
        while (e > 1) {
            primes.push_back(sieve[e]);
            int x = sieve[e];
            while (e % x == 0) { e /= x; }
        }
        for (int mask = 1; mask < 1 << primes.size(); mask++) {
            int prod = 1;
            for (int b = 0; b < primes.size(); b++) {
                if (mask & 1 << b) { prod *= primes[b];  }       
            }
            if (__builtin_popcount(mask) & 1) {
                ways[i] = (ways[i] + m[prod]) % MOD;
            }   else {
                ways[i] = ((ways[i] - m[prod]) % MOD + MOD) % MOD;
            }
        }
        for (int mask = 1; mask < 1 << primes.size(); mask++) {
            int prod = 1;
            for (int b = 0; b < primes.size(); b++) {
                if (mask & 1 << b) { prod *= primes[b]; }
            }
            m[prod] = (m[prod] + ways[i]) % MOD;
        }
    }
    cout << ways[N - 1];
}
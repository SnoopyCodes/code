#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

template<size_t z> using ints = std::array<int, z>;

const int MOD = 1e9 + 7;
const long INF = 4e18 + 7e9;

vector<int> sieve;

void era(int n) {
    sieve.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) { continue; }
        for (int j = i; j <= n; j += i) {
            sieve[j] = i;
        }
    }
}

vector<int> lin_sieve(int n) {
    sieve.resize(n + 1);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (!sieve[i]) {
            primes.push_back(i);
            sieve[i] = i;
        }
        for (int j = 0; i * primes[j] <= n; j++) {
            sieve[i * primes[j]] = primes[j];
            if (primes[j] == sieve[i]) { break; }
        }
    }
    return primes;
}

vector<ints<2>> factor(int n) {
    vector<ints<2>> res;
    while (n > 1) {
        int p = sieve[n], ct = 0;
        while (n % p == 0) { n /= p; ct++; }
        res.push_back({ p, ct });
    }
    return res;
}

vector<int> factor_naive(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) { continue; }
        if (n / i != i) { res.push_back(i); }
        res.push_back(i);
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    /*
    lin_sieve is better
    */

    auto beg = std::chrono::system_clock::now();
    lin_sieve(1e8);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - beg;
    cout << elapsed.count() << "\n";
}
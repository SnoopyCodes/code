#include <bits/stdc++.h>

using namespace std;

vector<int> sieve;

/*
by lcm = a * b / gcd(a,b)
a * b * c / gcd(a,b)^2 + d = x / gcd(a,b)
iterate over factors of x as gcd(a,b)
a * b / gcd(a,b)^2 = (x / gcd(a,b) - d) / c
so we only need to find the number of coprime pairs a/gcd(a,b) and b / gcd(a,b)
this is done simply by finding number of primes dividing right hand side
and splitting between a and b
*/

void solve() {
    int C, D, X; cin >> C >> D >> X;
    vector<int> factors;
    for (int i = 1; i * i <= X; i++) {
        if (X % i == 0) {
            factors.push_back(i);
            if (i * i != X) { factors.push_back(X / i); }
        }
    }
    int ans = 0;
    for (int cd : factors) {
        int rhs = X / cd + D;
        if (rhs % C) { continue; }
        int need = rhs / C;
        int cur = 1;
        int primes = sieve[need];
        while (primes--) { cur *= 2; }
        ans += cur;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    sieve.resize(2e7 + 1);
    for (int i = 2; i <= 2e7; i++) {
        if (sieve[i]) { continue; }
        for (int j = i; j <= 2e7; j += i) {
            sieve[j]++;
        }
    }
    int T; cin >> T; while(T--) { solve(); }
}
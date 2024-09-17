#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll exp(ll x, ll p, ll m) {  //standard
    ll res = 1;
    x %= m;
    while (p > 0) {
        if (p % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        p /= 2;
    }
    return res;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    ll a, b; cin >> a >> b;
    vector<array<ll, 2>> primes;
    for (ll i = 2; i <= a; i++) {
        if (a % i == 0) { primes.push_back({i, 1}); a /= i; }
        while (a % i == 0) {
            primes.back()[1]++;
            a /= i;
        }
    }
    ll MOD = 1e9+7;
    //okay wait find all primes of it

    //fermat's lil
    //we want to calculate 
    //p^0 + p^1... p^(n * b) for every prime?
    //and then multiply together
    //basically, we will calculate
    //(p^(n * b + 1) - 1) / (p - 1)
    //lets cook guys
    //ok nvm that takes like forever bc what if a itself is prime
    ll ans = 1;
    for (auto const& [pri, pow] : primes) {
        //we can use flt to speed up a little?
        ans = ans * (exp(pri, (pow * b + 1) % (MOD - 1), MOD) - 1) % MOD
                * exp(pri - 1, MOD - 2, MOD) % MOD;
    }
    cout << ans << "\n";
}
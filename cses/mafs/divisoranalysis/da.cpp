#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
ll exp(ll x, ll p, ll m) {
    ll res = 1;
    x %= m;
    while (p > 0) {
        if (p % 2) { res = res * x % m; }
        p /= 2;
        x = x * x % m;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<array<int, 2>> primes(N);
    ll numfacs = 1, sumfacs = 1, prodfacs = 1;
    ll why = 1;
    for (int i = 0; i < N; i++) {
        cin >> primes[i][0] >> primes[i][1];
    }
    for (int i = 0; i < N; i++) {
        int p = primes[i][0], pow = primes[i][1];
        numfacs = numfacs * (primes[i][1] + 1) % MOD;
        sumfacs *= (exp(p, pow + 1, MOD) - 1) * (exp(p - 1, MOD - 2, MOD)) % MOD;
        sumfacs %= MOD;
 
        //okay how can we iteratively calculate this
        //start with 12
        //every single one is immediately put to the number of powers here
        //so it is original to the power of (primes[i][1] + 1) times (new^sumpowers) to the power of original
        //1 ^ 3 * (2 ^ (1 + 2)) then 8^ (1 + 1) * 3 ^ (1) ^ 3
        
        ll sumpow = (ll)(pow + 1) * pow / 2;  //this is fine
        prodfacs = exp(prodfacs, pow + 1, MOD)  //i think this is fine
         * exp(exp(p, sumpow, MOD), why, MOD);  //this is probably okay bc the base can be % MOD and the exp is alr fine
        prodfacs %= MOD;
        why = why * (primes[i][1] + 1) % (MOD - 1);
        //okay
        //wtf is this bs
    }
    cout << numfacs << " " << sumfacs << " " << prodfacs << "\n";
}
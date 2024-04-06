#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> primes;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    primes.resize(k);
    for (int i = 0; i < k; i++) { cin >> primes[i]; }
    //isn't this a counting problem?
    //kind of
    //wait yea its like depending on which ones are turned on and off
    //2^20 combinations
    //so if popcount(ll x) is even then subtract, if its positive then add?
    /*for (int i = 0; i < k; i++) {
            if (x & (1 << i)) {
                if (prod > n / primes[i]) { prod = -1; break; }
                prod *= primes[i];
            }
        }*/
    ll x = 1;
    ll ans = 0;
    ll end = 1 << k;
    while (x < end) {
        ll prod = 1;
        for (int i = 0; i < k; i++) {
            if (x & (1 << i)) {
                prod *= primes[i];
            }
            if (prod > n) { prod = -1; break; }
        }
        if (prod != -1) {
            if (__builtin_popcount(x) % 2 == 0) { ans -= n / prod; }  //if even
            else { ans += n / prod; }  //if odd
        }
        x++;
    }
    cout << ans << "\n";
}
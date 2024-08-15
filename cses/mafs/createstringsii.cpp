#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll exp(ll x, ll p, ll m) {
    ll res = 1;
    while (p > 0) {
        if (p % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        p /= 2;
    }
    return res;
}



int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    vector<int> freq(26);
    vector<ll> facs(N+1);
    facs[0] = facs[1] = 1;
    for (int i = 2; i < N + 1; i++) {
        facs[i] = facs[i-1] * i % MOD;
    }
    for (int i = 0; i < N; i++) {
        freq[s[i] - 'a']++;
    }
    int remaining = N;
    //binomial coefficient is nCr
    //n! / r! / (n - r)!
    ll ans = 1;
    for (int i = 0; i < 26; i++) {
        ans *= facs[remaining] * exp(facs[freq[i]], MOD - 2, MOD) % MOD
         * exp(facs[remaining - freq[i]], MOD - 2, MOD) % MOD;
        ans %= MOD;
        remaining -= freq[i];
    }
    cout << ans << "\n";
}
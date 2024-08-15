#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll exp(ll x, ll p, int m) {
    ll res = 1;
    while (p > 0) {
        if (p % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        p /= 2;
    }
    return res;
}

vector<ll> facs;

ll nCr(ll n, ll r) {
    return facs[n] * exp(facs[r], MOD - 2, MOD) % MOD *
    exp(facs[n - r], MOD - 2, MOD) % MOD;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //this is very simply pie
    //ways to distribute - N * ways for this child to get their own gift +
    //N choose 2 * ways to do other stuff
    //etc
    facs.resize(N+1);
    facs[0] = facs[1] = 1;
    for (int i = 2; i < N + 1; i++) {
        facs[i] = facs[i-1] * i % MOD;
    }
    ll ans = 0;
    for (int i = 0; i < N + 1; i++) {  //PIE with i children definitely getting their own
        ll delta = nCr(N, i) * facs[N - i] % MOD;
        ans = ans + (delta * (i % 2 == 0 ? 1 : -1) + MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";

}
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


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    //we can regard this as stars and bars
    //formula is N + M - 1 choose N - 1
    //6 choose 1
    vector<ll> fac(N + M);
    fac[0] = fac[1] = 1;
    for (int i = 2; i < N + M; i++) {
        fac[i] = fac[i-1] * i % MOD;
    }
    cout << fac[N + M - 1] * exp(fac[N - 1], MOD - 2, MOD) % MOD * exp(fac[M], MOD - 2, MOD) % MOD;
}
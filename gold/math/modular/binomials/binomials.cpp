#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
ll factorial[1000001];
ll inv(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2) { res = a * res % MOD; }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    factorial[0] = 1;
    for (int i = 1; i < 1000001; i++) {
        factorial[i] = factorial[i-1] * i % MOD;
    }
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    //now find modular inverses of
    //b and a - b
    ll inva = inv(factorial[b], MOD - 2);
    assert(factorial[b] * inva % MOD == 1);
    ll invb = inv(factorial[a-b], MOD - 2);
    assert(factorial[a-b] * invb % MOD == 1);
    ll ans = factorial[a];
    ans = ans * inva % MOD;
    ans = ans * invb % MOD;
    cout << ans << "\n";
    }
}
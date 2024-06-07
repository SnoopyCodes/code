#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll N; cin >> N;
    N = 4e9;
    ll total = 0;
    for (ll i = 1; i * i < N + 1; i++) {
        ll lim = N / i;
        total += ((((lim + i + 1)) * ((lim - i) % MOD)) / 2) % MOD;
        total %= MOD;
        total += (i * ((lim-i + 1))) % MOD;
        total %= MOD;
    }
    cout << total << "\n";
}
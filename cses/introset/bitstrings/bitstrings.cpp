#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll N; cin >> N;
    //print 2^N
    ll res = 1;
    ll x = 2;
    while (N > 0) {
        if (N % 2 == 1) { res = res * x % MOD; }
        N /= 2;
        x = x * x % MOD;
    }
    cout << res << "\n";
}
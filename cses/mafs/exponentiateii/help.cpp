#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll exp(ll x, ll p, ll m) {
    ll res = 1;
    while (p > 0) {
        if (p % 2) { res = res * x % m; }
        p /= 2;
        x = x * x % m;
    }
    return res % m;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    const int MOD = 1e9 + 7;
    for (int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        cout << exp(a, exp(b, c, MOD - 1), MOD) << "\n";
    }
    //you cant exp a exp LMAO
    //we can repeatedly halve the technical amount by squaring the bottom
    //
}
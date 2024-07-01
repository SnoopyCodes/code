#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
//i did not use a template for this
ll exp(ll x, ll p, ll m) {
    ll res = 1;
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
    //uh bruh what
    //i suspect we will double count and eventually divide by 2
    int target = (N * (N + 1)) / 2;
    if (target % 2) { cout << 0; return 0; }
    target >>= 1; //i love arrows
    //okay first of all the sum is like N^2 so we can just run dp on that?
    //calculate the inverse of modulo 2 in 1e9+7
    //to multiply at the end
    //does what im doing even make sense?
    //
    vector<ll> ways(target+1);
    ways[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int x = target; x >= 0; x--) {
            if (ways[x] && target >= x + i) {
                ways[x + i] += ways[x];
                ways[x + i] %= MOD;
            }
        }
    }
    cout << (ways[target] * exp(2, MOD - 2, MOD))% MOD << "\n";
}
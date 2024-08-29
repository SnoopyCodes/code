#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
vector<int> facs;
ll exp(ll x, int p, int m) {
    ll res = 1;
    while (p > 0) {
        if (p % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        p /= 2;
    }
    return res;
}
ll nCr(int n, int r) {
    return facs[n] * exp(facs[r], MOD - 2, MOD) % MOD
            * exp(facs[n - r], MOD - 2, MOD) % MOD;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int K; cin >> K;
    string s; cin >> s;
    int N = s.size();
    facs.resize(K + N + 2);
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = s[i] - 'a';
    }
    facs[0] = facs[1] = 1;
    for (int i = 2; i < K + N + 2; i++) {
        facs[i] = facs[i-1] * i % MOD;
    }
    //okay uh
    //bruh this is so free
    //wait actually fun math probelm?
    //wait so its first number of ways to make string of length K
    //then insert segments of the word into there
    //26^K
    //
    ll initial = exp(26, K + N, MOD);
    
    ll ans = initial;
    cout << ans << "\n";
}
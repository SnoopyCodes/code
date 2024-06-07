#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9+7;
int K;
vector<int> pfx;
vector<int> dp;
vector<int> fac;
vector<int> invs;
void solve() {
    int a, b; cin >> a >> b;
    cout << pfx[b+1] - pfx[a] << "\n";
}
//idk how to do this
//do this later
ll exp(ll x) { //find exponent of x to the mod-2 power
    ll m = MOD;
    ll n = m-2;
    x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	ll res = 1;
    cout << "hi" << endl;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
    cout << "bruh" << endl;
    cout << res << endl;
	return res % m;
}
void inv(int to) {
    //find inverses of 1 to to
    //so bc inv n! = inv n! * n+1 * inv n+1 = inv n+1! * n+1
    cout << exp(fac[to]) << endl;
    invs[to] = (int) exp(fac[to]);
    cout << invs[to] << endl;
    for (int i = to; i >= 1; i--) {
        invs[i-1] = (ll) invs[i] * i % MOD;
        assert((ll) invs[i] * fac[i] % MOD == 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T >> K;
    invs.resize(1e5+1);
    pfx.resize(1e5+2);
    dp.resize(1e5+1);
    fac.resize(1e5+1);
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= 1e5; i++) {
        fac[i] = (int) ((fac[i-1] * (ll) i) % MOD);
    }
    inv(1e5);
    int n, c; cin >> n >> c;
    cout << (ll) fac[n] * invs[n-c] * invs[c] % MOD << "\n";
    cout << exp(n) << "\n";
    //then fill pfx
    //so for size k and we have n flowers to eat
    //we can choose to eat up to n / k batches
    //then the setup is (n - batches * (k-1)) choose batches
    //which is (n-batches * (k-1))! / ((n-batches*k)! * batches!)
    //compute factorials up to 10^5?
    //what do we need even
    //we can get the factorials and stuff mod stuff
    //we know how to calculate it so now just implement exponentiation
    //ok implemented
    //now calculate for every one and run pfx on it
    //while (T) { T--; solve(); }
}
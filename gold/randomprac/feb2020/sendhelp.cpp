#include <bits/stdc++.h>

using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }
//intellegent gampelay

const int MOD = 1e9 + 7;

ll exp(ll x, int p) {
	ll res = 1;
	while (p > 0) {
		if (p % 2 & 1) { res = res * x % MOD; }
		x = x * x % MOD;
		p /= 2;
	}
	return res;
}

int main() {
	// freopen("help.in", "r", stdin);
	// freopen("help.out", "w", stdout);
	int N; cin >> N;
	vector<int> happen(N + 1);
	vector<int> interval(2 * N);
    vector<ll> hash(2 * N);
	for (int i = 0; i < N; i++) {
		int l, r; cin >> l >> r; l--; r--;
        ll val = rng();
		interval[l]++;
        hash[l] = val;
		interval[r]--;
        hash[r] = val;
	}
	int diff = 0;
    ll hasher = 0;
    set<ll> seen;
	for (int i = 0; i < 2 * N; i++) {
		diff += interval[i];
        hasher ^= hash[i];
		if (diff >= 2 && !seen.count(hasher)) {
            happen[diff]++;
            seen.insert(hasher);
        }
	}
	ll ans = exp(2, N) * (N / 2) % MOD;
	if (N % 2 & 1) {
		ans = (ans + exp(2, N - 1)) % MOD;
	}
	vector<ll> suff(N + 2);
	for (int i = N; i > 0; i--) {
        //how many groups of 4 can 5 have?
        //5
        //but we have neglected that these groups are not all different
        //wtf the overlap is gg
		suff[i] = suff[i + 1] * i + happen[i];
	}
    //lock in
	for (int i = 2; i <= N; i++) {
		int mult = i % 2 & 1 ? 1 : -1;
		ans = (((ans - suff[i] * exp(2, N - i)) % MOD) + MOD) % MOD;
	}
	cout << ans << endl;
}
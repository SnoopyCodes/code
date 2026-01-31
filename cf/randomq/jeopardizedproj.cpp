#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

int qp(int x, int p = MOD - 2) { return p ? (p & 1 ? x : 1) * qp(x * x % MOD, p / 2) % MOD : 1; }

vector<int> fac, ifac;

int choose(int n, int r) { return n < r ? 0 : fac[n] * ifac[r] % MOD * ifac[n - r] % MOD; }

void prec(int n) {
	fac.resize(n + 1), ifac.resize(n + 1);
	fac[0] = 1;
    for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
	ifac[n] = qp(fac[n]);
	for (int i = n - 1; i > -1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	}
}

vt<int> ans, pans;
void solve() {
    int l, r; cin >> l >> r;
    cout << (pans[r + 1] - pans[l] + MOD) % MOD << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    prec(2e5);
    const int N = 1e5;
    vt<int> p2(N + 1);
    p2[0] = 1;
    ans = vt<int>(N + 1);
    for (int i = 1; i <= N; i++) p2[i] = p2[i - 1] * 2 % MOD;
    for (int i = 1; i <= N; i++) {
        ans[i] = (p2[i - 1] - p2[i / 2] + MOD) % MOD; 
    }
    pans = vt<int>(N + 2);
    for (int i = 1; i <= N; i++) {
        pans[i + 1] = (pans[i] + ans[i]) % MOD;
    }

    int T; cin >> T; while (T --> 0) solve();
}
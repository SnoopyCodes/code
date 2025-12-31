#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 998244353;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i,a,b) for (auto i=a; i<(b); i++)

long exp(long x, int p = MOD - 2) {
	long res = 1;
	while (p > 0) {
		if (p % 2 & 1) { (res *= x) %= MOD; }
		(x *= x) %= MOD;
		p /= 2;
	}
	return res;
}

vector<long> fac, ifac;

long choose(int n, int r) {
    return n < r ? 0 : fac[n] * ifac[r] % MOD * ifac[n - r] % MOD;
}
void prec(int n) {
	fac.resize(n + 1);
	ifac.resize(n + 1);
	fac[0] = 1;
    for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
	ifac[n] = exp(fac[n]);
	for (int i = n - 1; i > -1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	}
}


void solve()  {
    int N; cin >> N;
    vt<int> A(N);
    long sum = 0;
    bool bad = false;
    rep (i, 0, N) {
        cin >> A[i];
        sum += A[i];
        if (A[i] && i > (N - 1) / 2) {
            bad = true;
        }
    }
    if (bad || sum != N) {
        cout << 0 << "\n";
        return;
    }

    long ans = 1;
    int cur = 0;
    for (int i = (N - 1) / 2; i > -1; i--) {
        cur++;
        if (!(N & 1 && i == (N - 1) / 2)) {
            cur++;
        }
        int take = A[i];
        // cout << cur << " " << take << "\n";
        //if take > cur then = 0 right?
        
        (ans *= choose(cur, take)) %= MOD;
        cur -= take;
    }

    cout << ans << "\n";


}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    prec(2e5);
    int T; cin >> T; while (T--) solve();
}
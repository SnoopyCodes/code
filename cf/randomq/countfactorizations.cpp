#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 998244353;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;


const int N = 4e3 + 1e2, M = 1e6 + 5;
int dp[N][N];
int f[M], era[M];
int fin[N];

int qp(int x, int p = MOD - 2) { return p ? 1ll*(p & 1 ? x : 1) * qp(1ll*x * x % MOD, p / 2) % MOD : 1; }

int fac[M], ifac[M];

int choose(int n, int r) { return n < r ? 0 : fac[n] * ifac[r] % MOD * ifac[n - r] % MOD; }

void prec(int n) {
	fac[0] = 1;
    for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
	ifac[n] = qp(fac[n]);
	for (int i = n - 1; i > -1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	}
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    prec(M);
    rep(i, 2, M) {
        if (era[i]) continue;
        for (int j = i; j < M; j += i) {
            era[j] = i;
        }
    }
    //e hell yeah

    int n; cin >> n;
    int sz = 0;
    rep(i, 0, 2 * n) {
        int x; cin >> x;
        if (!f[x]++) {
            fin[sz++] = x;
        }
    }
    
    dp[0][0] = fac[n];

    rep(i, 0, sz) {
        int x = fin[i];
        rep(v, 0, n + 1) {
            //we have two options: if we are a prime, then we can become prime and multiply by ifac[f[x] - 1]
            //otherwise we can multiply by ifac[f[x]]
            if (era[x] == x) {
                (dp[i + 1][v + 1] += dp[i][v] * ifac[f[x] - 1] % MOD) %= MOD;
            }
            //surely no overflow
            (dp[i + 1][v] += dp[i][v] * ifac[f[x]] % MOD) %= MOD;
        }
    }
    cout << dp[sz][n] << "\n";
}
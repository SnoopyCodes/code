#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 998244353;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

int qp(int x, int p = MOD - 2) { return p ? (p & 1 ? x : 1) * qp(x * x % MOD, p / 2) % MOD : 1; }

vt<int> fac, ifac;

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


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    prec(62500 * 2);
    int N, K; cin >> N >> K;
    /*
    see how fast i can do this i guess
    wait the idea is ? 
    keep dp[i][j] = # of ways to have (i+1) as max edge length
    and j selected nodes so far
    compress states by adding on top of each other.
    
    how did i get this wrong?
    the problem is probably the qp()
    we can possibly be painting the same edges over?
    */

    N--;
    vt dp(N + 1, 0LL);
    dp[0] = 1;
    for (int i = 0; i < K; i++) {
        auto prev = dp;
        dp = vt(N + 1, 0LL);
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= N - j; k++) {
                //k is # to add.
                //for size j, we choose some non-tree edges (possibly 0) to turn into 
                //weight (i+1), and we choose some nodes to turn into (i+1)
                //wait do not do this i think
                //instead as we add nodes we set all edges NOW.
                //we have k * j + C(k, 2) new edges. we can set them to anything
                //in range [i, K - 1]. so (K - i) choices
                (dp[j+k] += choose(N - j, k) * prev[j] % MOD
                    * qp((K - i), k * j + k * (k - 1) / 2)) %= MOD;
            }
        }
    }
    cout << dp[N] << endl;
    
}
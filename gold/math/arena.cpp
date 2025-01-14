#include <bits/stdc++.h>
#define vec vector  //testing
#define long int64_t
using namespace std;

const int MOD = 998244353;

#define add(x, y) (((x) % MOD + (y) % MOD) % MOD + MOD) % MOD
#define sub(x, y) add((x), -(y))
#define mul(x, y) ((long(x) % MOD * (y) % MOD) % MOD + MOD) % MOD
#define div(x, y) (x) * inv(y) % MOD

long exp(long x, int p) {
	long res = 1;
	while (p > 0) {
		if (p % 2 & 1) { res = mul(res, x); }
		x = mul(x, x);
		p /= 2;
	}
	return res;
}

long inv(long x) {
    return exp(x, MOD - 2);
}

vec<int> fac;
long choose(int n, int r) {
    return div(div(fac[n], fac[r]), fac[n - r]);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, X; cin >> N >> X;

    //dp[i][j] = ways with i remaining and j as max value
    fac.resize(500 + 1);
    fac[0] = 1;
    for (int i = 1; i <= 500; i++) {
        fac[i] = (long) fac[i-1] * i % MOD;
    }
    vec<vec<int>> P(501, vec<int> (501));
    vec<vec<int>> C(501, vec<int> (501));
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            C[i][j] = choose(i, j);
            P[i][j] = exp(i, j);
        }
    }
    vec<vec<int>> dp(N + 1, vec<int>(X + 1));
    for (int i = 1; i <= X; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= X; i++) {
        dp[1][i] = 0;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= X; j++) {  //living
            if (j < i) { dp[i][j] = exp(j, i); continue; }
            for (int k = 0; k <= i; k++) {
                int die = i - k;
                //kill some people
                long ways = mul(P[i - 1][die], C[i][die]);
                dp[i][j] = add(dp[i][j], mul(dp[k][j - (i - 1)], ways));
            }
        }
    }
    cout << dp[N][X] << "\n";

}
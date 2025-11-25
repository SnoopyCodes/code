#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;
#define mm(x) ((((x) % MOD) + MOD) % MOD)
#define me(x) ((((x) %= MOD) += MOD) %= MOD)
long exp(long x, int p) {
	long res = 1;
	while (p > 0) {
		if (p % 2 & 1) { me(res *= x); }
		(x *= x) %= MOD;
		p /= 2;
	}
	return res;
}

vector<long> fac, ifac;

long choose(int n, int r) {
    return fac[n] * ifac[r] % MOD * ifac[n - r] % MOD;
}
void prec(int n) {
	fac.resize(n + 1);
	ifac.resize(n + 1);
	fac[0] = 1;
    for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
	ifac[n] = exp(fac[n], MOD - 2);
	for (int i = n - 1; i > -1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	}
}

void solve() {
    int N, A, B; cin >> N >> A >> B;
    if (N < A + B) { cout << 0 << "\n"; return; }
    long ties = choose(N, A + B); //(n, n - (a + b))
    long reorderings = fac[N];
    N = A + B;
    assert(N <= 10);
    long ways = 0;
    for (int mask = 0; mask < 1 << N; mask++) {
        if (__builtin_popcount(mask) == A) {
            long cur = 1;
            int ct = 0;
            for (int b = 0; b < N; b++) {
                if (mask & 1 << b) {
                    cur *= ++ct;
                }
            }
            (ways += cur) %= MOD;
        }
    }
    cout << ways << "\n";
    (((ways *= ties) %= MOD) *= reorderings) %= MOD;
    cout << ways << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    prec(5000);
    int T; cin >> T; while (T --> 0) { solve(); }
}
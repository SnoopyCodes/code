#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
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

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    prec(2 * N + 1);
    string s; cin >> s;
    int everneg = false;
    int M = N - size(s);
    int sum = 0;
    if (N % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }
    rep(i, 0, N - M) {
        sum += s[i] == '(' ? 1 : -1;
        if (sum < 0) {
            everneg = true;
        }
    }
    if (everneg) {
        cout << 0 << "\n";
        return 0;
    }
    //the problem is the same as finding a valid bracket sequence
    //that has sum more starting than closing.
    //find # of closing.
    int closing = (M - sum) / 2;
    int n = sum + closing, m = closing;
    int ans = choose(n + m, n);
    rep(i, 0, m) { //the x-coordinate at which we move above
        //we need to get to (n, m) from (i, i + 1)
        int catalan = qp(i + 1) * choose(2 * i, i) % MOD;
        int paths = choose(n - i + m - (i + 1), n - i);
        int bad = catalan * paths % MOD;
        ((ans -= bad) += MOD) %= MOD;
    }
    cout << ans << "\n";
    

}
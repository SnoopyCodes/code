#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

int M;

int qp(int x, int p = M - 2) { return p ? (p & 1 ? x : 1) * qp(x * x % M, p / 2) % M : 1; }

vt<int> fac, ifac;

int choose(int n, int r) { return n < r ? 0 : fac[n] * ifac[r] % M * ifac[n - r] % M; }

void prec(int n) {
	fac.resize(n + 1), ifac.resize(n + 1);
	fac[0] = 1;
    for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % M;
	}
	ifac[n] = qp(fac[n]);
	for (int i = n - 1; i > -1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % M;
	}
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N >> M;
    prec(2 * N);
    int ans = 0;
    int rem = (N) / 2;
    rep(i, rem, N) {
        int outer = max(0LL, N - (i) - 2);
        int ct = 2 * rem - i; //# of final choices we can make
        //permute the remaining i elements
        rep(j, 0, outer + 1) {
            //(i + 1 + j elements)
            //i! * j! * choose(i + j, j)
            (ans += N * ct % M * choose(outer, j) % M * fac[i - 1 + j] % M) %= M;
        }
    }


    cout << ans << "\n";

}
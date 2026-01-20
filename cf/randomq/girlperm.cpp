#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

int qp(int x, int p = MOD - 2) { return p ? 1ll*(p & 1 ? x : 1) * qp(1ll*x * x % MOD, p / 2) % MOD : 1; }

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


void solve() {
    int N, npf, nsf; cin >> N >> npf >> nsf;
    vt<int> pf(npf), sf(nsf);
    vt<int> see(N);
    rep(i, 0, npf) {
        cin >> pf[i], pf[i]--;
        see[pf[i]]++;
    }
    int maxsf = 0;
    rep(i, 0, nsf) {
        cin >> sf[i], see[sf[i]-1]++, sf[i] = N - sf[i];
        if (i == nsf - 1) {
            maxsf = N - sf[i] - 1;
        }
    }
    /*
    what makes them invalid?
    if they overlap by more than one element.
    */
    see[pf.back()]--;
    if (N - sf[0] - 1 != pf.back() || nsf + npf > N + 1 || *ranges::max_element(see) > 1 || maxsf != N - 1 || pf[0] != 0) {
        cout << 0 << "\n";
        return;
    }
    ranges::reverse(sf);

    /*
    sf[0] == pf[-1] = N
    take a set of elements for the left side.
    how many ways are there to arrange them?
    oh we can just recursion it sorta kinda
    */

    auto solve = [](vt<int> v) {
        int rem = v.back();
        ranges::reverse(v);
        int res = 1;
        rep(i, 1, size(v)) {
            int amt = v[i - 1] - v[i] - 1;
            //amt is in between. we choose the largest, then the between
            (res *= fac[rem - 1] * ifac[rem - 1 - amt] % MOD) %= MOD;
            rem -= 1 + amt;
        }
        return res;
    };

    int ways = solve(pf) * solve(sf) % MOD;
    (ways *= choose(N - 1, pf.back())) %= MOD;
    cout << ways << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    prec(2e5);
    int T; cin >> T; while (T --> 0) solve();
}
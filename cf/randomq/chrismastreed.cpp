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

void solve() {
    int N; cin >> N;
    vt<int> A(N);
    int reserve; cin >> reserve;
    rep(i, 0, N) {
        cin >> A[i];
    }

    int max_r = *ranges::max_element(A);
    int cnt_max_r = ranges::count(A, max_r);
    /*
    recalculate values; find for i how much we will need to take from box 0
    */
    
    vt<int> take(N);
    int sum = 0;
    rep(i, 0, N) {
        take[i] = max_r - A[i];
        sum += take[i];
    }
    sum -= N - cnt_max_r; //if all elements are after last occurrence of max_r
    int ans = 0;
    //take[i] is # of taken from box if it's i < (j := index of last occurrence of max_r)
    rep(i, cnt_max_r - 1, N) { //final occurrence of max_r
        if (sum > reserve) {
            break;
        }
        int rem = N - cnt_max_r;
        int amt = i; //# of spots
        //we delegate cnt_max_r - 1 of them to these spots
        //we may permute them in whichever way we choose WITH current index?
        //i believe so
        long set_max_r = choose(i, cnt_max_r - 1) * fac[cnt_max_r] % MOD;
        //now we choose the other stuff to fill
        long inc = set_max_r * fac[rem] % MOD;
        (ans += inc) %= MOD;
        sum++; // we take more each time?
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    prec(50);
    int T; cin >> T; while (T --> 0) solve();
}
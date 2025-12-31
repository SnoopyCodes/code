#include <bits/stdc++.h>

using namespace std;

const int  MOD = 998244353;
#define int long long
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
#define add push_back
#define rep(i,a,b) for(auto i=a; i<(b); i++)

int exp(int x, int p = MOD - 2) {
	int res = 1;
	while (p > 0) {
		if (p % 2 & 1) { (res *= x) %= MOD; }
		(x *= x) %= MOD;
		p /= 2;
	}
	return res;
}

vector<int> fac, ifac;

int choose(int n, int r) {
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

vt<int> p2;

int fast(ii<61> a, int x, int total) {
    //we only ever match a[i] to one particular group. find that group.
    int ans = 0;
    int amt = 0; //bits already set
    int seen_bits = 0;
    int prev_bit = 61;
    int prev_ways = 1;
    
    for (int i = 60; i > -1; i--) {
        if (x >> i & 1) {
            int cnt = 1;
            for (int j = i - 1; j > -1; j--) {
                if (x >> j & 1) {
                    cnt++;
                }   else {
                    break;
                }
            }

            //the given bit is i + amt
            int b = i + amt;
            //how many reindeer are in between b and prev_bit?
            int sum = 0;
            rep(j, b + 1, prev_bit) {
                sum += a[j];
            }
            //ans += 2^(sum - 1) * 2^(N - sum - amt)
            //surely?
            if (sum > 0) {
                (ans += prev_ways * (p2[sum] - 1) % MOD * p2[total - sum - seen_bits] % MOD) %= MOD;
            }
            //new ways := C(a[i], cnt) * prev_ways
            if (a[b] < cnt) {
                prev_ways = 0;
                break;
            }
            int new_ways = choose(a[b], cnt) * prev_ways % MOD;
            //now count overfill (choosing > cnt from this)
            //at least one
            if (a[b] > cnt) {
                int ways_to_not = 0;
                rep(j, 0, cnt + 1) {
                    (ways_to_not += choose(a[b], j) % MOD) %= MOD;
                }
                int ways_to_over = (p2[a[b]] - ways_to_not + MOD) % MOD;
                //p2[a[b] - cnt] is # of ways to turn other stuff on?
                (ans += prev_ways * ways_to_over % MOD * p2[total - sum - seen_bits - a[b]] % MOD) %= MOD;
            }

            amt += cnt;
            seen_bits += a[b];
            seen_bits += sum;
            prev_bit = b;
            prev_ways = new_ways;

            i = i - cnt + 1;
        }
    }

    int sum = 0;
    rep(i, 0, prev_bit) {
        sum += a[i];
    }
    (ans += p2[sum] * prev_ways % MOD) %= MOD;
    return ans;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    ii<61> cnt{};
    p2.resize(6e5);
    prec(6e5);
    p2[0] = 1;
    rep(i, 1, 6e5) p2[i] = p2[i-1] * 2 % MOD;
    int N, M; cin >> N >> M;
    rep(i, 0, N) {
        int x; cin >> x;
        cnt[x]++;
    }
    while (M --> 0) {
        int t; cin >> t;
        if (t == 1) {
            int x ; cin >> x;
            cnt[x]++;
            N++;
        }   else if (t == 2) {
            int x; cin >> x;
            cnt[x]--;
            N--;
        }   else {
            int x; cin >> x;
            cout << fast(cnt, x, N) << "\n";
        }
    }
}
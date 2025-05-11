#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

#define long long long

template<int MOD> struct mint {
	int v;
	mint():v(0) {}
	mint(long _v):v(int(_v % MOD)) { v += (v < 0) * MOD; }
	friend mint operator+(mint a, const mint& b) { return a.v + b.v; }
	friend mint operator-(mint a, const mint& b) { return a.v - b.v; }
	friend mint operator*(mint a, const mint& b) { return (long)a.v*b.v; }
	friend mint operator/(mint a, const mint& b) { return a * inv(b); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mint inv(const mint& a) { return pow(a, MOD-2); }
};
using mi = mint<int(998244353)>;

const int MAXV = 1e6;
vector<mi> fac(MAXV + 1);
void spit_fax() {
    fac[0] = 1;
    for (int i = 1; i <= MAXV; i++) {
        fac[i] = fac[i-1] * i;
    }
}

mi choose(int n, int r) {
    return fac[n] / fac[r] / fac[n-r];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    mi ans = 0;
    spit_fax();
    vector<array<int, 2>> event(2 * N);
    for (int i = 0; i < N; i++) {
        int l, r; cin >> l >> r;
        event[2 * i] = { l, 1 };
        event[2 * i + 1] = { r + 1, -1 };
    }
    sort(event.begin(), event.end());

    int i = 0, cur = 0;
    while (i < 2 * N) {
        //just run pascal's, no need for nck
        int t = event[i][0];
        while (event[i][0] == t) {
            if (event[i][1] < 0) { cur--; }
            else {
                //C(N, K) = C(N - 1, K - 1) + C(N - 1, K)
                //C(N - 1, K - 1)
                if (cur + 1 >= K) { ans = ans + choose(cur, K - 1); }
                cur++;
            }
            i++;
        }
        
    }
    cout << ans.v << "\n";
}
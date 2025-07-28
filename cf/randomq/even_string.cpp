#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int MOD = 998244353;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

struct mint {
	int v; mint(long _v = 0):v(int(_v % MOD)) { v += (v < 0) * MOD; }
	mint operator+(mint x) { return v + x.v; }
	mint operator-(mint x) { return v - x.v; }
	mint operator*(mint x) { return (long)v * x.v; }
	mint operator/(mint x) { return (*this) * inv(x); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mint inv(mint a) { return pow(a, MOD-2); }
};

vector<mint> fax;

void spit_fax(int N) {
	fax.resize(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        fax[i] = fax[i-1] * i;
    }
}

void solve() {
    int N = 0;
    int C = 26;
    vector<int> ct(C);
    mint div = 1;
    for (int i = 0; i < C; i++) {
        std::cin >> ct[i];
        N += ct[i];
        div = div * fax[ct[i]];
    }
    /*
    uhh wtf
    the total # of ways to partition the string is n!/c_0!/c_1!...
    o bruh so basically its the total thing and then
    */
    vector<mint> ways(N + 1);
    ways[0] = 1;
    for (int i = 0; i < C; i++) {
        if (!ct[i]) { continue; }
        for (int j = N - ct[i]; j > -1; j--) {
            ways[j + ct[i]] = ways[j + ct[i]] + ways[j];
        }
    }
    mint ans = ways[N / 2] / div * fax[N / 2] * fax[N - N / 2];
    std::cout << ans.v << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    spit_fax(5e5);
    int T; std::cin >> T; while(T--) { solve(); }
}
#include <bits/stdc++.h>

using std::vector, std::min, std::max;

template<size_t z> using ints = std::array<int, z>;

#define long long long

template<int MOD> struct mint {
	int v;
	mint(long _v = 0):v(int(_v % MOD)) { v += (v < 0) * MOD; }
	friend mint operator+(mint a, mint b) { return a.v + b.v; }
	friend mint operator-(mint a, mint b) { return a.v - b.v; }
	friend mint operator*(mint a, mint b) { return (long)a.v*b.v; }
	friend mint operator/(mint a, mint b) { return a * inv(b); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mint inv(mint a) { return pow(a, MOD-2); }
};
using mi = mint<998244353>;

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int N; std::cin >> N;
    std::map<int, vector<int>> has;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            int x; std::cin >> x;
            has[x].push_back(i);
        }
    }

    vector<int> at(N);
    vector<int> cur(7);
    cur[0] = N;
    mi div = pow(inv(mi(6)), N);
    auto calc = [&]() {
        mi res = 1;
        for (int i = 0; i <= 6; i++) {
            res = res * pow(mi(i), cur[i]);
        }
        return res;
    };
    //div divies by 36 i think
    mi ans = 0;
    for (auto [x, is] : has) {
        //how do we deal with duplicates, exactly?
        //we can calculate the normal probability
        //without these elements
        //then calculate any variation without them doing that
        std::map<int, int> bruh;
        for (int i : is) {
            bruh[i]++;
            if (bruh[i] != 1) { continue; }
            cur[at[i]]--;
        }
        mi ways = calc();
        //find all ways
        mi all_ways = 1;
        mi bad_ways = 1;
        //find ways that we are
        for (auto [i, inc] : bruh) {
            bad_ways = bad_ways * at[i];
            at[i] += inc;
            all_ways = at[i] * all_ways;
            cur[at[i]]++;
        }
        ways = ways * (all_ways - bad_ways);
        ans = ans + ways * x;
    }
    ans = ans * div;
    std::cout << ans.v << "\n";
}
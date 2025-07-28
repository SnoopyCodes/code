#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

template<int MOD> struct mint {
	int v; mint(long _v = 0):v(int(_v % MOD)) { v += (v < 0) * MOD; }
	mint operator+(mint x) { return v + x.v; }
	mint operator-(mint x) { return v - x.v; }
	mint operator*(mint x) { return (long)v * x.v; }
	mint operator/(mint x) { return (*this) * inv(x); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mint inv(mint a) { return pow(a, MOD-2); }
};
using mi = mint<998244353>;

void solve() {
    int N, Q; std::cin >> N >> Q;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    //min(a_i, b_i)
    //oh we want largest value
    //so note that we only ever choose a certain
    //selection of them
    //optimally we match mins to mins, so in sorted order (i think)
    //we can compute initial.
    //updates.! if in the sorted order one surpasses another we just divide and recalculate.
    vector<int> sortA = A, sortB = B;
    std::sort(sortA.begin(), sortA.end());
    std::sort(sortB.begin(), sortB.end());

    mi ans = 1;
    for (int i = 0; i < N; i++) {
        ans = ans * min(sortA[i], sortB[i]);
    }
    std::cout << ans.v << " ";
    while (Q--) {
        int t; std::cin >> t;
        int p; std::cin >> p; p--;
        int ind;
        if (t & 1) {
            ind = std::upper_bound(sortA.begin(), sortA.end(), A[p]) - sortA.begin() - 1;
            //we have the last occurrence
            A[p]++;
        }   else {
            ind = std::upper_bound(sortB.begin(), sortB.end(), B[p]) - sortB.begin() - 1;
            B[p]++;
        }
        ans = ans / min(sortA[ind], sortB[ind]);
        t & 1 ? sortA[ind]++ : sortB[ind]++;
        ans = ans * min(sortA[ind], sortB[ind]);

        std::cout << ans.v << " \n"[Q == 0];
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
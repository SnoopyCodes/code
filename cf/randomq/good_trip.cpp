#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;

template<int MOD> struct mint {
	int v; mint(long _v = 0):v(_v % MOD) { v += (v < 0) * MOD; }
	mint operator+(mint x) { return v + x.v; }
	mint operator-(mint x) { return v - x.v; }
	mint operator*(mint x) { return (long) v * x.v; }
	mint operator/(mint x) { return (*this) * pow(x, MOD - 2); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
};
using mi = mint<int(1e9 + 7)>;

template<class T> using vt = vector<T>;

void solve() {
    int N, M, K; cin >> N >> M >> K;
    mi one_round = 0;
    for (int i = 0; i < M; i++) {
        int a, b, f; cin >> a >> b >> f;
        one_round = one_round + f;
    }
    mi all_rounds = one_round * K / (mi(N) * (N - 1) / 2);
    /*
    boils down to: M out of C(N, 2) boxes.
    each time you choose one of M boxes, add the value of it, and increase its value by one.
    */
    mi exp = 0;  //expected value if we choose from M edges.
    mi prob_choose = mi(M) / (mi(N) * (N - 1) / 2);
    for (int i = 0; i < K; i++) {
        all_rounds = all_rounds + exp * prob_choose;
        exp = exp + prob_choose / M;
    }
    cout << all_rounds.v << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
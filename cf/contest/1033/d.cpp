#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

const int MOD = 1e9 + 7;

template<int MOD> struct mint {
	int v;
	mint(long v = 0):v(int(v % MOD)) { v += (v < 0) * MOD; }
	friend mint operator+(mint a, mint b) { return a.v + b.v; }
	friend mint operator-(mint a, mint b) { return a.v - b.v; }
	friend mint operator*(mint a, mint b) { return (long)a.v*b.v; }
	friend mint operator/(mint a, mint b) { return a * inv(b); }
	friend mint pow(mint a, long p) { return p ? pow(a * a, p / 2) * (p & 1 ? a : 1) : 1; }
	friend mint inv(mint a) { return pow(a, MOD-2); }
};
using mi = mint<int(1e9 + 7)>;

void solve() {
    int A, B, K; std::cin >> A >> B >> K;
    int N = ((long) (A - 1) * K + 1) % MOD;
    //how does it cycle?
    //i guess they can do 
    //how many arrangements before
    //the next column with 1s in the right spot
    //N choose A
    //N choose A repeated (B - 1) times + 1?
    //how do we compute large N?
    //that was not the answer
    mi M = 1;
    mi fac = 1;
    for (int i = 1; i <= A; i++) {
        fac = fac * i;
    }
    for (int i = N; i > N - A; i--) {
        M = M * i;
    }
    M = M * K * (B - 1) / fac + 1;
    std::cout << N << " " << M.v << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
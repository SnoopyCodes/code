#include <bits/stdc++.h>

using namespace std;

#define am(x, y) (((x) + (y)) % MOD)
#define mm(x, y) (((x) * (y)) % MOD)
#define long long long

const int MOD = 1e9 + 7;

constexpr long exp(long x, long p) {
	long res = 1;
	for (; p; p /= 2) {
		if (p % 2 & 1) { res = res * x % MOD; }
		x = x * x % MOD;
	}
	return res;
}

constexpr long inv(long x) {
    return exp(x, MOD - 2);
}

const int DIV = 1e4;
constexpr long MDIV = inv(DIV);

template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    vector<long> P(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    //we want to find the parity of bits
    //this is done for each bit individually
    //then we just bitmask over it at the end
    array<long, 1024> chance{};
    chance[A[0]] = mm(P[0], MDIV);
    chance[0] = mm(DIV - P[0], MDIV);
    for (int i = 1; i < N; i++) {
        array<long, 1024> nchance{};
        for (int j = 0; j < 1024; j++) {
            nchance[j] = am(mm(mm(chance[j], (DIV - P[i])), MDIV),
                mm(chance[j ^ A[i]], mm(P[i],MDIV)));
        }
        swap(chance, nchance);
    }
    long ans = 0;
    for (int mask = 1; mask < 1024; mask = mask + 1) {
        ans = am(ans, mm(mm(chance[mask], mask), mask));
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
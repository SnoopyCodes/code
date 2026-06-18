#include <bits/stdc++.h>

using namespace std;
#define int long long
const int P = 998244353;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

int qp(int x, int p = P - 2) { return p ? (p & 1 ? x :1) * qp(x * x % P, p / 2) % P : 1; }

vector<int> fac, ifac;

int choose(int n, int r) { return n < r ? 0 : fac[n] * ifac[r] % P * ifac[n - r] % P; }
void prec(int n) {
	fac = ifac = vt<int>(n + 1, 1);
    for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % P;
	}
	ifac[n] = qp(fac[n]);
	for (int i = n - 1; i > 1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % P;
	}
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    prec(N);
    vt<int> diff(N + 2);
    vt<int> cont(N + 1); //how many ranges contain i?
    vt<int> inc(N + 1);
    for (int i = 0; i < N; i++) {
        int l, r; cin >> l >> r; r++;
        diff[l]++; diff[r]--;
        r--;
        if (l <= N / 2 && r >= (N + 1) / 2)
        if (l <= N - r) {
            inc[r]++;
        }   else {
            inc[l]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        cont[i] = cont[i-1] + diff[i];
    }
    int ans = 0;
    int num_range_both = 0;
    for (int i = 1; i < (double) N / 2; i++) {
        int j = N - i;
        num_range_both += inc[i] + inc[j] - (i == j ? inc[i] : 0);
        int total = cont[i] + cont[j] - num_range_both;
        if (total != N) {
            continue;
        }
        int only_i = cont[i] - num_range_both;
        int only_j = cont[j] - num_range_both;
        assert(only_i >= 0 && only_j >= 0);
        if (only_i > i || only_j > j) {
            continue;
        }
        (ans += choose(num_range_both, i - only_i)) %= P;
    }
    (ans *= 2) %= P;
    if (N % 2 == 0) {
        num_range_both += inc[N / 2];
        if (cont[N/2] * 2 - num_range_both == N) {
            (ans += choose(num_range_both, N/2 - cont[N/2] + num_range_both)) %= P;
        }
    }
    cout << ans << "\n";


}
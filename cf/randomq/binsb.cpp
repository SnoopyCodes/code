#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 998244353;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

int f(int a, int b) { return ((a + b) % MOD + MOD) % MOD; }

void solve() {
    int N, M; cin >> N >> M;
    vt<int> constraints(N, -1);
    while (M --> 0) {
        int l, r; cin >> l >> r; l--; r--;
        constraints[r] = max(constraints[r], l);
    }
    vt<ii<2>> dp(N, ii<2>{});
    dp[0] = { 1, 1 };
    vt<int> pfms0{ 0, 1, 2 }, pfms1{ 0, 1, 2 };
    int stop = -1;
    for (int i = 1; i < N; i++) {
        stop = max(stop, constraints[i]);
        dp[i][0] = f(pfms1.back(), -pfms1[stop + 1]);
        dp[i][1] = f(pfms0.back(), -pfms0[stop + 1]);
        pfms0.add(f(pfms0.back(), dp[i][0]));
        pfms1.add(f(pfms1.back(), dp[i][1]));
    }
    cout << f(dp[N-1][0], dp[N-1][1]) << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) { solve(); }
}
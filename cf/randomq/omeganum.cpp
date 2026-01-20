#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 998244353;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
#define rev(i, a, b) for (auto i=(a)-1; i>(b)-1; i--)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

int qp(int x, int p = MOD - 2)
    { return p ? 1ll * (p & 1 ? x : 1LL) * qp(1ll * x * x % MOD, p / 2) % MOD : 1; }

int dp[7][7][200000 + 5];
//yet another editorial problem
void solve() {
    int N, K; cin >> N >> K;
    int M = N + 1;
    vt<int> f(M);
    rep(i, 0, N) {
        int x; cin >> x;
        f[x]++;
    }

    vt<int> num(M);
    rep(i, 2, M) {
        if (num[i]) { continue; }
        for (int j = i; j < M; j += i) {
            num[j]++;
        }
    }
    
    vt<ii<7>> aux(M, ii<7>{}); //:= # of a_i it divides with num = j
    rep(i, 1, M) {
        for (int j = i; j < M; j += i) {
            aux[i][num[j]] += f[j];
        }
    }
    
    /*
    okay...
    oh do we go from pov of gcd?
    that is surely an observation of all time
    */

    int ans = 0;
    rev(i, M, 1) {
        //iterate across all
        rep(a, 0, 7) {
            rep(b, a, 7) {
                int c = num[i];
                if (a + b <= c) { continue; }
                if (a == b) {
                    dp[a][b][i] = aux[i][a] * (aux[i][b] - 1) / 2;
                }   else {
                    dp[a][b][i] = aux[i][a] * aux[i][b];
                }
                for (int j = i * 2; j < M; j += i) {
                    dp[a][b][i] -= dp[a][b][j];
                }
                (ans += (qp(a + b - c, K) * (dp[a][b][i] % MOD)) % MOD) %= MOD;
            }
        }
    }

    cout << ans << "\n";
    
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
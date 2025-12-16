#include <bits/stdc++.h>

using namespace std;

#define long long long
#define rep(i, a, b) for (auto i=a; i<(b); i++)

const int BIG = 1e9 + 7;
const long INF = 4e18 + 7e9;

template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;

template<class T> using vt = vector<T>;

void solve() {
    int N, K; cin >> N >> K;

    int maxv = -1;
    vt<int> inc;
    vt<int> ind;
    rep(i, 0, N) {
        int x; cin >> x;
        if (maxv >= x) { continue; }
        inc.push_back(x);
        ind.push_back(i);
        maxv = x;
    }

    //len(inc) <= K, len(ind) <= K
    //dp[current max][remaining k]
    vt dp(K + 1, vt(K + 1, 0));
    int M = size(inc);
    ind.push_back(N);
    rep(i, 0, M) {
        auto prev = dp;
        rep(j, 0, K + 1) {
            rep(k, 0, K + 1) {
                if (prev[j][k])
                dp[j][k] = max(dp[j][k], prev[j][k] + j * (ind[i + 1] - ind[i]));
            }
        }

        vt<int> maxprev(K + 1);
        rep(j, 0, inc[i] + 1) { //current max

            rep(k, 0, K - j + 1) {
                maxprev[j + k] = max(maxprev[j + k], prev[j][j + k]);
            }

            rep(k, 0, K - j + 1) { //remaining
                dp[j][k] = max(dp[j][k], maxprev[j + k] + j * (ind[i + 1] - ind[i]));
            }
        }
    }

    int ans = 0;
    rep(i, 0, K + 1) rep(j, 0, K + 1) ans = max(ans, dp[i][j]);
    cout << ans << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve(); 
}
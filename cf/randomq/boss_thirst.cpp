#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N, M; cin >> N >> M;
    vt profit(N, vt(M, -MOD * MOD));
    auto dpl = profit, dpr = profit;
    rep(i, 0, N) rep(j, 0, M) cin >> profit[i][j];
    
    /* base case setup */ {
        int val = 0;
        int minsum = 0;
        int goat = 0;
        vt<int> psum(M + 1);
        rep(i, 0, M) {
            psum[i + 1] = psum[i] + profit[0][i];
        }
        rep(i, 0, M) {
            
        }
    }
    rep(i, 1, N) {
        rep(j, 0, M) { //run right
            
        }
    }

    int ans = 0;
    rep(i, 0, M) ans = max({ ans, dpl[N-1][i], dpr[N-1][i] });
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
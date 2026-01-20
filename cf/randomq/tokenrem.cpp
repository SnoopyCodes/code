#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i, a, b) for (auto i = a; i <(b); i++)

void solve() {
    int N, M; cin >> N >> M;
    vt<vt<int>> dp(N + 1, vt<int>(N + 1));
    dp[0][0] = 1;
    rep(i, 1, N + 1) {
        rep(j, 0, i + 1) {
            //case 1: we didn't eat any balls
            //when did i start referring to this problem as eating balls?
            //that is pretty funny
            
        }
        cout << "\n";
    }
    int ans = 0;
    rep(i, 0, N + 1) (ans += dp[N][i]) %= M;
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
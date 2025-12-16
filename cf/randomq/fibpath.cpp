#include <bits/stdc++.h>

using namespace std;

#define long long long
const int  MOD = 998244353;
#define rep(i, a, b) for (auto i = a; i < (b); i++)
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
using vi = vt<int>;

void solve() {
    int N, M; cin >> N >> M;
    vt<long> vals(N);
    rep(i, 0, N) cin >> vals[i];
    vt<vi> G(N);

    //dp[i][next] = ways to get to i with next value this
    vt<map<long, int>> dp(N);
    while(M--) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        dp[v][vals[u] + vals[v]]++;
    }
    
    rep (i, 0, N) {
        
    }

    vi ord(N); rep (i, 0, N) ord[i] = i;
    ranges::sort(ord, [&](int i, int j) { return vals[i] < vals[j]; });

    int ans = 0;

    for (int u : ord) {
        for (int v : G[u]) if (vals[v] > vals[u] && dp[u].count(vals[v])) {
            (dp[v][vals[v] + vals[u]] += dp[u][vals[v]]) %= MOD;
        }
        for (auto [val, ways] : dp[u]) {
            (ans += ways) %= MOD;
        }
    }

    cout << ans << "\n";


}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve(); 
}
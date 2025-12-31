#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
#define rep(i,a,b) for(auto i=(a); i<(b);i++)

void solve() {
    int N, M, K; cin >> N >> M >> K;
    vt<vt<int>> G(N);
    vt<int> H(N);
    rep(i, 0, N) {
        cin >> H[i];
    }

    vt<int> in(N);
    while (M--) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].add(v);
        in[v]++;
    }
    queue<int> q;
    vt<int> dp(N);
    long ans = 0;
    int st_h = MOD;
    rep (i, 0, N) {
        if (in[i] == 0) q.push(i), st_h = min(st_h, H[i]);
    }
    auto save = in;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            bool inc = H[v] < H[u];
            dp[v] = max(dp[v], dp[u] + inc);
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    vt<int> ord(N); iota(begin(ord), end(ord), 0);
    ranges::sort(ord, [&](int i, int j) { return H[i] < H[j]; });

    long new_maxes = 0;
    rep (i, 0, N) {
        new_maxes = max((long) dp[i] * K + H[i], new_maxes);
    }
    ans = new_maxes - st_h;
    rep (i, 0, N - 1) {
        int j = ord[i];
        st_h = H[ord[i + 1]];
        //convert these
        if (dp[j] == 0) {
            q.push(j);
            dp[j] = 1;
            new_maxes = max(new_maxes,(long) K + H[j]);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : G[u]) {
                bool inc = H[v] < H[u];
                if (dp[u] + inc > dp[v]) {
                    dp[v] = dp[u] + inc;
                    new_maxes = max(new_maxes, (long) dp[v] * K + H[v]);
                    q.push(v);
                }
            }
        }
        ans = min(ans, new_maxes - st_h);
    }
    cout << ans << "\n";
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) solve();
}
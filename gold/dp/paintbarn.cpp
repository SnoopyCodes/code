#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
vector<vector<int>> barns;
vector<array<ll, 3>> ways;
vector<bool> done;
vector<int> visited;
void dfs(int u, int from) {
    if (done[u]) { return; }
    visited[u] = true;
    ways[u] = {1, 1, 1};
    for (int v : barns[u]) {
        if (v == from) { continue; }
        dfs(v, u);
        ways[u][0] *= (ways[v][1] + ways[v][2]);
        ways[u][0] %= MOD;
        ways[u][1] *= (ways[v][0] + ways[v][2]);
        ways[u][1] %= MOD;
        ways[u][2] *= ways[v][0] + ways[v][1];
        ways[u][2] %= MOD;
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    int N, K; cin >> N >> K;
    barns.resize(N);
    done.resize(N);
    visited.resize(N);
    ways.resize(N, {0,0,0});
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        barns[u].push_back(v);
        barns[v].push_back(u);
    }
    for (int i = 0; i < K; i++) {
        int u, c; cin >> u >> c; u--; c--;
        ways[u][c]++;
        done[u] = true;
    }
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        if (!done[i] && !visited[i]) {
            dfs(i, -1);
            ans *= (ways[i][0] + ways[i][1] + ways[i][2]) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << "\n";

}
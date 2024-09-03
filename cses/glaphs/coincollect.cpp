#include <bits/stdc++.h>
//pretty clean
using namespace std;
using ll = long long;
vector<vector<int>> rooms;
vector<vector<int>> comps;
vector<int> back;
vector<int> in_comp;

vector<ll> comp_coins;
vector<int> coins;
int euler = 0, comp = 0;
stack<int> path;

void dfs(int u) {
    back[u] = euler;
    int in = euler;
    euler++;
    path.push(u);
    for (int v : rooms[u]) {
        if (back[v] == -1) { dfs(v); }
        if (in_comp[v] == -1) { back[u] = min(back[u], back[v]); }
    }
    if (back[u] == in) {
        comps.push_back({});
        comp_coins.push_back(0);
        int v = -1;
        while (v != u) {
            v = path.top();
            path.pop();
            comps[comp].push_back(v);
            in_comp[v] = comp;
            comp_coins[comp] += coins[v];
        }
        comp++;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    rooms.resize(N);
    coins.resize(N);
    back.resize(N, -1);
    in_comp.resize(N, -1);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        rooms[u].push_back(v);
    }
    for (int i = 0; i < N; i++) {
        if (back[i] == -1) { dfs(i); }
    }
    //tarjans gives a reversed toposort, so we need to reverse it
    for (int i = 0; i < N; i++) {
        in_comp[i] = comp - in_comp[i] - 1;
    }
    reverse(comps.begin(), comps.end());
    reverse(comp_coins.begin(), comp_coins.end());
    vector<ll> dp = comp_coins;
    for (int i = 0; i < comp; i++) {
        for (int u : comps[i]) {
            for (int v : rooms[u]) {
                if (in_comp[v] != in_comp[u]) {
                    int c = in_comp[v];
                    dp[c] = max(dp[c], dp[i] + comp_coins[c]);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < comp; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}
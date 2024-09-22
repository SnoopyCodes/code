#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
vector<vector<int>> tree;
vector<array<ll, 2>> ways;  //0-- black, 1-- white
void dfs(int u, int from) {
    //ways to color htis node white:
    //all the ways
    ways[u] = {1, 1};
    for (int v : tree[u]) {
        if (v == from) { continue; }
        dfs(v, u);
        ways[u][0] *= (ways[v][1] + ways[v][0]);
        ways[u][0] %= MOD;
        ways[u][1] *= ways[v][0];
        ways[u][1] %= MOD;
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    tree.resize(N);
    ways.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }
    dfs(0, -1);
    cout << (ways[0][0] + ways[0][1]) % MOD << "\n";
}
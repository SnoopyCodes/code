#include <bits/stdc++.h>

using namespace std;
#define long long long
const int MOD = 998244353;

vector<vector<int>> T;
int ans;
int dfs(int u, int p) {
    int prod = 1;
    for (int v : T[u]) {
        if (v == p) { continue; }
        prod = (long) prod * (dfs(v, u) + 1) % MOD;
    }
    ans = (ans + prod) % MOD;
    return prod;
}

void solve() {
    int N; cin >> N;
    T.clear();
    T.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    ans = 1;
    dfs(0, -1);
    cout << ans << "\n";
}

//the problem rn is:
//select subset of children and multiply all children subsizes together
//do this for every subset
//consider adding oen child at a time
//what is prod?
//prod is number of ways to select
//therefore dp
//define dp[u] as number of ways to select stuff such that cond is satisfied in subtree
//and exactly than 1 node is on path through u
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
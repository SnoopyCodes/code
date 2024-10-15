
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
vector<vector<int>> tree;
vector<ll> atk;
vector<vector<ll>> res;
ll ans = 0;
const int lim = 23;
void dfs(int u, int from) {
    //define dp[u]
}
void solve() {
    int N; cin >> N;
    tree.clear(); tree.resize(N);
    atk.resize(N);
    res.clear(); res.resize(N, vector<ll>(lim, -1));
    for (int i = 0; i < N; i++) {
        cin >> atk[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
 
    //all monsters die in at most 23 rounds :sob:

    dfs(0, -1);

    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T--) { solve(); }
}
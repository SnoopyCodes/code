#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<vector<int>> tree;
vector<array<int, 2>> ranges;
ll ans = 0;
void dfs(int u, int par) {
    
}
void solve() {
    int N; cin >> N;
    tree.clear(); tree.resize(N);
    ranges.clear(); ranges.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    ans = 0;
    dfs(0, -1);
    cout << ans << "\n";
    //li and ri
    //maximize.
    //i doubt it works for every single one
    //oh wait it does unless it is a leaf

}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}
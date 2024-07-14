#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> vals;
vector<vector<int>> tree;
vector<bool> visited;
ll total = 0;
void dfs(int v, int from) {
    
    visited[v] = true;
    ll sum = 0;
    for (int x : tree[v]) {
        if (x == from) { continue; }
        dfs(x, v);
        sum += vals[x];
    }
    total += max(0LL, sum - vals[v]);
    vals[v] = max(vals[v], sum);
}
//im done its wrong
void solve() {
    int N; cin >> N;
    visited.resize(N);
    tree.resize(N);
    vals.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        tree[a].push_back(b);
    }
    dfs(0, -1);
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T) { T--; solve(); }
}
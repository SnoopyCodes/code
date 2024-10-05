#include <bits/stdc++.h>

using namespace std;
vector<vector<array<int, 2>>> tree;

void dfs(int u, int par) {
    map<int, vector<int>> m;  //max path, number of things
    for (auto const&[v, w] : tree[u]) {
        if (v == par) { continue; }
        dfs(v, u);
    }
    //now what?
    //we can easily calculate subtree size, max path weight to the current node
    //yeah
    //sort by max path weight and go!
    //hold up
    //what
    //def not
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    tree.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    dfs(0, -1);
    //okay well we need to calculate the answers for basically every single 
    //possible weight
    //obviously, we will dfs and move back up
    //wo de nao dai
}
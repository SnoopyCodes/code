#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> tree;
vector<int> order;
vector<int> leaves;  //leaves in subtree
vector<int> pots;  //pots in this room
int countleaves(int v, int from) {
    if (tree[v].size() == 1) { leaves[v] = 1; }
    for (int x : tree[v]) {
        if (x == from) { continue; }
        leaves[v] += countleaves(x, v);
    }
    return leaves[v];
}
int countpots(int v, int from) {
    int leafpots = 0;
    for (int x : tree[v]) {
        if (x == from) { continue; }
        leafpots += countpots(x, v);
    }
    return min(pots[v] + leafpots, leaves[v]);
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    tree.resize(N);
    order.resize(N);
    leaves.resize(N);
    pots.resize(N);
    for (int i = 0; i < N; i++) {
        int r; cin >> r; r--;
        order[i] = r;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    countleaves(0, -1);
    cout << leaves[0] << "\n";
    for (int i = 0; i < leaves[0]; i++) {
        pots[order[i]]++;
    }
    int ans = countpots(0, -1);
    cout << ans << "\n";
}
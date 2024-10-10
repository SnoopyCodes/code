#include <bits/stdc++.h>

using namespace std;
//shortest and cleanest? :P
using ll = long long;
vector<vector<int>> tree;
vector<vector<ll>> pfx;
vector<vector<ll>> sfx;
vector<ll> ways;
int N, M;
void subtrees(int u, int from) {
    for (int v : tree[u]) {
        if (v == from) { continue; }
        subtrees(v, u);
    }
    //we also need to avoid taking into account parent..
    int sz = tree[u].size();
    pfx[u].resize(sz + 1, 1);
    sfx[u].resize(sz + 1, 1);
    for (int i = 0; i < sz; i++) {  //i will always be the neighbor
        ll mult = tree[u][i] != from ? (ways[tree[u][i]] + 1) : 1;
        pfx[u][i + 1] = pfx[u][i] * mult % M;
    }
    ways[u] = pfx[u].back();
    for (int i = sz - 1; i > -1; i--) {
        ll mult = tree[u][i] != from ? (ways[tree[u][i]] + 1) : 1;
        sfx[u][i] = sfx[u][i + 1] * mult % M;
    }
}
void calc(int u, int from, ll parfac) {
    parfac++;
    ways[u] = ways[u] * parfac % M;
    for (int i = 0; i < tree[u].size(); i++) {
        if (tree[u][i] == from) { continue; }
        ll mult = pfx[u][i] * sfx[u][i + 1] % M * parfac % M;
        calc(tree[u][i], u, mult);
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> M;
    tree.resize(N);
    pfx.resize(N);
    sfx.resize(N);
    ways.resize(N, 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    subtrees(0, -1);
    calc(0, -1, 0);
    for (int i = 0; i < N; i++) {
        cout << ways[i] << endl;
    }
}
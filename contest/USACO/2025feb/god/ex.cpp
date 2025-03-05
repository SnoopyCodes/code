#include <bits/stdc++.h>

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))


using namespace std;
template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;

vec<vec<int>> tree;
vec<int> val;

int dfs(int u) {
    int sum = val[u];
    for (int v : tree[u]) {
        sum += dfs(v);
    }
    return sum;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    tree.resize(N);
    val.resize(N);
    rep(i, N - 1) {
        int u, v; cin >> u >> v; u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}
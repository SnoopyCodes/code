#include <bits/stdc++.h>

using std::min, std::max;

template<size_t z> using ints = std::array<int, z>;
template<class T> using list = std::vector<T>;

/*
you are a given a tree.
find the maximum sum of longest paths in the resulting graph(s) if any one edge is removed.
*/
list<list<int>> T;

list<ints<2>> res;
void dfs_dp(int u, int p) {
    int p1 = 0, p2 = 0;
    int maxd = 0;
    for (int v : T[u]) {
        if (v == p) { continue; }
        dfs_dp(v, u);
        maxd = max(res[v][1], maxd);
        if (res[v][0] + 1 > p1) { p1 = res[v][0] + 1; }
        else if (res[v][0] + 1 > p2) { p2 = res[v][0] + 1; }
    }
    maxd = max(maxd, p1 + p2);
    res[u] = { p1, maxd };
}

int dfs_ans(int u, int p, int top, int par_best) {
    int best = par_best + res[u][1];
    /*
    a few cases: top combines with bottom
    best of this subtree already.
    try to form the best diameter ignoring the child
    */
   
    
    
    for (int v : T[u]) {
        best = max(top + res[v][0], best);
        
    }
    return best;
}

void solve() {
    int N; std::cin >> N;
    T.clear(); T.resize(N); res.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; std::cin >> u >> v; u--; v--;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    /*
    if a node is not part of the diameter, the answer for if we split that and its parent is:
    diameter of its subtree + overall tree diameter.
    else it is diameter of subtree from v and dimaeter subtree from u
    */

    dfs_dp(0, -1);
    std::cout << dfs_ans(0, -1, 0, -N) << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
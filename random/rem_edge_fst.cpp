#include <bits/stdc++.h>

using std::min, std::max;

template<size_t z> using ints = std::array<int, z>;
template<class T> using list = std::vector<T>;

/*
you are a given a tree.
find the maximum sum of longest paths in the resulting graph(s) if any one edge is removed.
*/
list<list<int>> T;

list<int> dist;
void dfs_far(int u, int p, int d) {  //res contains dist from node
    dist[u] = d;
    for (int v : T[u]) {
        if (v == p) { continue; }
        dfs_far(v, u, d + 1);
    }
}

std::array<list<ints<2>>, 2> from;
void dfs_dp(int u, int p, bool z) {
    int p1 = 0, p2 = 0;
    int maxd = 0;
    for (int v : T[u]) {
        if (v == p) { continue; }
        dfs_dp(v, u, z);
        maxd = max(from[z][v][1], maxd);
        if (from[z][v][0] + 1 > p1) { p1 = from[z][v][0] + 1; }
        else if (from[z][v][0] + 1 > p2) { p2 = from[z][v][0] + 1; }
    }
    maxd = max(maxd, p1 + p2);
    from[z][u] = { p1, maxd };
}

ints<2> dfs_ans(int u, int p, int dv, int dia) {
    ints<2> res{};
    if (u == dv) { res[1] = true; }
    for (int v : T[u]) {
        if (v == p) { continue; }
        ints<2> other = dfs_ans(v, p, dv, dia);
        res[1] |= other[1];
        res[0] = max(res[0], other[0]);
    }
    if (res[1] && p != -1) { // we are on diameter and p is valid
        res[0] = max(res[0], from[1][p][1] + from[0][u][1]);
    }   else if (!res[1]) {
        res[0] = max(res[0], from[0][u][1] + dia);
    }
    return res;
}

void solve() {
    int N; std::cin >> N;
    T.clear(); T.resize(N); dist.resize(N); from[0].resize(N); from[1].resize(N);
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
    dfs_far(0, -1, 0);
    int du = std::max_element(dist.begin(), dist.end()) - dist.begin();
    dfs_far(du, -1, 0);
    int dv = std::max_element(dist.begin(), dist.end()) - dist.begin();
    int diameter_len = *std::max_element(dist.begin(), dist.end());

    dfs_dp(du, -1, 0), dfs_dp(dv, -1, 1);
    std::cout << dfs_ans(du, -1, dv, diameter_len)[0] << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
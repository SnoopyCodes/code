#include <bits/stdc++.h>

using std::min, std::max;

template<size_t z> using ints = std::array<int, z>;
template<class T> using list = std::vector<T>;

/*
you are a given a tree.
find the maximum sum of longest paths in the resulting graph(s) if any one edge is removed.
*/
void dfs_far(int u, int p, int d, list<list<int>> &T, list<int> &res) {  //res contains dist from node
    res[u] = d;
    for (int v : T[u]) {
        if (v == p) { continue; }
        dfs_far(v, u, d + 1, T, res);
    }
}

void dfs_dp(int u, int p, list<list<int>> &T, list<ints<2>> &res) {
    int p1 = 0, p2 = 0;
    int maxd = 0;
    for (int v : T[u]) {
        if (v == p) { continue; }
        dfs_dp(v, u, T, res);
        maxd = max(res[v][1], maxd);
        if (res[v][0] + 1 > p1) { p1 = res[v][0] + 1; }
        else if (res[v][0] + 1 > p2) { p2 = res[v][0] + 1; }
    }
    maxd = max(maxd, p1 + p2);
    res[u] = { p1, maxd };
}

ints<2> dfs_ans(int u, int p, int dv, int dia, list<list<int>> &T, list<ints<2>> &fu, list<ints<2>> &fv) {
    ints<2> res{};
    if (u == dv) { res[1] = true; }
    for (int v : T[u]) {
        if (v == p) { continue; }
        ints<2> other = dfs_ans(v, p, dv, dia, T, fu, fv);
        res[1] |= other[1];
        res[0] = max(res[0], other[0]);
    }
    if (res[1] && p != -1) { // we are on diameter and p is valid
        res[0] = max(res[0], fv[p][1] + fu[u][1]);
    }   else if (!res[1]) {
        res[0] = max(res[0], fv[u][1] + dia);
    }
    return res;
}

void solve() {
    int N; std::cin >> N;
    list<list<int>> T(N);
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
    list<int> dist;
    dfs_far(0, -1, 0, T, dist);
    int du = std::max_element(dist.begin(), dist.end()) - dist.begin();
    dfs_far(du, -1, 0, T, dist);
    int dv = std::max_element(dist.begin(), dist.end()) - dist.begin();
    int diameter_len = *std::max_element(dist.begin(), dist.end());

    list<ints<2>> from_u(N), from_v(N);
    dfs_dp(du, -1, T, from_u), dfs_dp(dv, -1, T, from_v);
    std::cout << dfs_ans(du, -1, dv, diameter_len, T, from_u, from_v)[0] << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
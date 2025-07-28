#include <bits/stdc++.h>

using std::min, std::max;

template<size_t z> using ints = std::array<int, z>;
template<class T> using list = std::vector<T>;
template<class T> void scan(T &x) { std::cin >> x; }
template<class T, class... Ts> void scan(T &x, Ts&... z) { scan(x); scan(z...); }

list<list<int>> T;

list<int> dist;
void dfs_far(int u, int p, int d) {
    dist[u] = d;
    for (int v : T[u]) {
        if (v == p) { continue; }
        dfs_far(v, u, d + 1);
    }
}

std::array<list<ints<2>>, 2> from;
int ans;
bool dfs_dp(int u, int p, int dv) {
    int p1 = 0, p2 = 0, maxd = 0;
    bool on_path = u == dv;
    bool z = dv != -1;
    for (int v : T[u]) {
        if (v == p) { continue; }
        on_path |= dfs_dp(v, u, dv);
        maxd = max(from[z][v][1], maxd);
        if (from[z][v][0] + 1 > p1) {
            p2 = max(p1, p2);
            p1 = from[z][v][0] + 1;
        }
        else if (from[z][v][0] + 1 > p2) { p2 = from[z][v][0] + 1; }
    }
    maxd = max(maxd, p1 + p2);
    from[z][u] = { p1, maxd };
    if (dv != -1) {
        if (on_path) {
            ans = max(from[z][u][1] + from[!z][p][1], ans);
        }   else {
            ans = max(from[z][u][1] + dist[dv], ans);
        }
    }
    return on_path;
}

void solve() {
    int N; scan(N);
    T.clear(); T.resize(N); dist.resize(N); from[0].resize(N); from[1].resize(N);
    ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int u, v; scan(u, v); u--; v--;
        
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

    dfs_dp(dv, -1, -1), dfs_dp(du, -1, dv);
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
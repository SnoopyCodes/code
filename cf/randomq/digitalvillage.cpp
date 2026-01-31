#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

struct DSU {
    int N;
    vector<int> p, s;
    vt<int> contrib;
    vt<int> aug; //# of needed
    DSU(int n):N(n), p(N), s(N, 1), aug(N), contrib(N) { while (n--) p[n] = n; }
    int par(int u) { return p[u] != u ? p[u] = par(p[u]) : u; }
    bool unite(int u, int v, int w) {
        u = par(u), v = par(v);
        if (u == v) { return false; }
        if (s[u] < s[v] && !aug[u]) { swap(u, v); } //default mst speed
        if (aug[u] && aug[v]) { //just merge u in
            contrib[u] += aug[v] * w;
            aug[u] += aug[v];
            aug[v] = 0;
        }
        s[u] += s[v];
        p[v] = u;
        return N--;
    }
};

void dfs(int u, int p, int src, vt<vt<ii<2>>> &T, DSU &cc, int expense, vt<vt<int>> &cost) {
    if (cc.aug[u] && u != src) {
        cost[src][u] = expense;    
        return;
    }
    for (auto [v, w] : T[u]) {
        if (v == p) { continue; }
        dfs(v, u, src, T, cc, max(expense, w), cost);
    }
}

void solve() {
    int N, M, K; cin >> N >> M >> K;
    vt<int> need(K);
    vt<vt<ii<2>>> T(N);
    
    rep(i, 0, K) {
        cin >> need[i], need[i]--;
    }
    vt<ii<3>> E(M);
    DSU mst(N);
    /*
    think kruskals
        each server serves a certain amount of ppl
        put a cost up with it
        now, to remove a server, we have to select a server, examine where it goes to
        we only ever look at edges in the mst
        but anyways
        consider only those that can see each other
        initially just calculate it with dfs, and update it like prims!
    */


    rep(i, 0, M) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        E[i] = { u, v, w };
    }
    vt<vt<int>> cost(N, vt<int>(N, MOD * MOD));
    DSU cc(N);
    rep(i, 0, K) {
        cc.aug[need[i]] = 1;
    }
    sort(begin(E), end(E), [](auto a, auto b) { return a[2] < b[2]; });
    for (auto [u, v, w] : E) {
        if (mst.unite(u, v, w)) {
            T[u].add({ v, w });
            T[v].add({ u, w });
        }
    }
    
    vt<int> best(N, -1);

    for (int i = 0; i < N; i++) {
        if (cc.aug[i]) {
            dfs(i, -1, i, T, cc, 0, cost);
            best[i] = ranges::min_element(cost[i]) - begin(cost[i]);
            cout << i << ": ";
            for (int j = 0; j < N; j++) {
                if (cost[i][j] != MOD * MOD) {
                    cout << j << "_" << cost[i][j] << " ";
                }
            }
            cout << "best: " << best[i] << endl;
            cout << "\n";
        }
    }
    auto dir = cost; //direct costs so we can update

    vt<int> ans(N);
    K--; while (K --> 0) {
        int u = -1;
        for (int i = 0; i < N; i++) {
            if (cc.aug[i] && (u == -1 || cost[i][best[i]] < cost[u][best[u]])) {
                u = i;
            }
        }
        int v = best[u];
        cout << "merging " << u << " " << v << endl;
        cout << cost[u][v] << endl;
        //we merge u into v
        ans[K] = ans[K + 1] + cost[u][v];
        cc.unite(v, u, dir[u][v]);
        for (int i = 0; i < N; i++) {
            if (cc.aug[i] && i != v && i != u) {
                if (dir[i][v] == MOD * MOD && dir[i][u] != MOD * MOD) { //can see u but not v
                    //can now see v
                    assert(dir[v][u] != MOD * MOD);
                    dir[i][v] = dir[v][i] = max(dir[v][u], dir[i][u]);
                }
                cost[i][u] = dir[i][u] = cost[u][i] = dir[u][i] = MOD * MOD;
                if (dir[i][v] != MOD * MOD) { //can see, recalculate edge weights for both.
                    cost[i][v] = dir[i][v] * cc.aug[i] - cc.contrib[i];
                    cost[v][i] = dir[i][v] * cc.aug[v] - cc.contrib[v];
                }
                if (best[i] == u || best[i] == v) {
                    //at most N^2 amortized? pray
                    best[i] = ranges::min_element(cost[i]) - begin(cost[i]); 
                }   else if (cost[i][v] < cost[i][best[i]]) {
                    best[i] = v;
                }
            }
        }
        dir[v][u] = dir[u][v] = cost[u][v] = cost[v][u] = MOD * MOD;
        best[v] = ranges::min_element(cost[v]) - begin(cost[v]);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
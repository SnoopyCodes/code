#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

vt<vt<int>> T;
vt<int> depth;
int N, a, b, da, db;

ii<2> dfs(int u, int p) { // { max chain, max diameter }
    ii<2> res{};
    for (int v : T[u]) {
        if (v == p) { continue; }
        depth[v] = depth[u] + 1;
        ii<2> comb = dfs(v, u);
        res[1] = max(res[1], comb[0] + 1 + res[0]);
        res[1] = max(res[1], comb[1]);
        res[0] = max(comb[0] + 1, res[0]);
    }
    return res;
}

void solve() {
    cin >> N >> a >> b >> da >> db; a--; b--;
    T.clear();
    T = vt<vt<int>>(N);
    depth = vt<int>(N);
    rep(i, 1, N) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].add(v);
        T[v].add(u);
    }
    depth[a] = 0; //DOES THIS NEED TO BE SAID BRO

    int diameter = dfs(a, -1)[1];

    if (diameter <= 2 * da) {
        cout << "Alice" << "\n";
        return;
    }
    if (db <= 2 * da) {
        cout << "Alice" << "\n";
        return;
    }
    if (depth[b] <= da) {
        cout << "Alice" << "\n";
    }   else {
        cout << "Bob" << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) { solve(); }
}
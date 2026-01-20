#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
#define int long long
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

const int N = 1e5 + 5;
int imp[N], sz[N], par[N];
vt<int> T[N];
set<ii<2>> ch[N];

void dfs(int u) {
    for (int v : T[u]) {
        if (v == par[u]) { continue; }
        par[v] = u;
        dfs(v);
        imp[u] += imp[v];
        sz[u] += sz[v];
        ch[u].insert({ sz[v], -v });
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, m; cin >> n >> m;
    rep(i, 0, n) {
        cin >> imp[i];
        sz[i] = 1;
    }
    par[0] = 0;
    rep(i, 1, n) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].add(v);
        T[v].add(u);
    }
    dfs(0);

    while (m--) {
        int t; cin >> t;
        int u; cin >> u; u--;
        if (t == 1) {
            cout << imp[u] << "\n";
        }   else {
            if (ch[u].empty()) {
                continue;
            }
            auto [_, v] = *ch[u].rbegin(); ch[u].erase({ _, v });
            int o = par[u];
            ch[o].erase({ sz[u], -u });
            v = -v;
            int oldv_imp = imp[v];
            imp[v] = imp[u];
            imp[u] = imp[u] - oldv_imp;

            int oldv_sz = sz[v];
            sz[v] = sz[u];
            sz[u] = sz[u] - oldv_sz;

            ch[v].insert({ sz[u], -u });

            par[v] = o;
            par[u] = v;
            ch[o].insert({ sz[v], -v });

        }
    }

}
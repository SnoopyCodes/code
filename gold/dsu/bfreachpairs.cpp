#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vt<bool> type(N);
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        type[i] = c == '1';
    }
    vt<set<int>> G(N);
    while (M--) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    
    for (int t = 0; t < N; t++) {
        int ct = 0;
        vt<bool> vis(N);
        vt<int> q(N);
        int s = 0, e = 0;
        for (int i = t; i < N; i++) {
            if (vis[i]) { continue; }
            int cur = 1;
            q[e++] = i;
            vis[i] = true;
            while (s < e) {
                int u = q[s++];
                for (int v : G[u]) {
                    if (!vis[v] && v > t) {
                        cur++;
                        q[e++] = v;
                        vis[v] = true;
                    }
                }
            }
            ct += cur * (cur - 1) / 2;
        }
        cout << ct << "\n";
        if (type[t]) {
            auto jit = G[t].begin();
            while (jit != G[t].end()) {
                auto kit = jit;
                kit++;
                for (; kit != G[t].end(); kit++) {
                    G[*jit].insert(*kit);
                    G[*kit].insert(*jit);
                }
                jit++;
            }
        }
        G[t].clear();
    }

}
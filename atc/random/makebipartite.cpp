#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

struct dsu {
    int ans = 0;
    vector<int> p, zero, parity, one;
    dsu(int n): p(n), zero(n, 1), parity(n), one(n){ while (n--) p[n] = n; }
    int find(int u) {
        if (p[u] != u) {
            int v = p[u];
            find(p[u]);
            parity[u] = parity[v] ^ 1;
        }
        return p[u];
    }
    bool unite(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) {
            return parity[u] ^ parity[v] ^ 1;
        }
        bool f = u == 1 && v == 2;
        if (rand() % 2) { swap(ru, rv); } //youll never see this coming
        // if (f) cout << ans << endl;
        // if (f) cout << zero[ru] << one[ru] << endl;
        // if (f) cout << parity[0] << " " << parity[1] << " " << parity[2] << endl;
        // if (f) cout << p[0] << " " << p[1] << " " << p[2] << endl;
        ans -= min(zero[rv], one[rv]);
        ans -= min(zero[ru], one[ru]);
        if (f) cout << ans << endl;
        if (parity[u] ^ parity[v]) {
            zero[ru] += zero[rv];
            one[ru] += one[rv];
        }   else {
            zero[ru] += one[rv];
            one[ru] += zero[rv];
        }
        // if (f) cout << zero[ru] << " " << one[ru] << endl;
        parity[rv] = parity[u] ^ parity[v] ^ 1;
        if (f) cout << parity[rv] << endl;
        p[rv] = u;
        ans += min(zero[ru], one[ru]);
        return true;
    }
};
/*
maintain distance from root?
we want all to be white at first. so each component needs
# of nodes on even ranks
and maintain parity of distance from root.
*/
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N>> Q;
    dsu cc(N);
    bool bad = false;
    while (Q --> 0) {
        int u, v; cin >> u >> v; u--; v--;
        if (!cc.unite(u, v)) {
            bad = true;
        }
        cout << (bad ? -1 : cc.ans) << "\n";
    }

}
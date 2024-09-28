#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> barns;
int dfs(int u, int from, int k) {  //path length through this node
    map<int, int> m;  //desperation
    for (int v : barns[u]) {
        if (v == from) { continue; }
        int res = dfs(v, u, k);
        if (res < 0) { return -1; }
        res = (res + 1) % k;
        if (res == 0) { continue; }  //naturally forms a path, ignore
        if (m[k - res]) { m[k - res]--; }
        else { m[res]++; }
    }
    int take = 0;

    for (auto p : m) {
        if (p.second == 0) { continue; }
        if (!take && p.second == 1) { take = p.first; }
        else { return -1; }
    }
    return take;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    int N; cin >> N;
    barns.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        barns[u].push_back(v);
        barns[v].push_back(u);
    }
    for (int i = 0; i < N - 1; i++) {
        if ((N - 1) % (i + 1) != 0) { cout << 0;  continue; }
        cout << (dfs(0, -1, i + 1) % (i + 1) == 0);
    }
}
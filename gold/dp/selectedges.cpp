#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<vector<array<int, 2>>> tree;
vector<int> d;
array<ll, 2> dfs(int u, int from) {
    array<ll, 2> res{0,(ll)-1e18};
    priority_queue<ll> pq;  //the most delta we get
    for (auto const&[v, w] : tree[u]) {
        if (v == from) { continue; }
        auto const&[amt, loss] = dfs(v, u);
        res[0] += amt;
        if (w + loss - amt > 0) { pq.push({w + loss - amt}); }
    }
    int i = 0;
    while (i < d[u] && !pq.empty()) {
        res[1] = res[0];
        res[0] += pq.top();
        pq.pop();
        i++;
    }
    if (i < d[u]) {
        res[1] = res[0];
    }
    return res;
    
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    tree.resize(N);
    d.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    cout << dfs(0, -1)[0] << "\n";
}
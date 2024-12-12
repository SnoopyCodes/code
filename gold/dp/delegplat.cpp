#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;


//return the length of the smallest path in subtree, or -1 if there are too many
//we can also combine paths
//but only combine two
//no we canc ombine muiltiple

int K;
int dfs(int u, int p) {
    if (tree[u].size() == 1 && p != -1) { return 1; }
    vector<int> reses;
    multiset<int> ms;
    for (int v : tree[u]) {
        if (v == p) { continue; }
        int res = dfs(v, u);
        if (res == -1) { return -1; }
        reses.push_back(res);
        ms.insert(res);
    }
    sort(reses.begin(), reses.end());
    vector<int> pass(reses.size());
    bool atleast = true; //if we can pair all so this subtree is satisfied
    while (ms.size() > 1) {
        int cur = *ms.begin(); ms.erase(ms.begin());
        if (ms.lower_bound(K - cur) == ms.end()) { atleast = false; break; }
    }
    //this is so sad
    if (ms.size() && *ms.begin() < K) { atleast = false; }
    if (!atleast && p == -1) { return -1; }
    //now try binary searching on the thing we can return
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("deleg.in", "r", stdin);
    //freopen("deleg.out", "w", stdout);
    int N; cin >> N;
    tree.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int s = 0, e = N + 1;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        K = m;
        cout << K << "\n";
        if (dfs(0, -1) >= K) { s = m; }
        else { e = m; }
        cout << "\n";
    }
    cout << s << endl;
}
#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int N;
    vector<int> root, sizes;
    void init(int _N) {
        int N = _N;
        root.resize(N);
        sizes.resize(N, 1);
        for (int i = 0; i < N; i++) { root[i] = i; }
    }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool merge(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (sizes[ru] < sizes[rv]) { swap(ru, rv); }
        sizes[ru] += sizes[rv];
        root[rv] = ru;
        return true;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    //benchmark dsu time!
    DSU cc; cc.init(N);
    const int MOD = 998244353;
    vector<int> pre(Q);
    pre[0] = 1;
    for (int i = 1; i < Q; i++) {
        pre[i] = 2 * pre[i-1] % MOD;
    }
    int ans = 0;
    //i had to google translate to figure out the weird output lol
    vector<bool> answers;
    while (Q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 0) {
            cc.merge(u, v);
        }   else {
            answers.push_back(cc.find(u) == cc.find(v));
        }
    }
    int j = 0;
    for (int i = answers.size() - 1; i > -1; i--) {
        ans = (ans + pre[j++] * answers[i]) % MOD;
    }
    cout << ans << "\n";

}
#include <bits/stdc++.h>

using namespace std;

//dyna
struct DSU {
    int N;
    unordered_map<int, int> root;
    unordered_map<int, int> sizes;
    int find(int u) {
        if (!root.count(u)) { return u; }
        root[u] = find(root[u]);
        return root[u];
    }
    int sz(int u) {
        if (!sizes.count(u)) { return 1; }
        return sizes[u];
    }
    bool merge(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (sz(ru) < sz(rv)) { swap(ru, rv); }
        sizes[ru] = sz(ru) + sz(rv);
        root[rv] = ru;
        return true;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    DSU cc;
    vector<bool> alive(N);
    priority_queue<array<int, 2>> pq;
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        pq.push({k, i});
    }
    long long ans = 0;
    while (!pq.empty()) {
        auto [h, i] = pq.top();
        pq.pop();
        alive[i] = true;
        if (i > 0 && alive[i-1]) { cc.merge(i, i - 1); }
        if (i + 1 < N && alive[i + 1]) { cc.merge(i, i + 1); }
        ans = max(ans, (long long) cc.sz(cc.find(i)) * h);
    }
    cout << ans << "\n";
}
#include <bits/stdc++.h>

using namespace std;
struct DSU {
    int N;
    vector<int> root;
    vector<int> sizes;
    void init(int N) {
        root.resize(N);
        sizes.resize(N, 1);
        for (int i = 0; i < N; i++) { root[i] = i; }
    }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) { return false; }
        if (sizes[u] < sizes[v]) { swap(u, v); }
        sizes[u] += sizes[v];
        root[v] = u;
    }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}
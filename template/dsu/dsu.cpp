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
    
}
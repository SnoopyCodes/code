#include <bits/stdc++.h>

using namespace std;

/*
all pairs is annoying.
for a range [l, r] instead find for each i in [l, r)
the time when i connects to i + 1.
note that this is equivalent to CSES New Roads Queries
the answer is the maximum in the range—segtree.
In summary, I have no idea what a KRT is.
*/

template<class T> using vt = vector<T>;

vt<int> seg;
int S;
int query(int l, int r) {
    int res = 0;
    for (l += S, r += S; l < r; l >>= 1, r >>= 1) {
        if (l & 1) { res = max(res, seg[l++]); }
        if (r & 1) { res = max(res, seg[--r]); }
    }
    return res;
}

vt<int> dsu, sz, weight;
#define union its_called_union_find_not_merge_find
int find(int u) {
    return dsu[u] != u ? find(dsu[u]) : u;
}
void union(int u, int v, int w) {
    u = find(u), v = find(v);
    if (u == v) { return; }
    if (sz[u] < sz[v]) { swap(u, v); }
    sz[u] += sz[v];
    dsu[v] = u;
    weight[v] = w;
}
int weight_on_path(int u, int v) {  //idk how this works credit to eysbutno just dont wanna binlift
    int res = 0;
    while (u != v) {
        if (weight[u] > weight[v]) { swap(u, v); }
        res = weight[u];
        u = dsu[u];
    }
    return res;
}

void solve() {
    int N, M, Q; cin >> N >> M >> Q;
    dsu.resize(N), sz.resize(N, 1), weight.resize(N, M + 1);
    iota(dsu.begin(), dsu.end(), 0);
    ranges::fill(sz, 1);
    ranges::fill(weight, M + 1);
    S = N - 1;
    seg.resize(2 * S);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        union(u, v, i + 1);
    }
    for (int i = 0; i < S; i++) {
        seg[i + S] = weight_on_path(i, i + 1);
    }
    for (int i = S - 1; i > 0; i--) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
    while (Q--) {
        int l, r; cin >> l >> r; l--; r--;
        cout << query(l, r) << " \n"[!Q];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
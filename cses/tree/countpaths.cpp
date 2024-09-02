#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> tree;
int euler;
vector<int> order;
vector<int> depth;
vector<int> beg;
vector<int> stop;
vector<int> par;
void dfs(int v, int from, int d) {
    order.push_back(v);
    depth[v] = d;
    beg[v] = euler;
    par[v] = from;
    euler++;
    for (int u : tree[v]) {
        if (u == from) { continue; }
        dfs(u, v, d+1);
    }
    stop[v] = euler;
}
template<typename T>
struct SegTree {
    int SN;
    int DN;
    vector<T> data;
    virtual T def() const { return 0; }
    virtual T comb(T t1, T t2) const { return t1 + t2; }
    void build(const vector<T>& v) {
        SN = v.size();
        DN = v.size();
        SN = 1 << (1 + __lg(SN - 1));
        data.resize(2 * SN);
        for (int i = 0; i < DN; i++) { data[i + SN] = v[i]; }
        for (int i = SN - 1; i > 0; i--) { data[i] = comb(data[2 * i], data[2 * i + 1]); }
    }
    void alter(int i, T dat) {
        data[i + SN] = dat;
        for (i = (i + SN) / 2; i > 0; i /= 2) {
            data[i] = comb(data[2 * i], data[2 * i + 1]);
        }
    }
    T query(int l, int r) {
        T ansl = def();
        T ansr = def();
        for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
            if (l & 1) { ansl = comb(ansl, data[l++]); }
            if (r & 1) { ansr = comb(data[--r], ansr); }
        }
        return comb(ansl, ansr);
    }
};
struct LCAC : public SegTree<int> {
    int deff;
    int def() const override { return deff; }
    void setdef(int x) { deff = x; }
    int comb(int t1, int t2) const override { return depth[t1] < depth[t2] ? t1 : t2; }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    tree.resize(N);
    depth.resize(N);
    beg.resize(N);
    stop.resize(N);
    par.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, -1, 0);
    int lowest = 0;
    for (int i = 1; i < N; i++) {
        lowest = depth[i] > depth[lowest] ? i : lowest;
    }
    LCAC lcac;
    lcac.build(order);
    lcac.setdef(lowest);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        if (beg[a] > beg[b]) { swap(a, b); }
        //find lca
        int lca;
        if (a == b) { lca = a; }
        else { lca = par[lcac.query(beg[a] + 1, beg[b] + 1)]; }
        //now wtf do we do
    }
}
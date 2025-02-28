#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using gset = gp_hash_table<T, null_type>;

vec<int> dsu;
vec<gset<int>> queries;
vec<int> ans;
int find(int u) {
    if (u != dsu[u]) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void merge(int u, int v, int t) {
    u = find(u);
    v = find(v);
    if (u == v) { return; }
    if (queries[u].size() > queries[v].size()) { swap(u, v); }  //v is more
    for (auto const &q : queries[u]) {
        if (queries[v].find(q) != queries[v].end()) {
            queries[v].erase(q);
            ans[q] = t;
        }   else {
            queries[v].insert(q);
        }
    }
    dsu[u] = v;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M, Q; cin >> N >> M >> Q;
    dsu.resize(N), queries.resize(N);
    ans.resize(Q, -2);
    rep(i, N) {
        dsu[i] = i;
    }
    vec<arr<int, 2>> edges(M);
    rep(i, M) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--; edges[i][1]--;
    }
    rep(q, Q) {
        int u, v; cin >> u >> v; u--; v--;
        if (u == v) {
            ans[q] = -1;
        }   else {
            queries[u].insert(q);
            queries[v].insert(q);
        }
    }
    rep(t, M) {
        auto [u, v] = edges[t];
        merge(u, v, t);
    }
    rep(q, Q) {
        cout << ans[q] + 1 << "\n";
    }
}
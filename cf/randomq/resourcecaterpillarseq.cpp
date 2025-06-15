#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
#define long long long
const int MOD = 1e9 + 7;
const long INF = 4e18;

#define rep(i,s,e) for(auto i=(s);i<(e);i++)
#define rev(i,s,e) for(auto i=(s) - 1;i>=(e);i--)
#define emp emplace
#define emb emplace_back

template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}

void solve() {
    int N; cin >> N;
    vector<vector<int>> T(N);
    rep(i, 0, N - 1) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].emb(v);
        T[v].emb(u);
    }
    int leaves = 0;
    rep(i, 0, N) {
        leaves += T[i].size() == 1;
    }
    //explanation orz some random guy and ecnerwala
    //initial is q, we are pulled to q' which is within 1 of a leaf.
    //q cannot be a leaf, q' cannot be a leaf.
    //iterate through q'. suppose we have a path (p, q).
    //for those that are not leaves, we can consider them potential q for some p,
    //except one, because q' will be on the path (p, q).
    long ans = (long) leaves * (N - leaves);
    long p = 0, q = 0;
    rep(i, 0, N) {
        if (T[i].size() == 1) { continue; }
        int adj_leaves = 0;
        for (int v : T[i]) {
            adj_leaves += T[v].size() == 1;
        }
        if (adj_leaves == 0) { p++; }
        else { q += max(0, (int) T[i].size() - 1 - adj_leaves); }
    }
    ans += p * q;
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
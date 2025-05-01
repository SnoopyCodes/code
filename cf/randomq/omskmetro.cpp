#include <bits/stdc++.h>

#define long long long
#define rep(i, s, e) for (auto i = (s); i < (e); i++)
#define rev(i, s, e) for (auto i = (s)-1; i >= (e); i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

const int MOD = 1e9 + 7;
const long INF = 4e18 + 7e9;


using namespace std;
template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}
using info = array<int, 7>; //sum, best min/max, best suff min/max, best pref min/max
info join(const info &a, info &b) {  //b is towards root
    return {
        a[0] + b[0],
        min(min(a[1], b[1]), a[3] + b[5]),
        max(max(a[2], b[2]), a[4] + b[6]),
        min(b[3], a[3] + b[0]),
        max(b[4], a[4] + b[0]),
        min(a[5], a[0] + b[5]),
        max(a[6], a[0] + b[6])
    };
}
info init(int v) {
    int small = min(0, v), big = max(0, v);
    return { v, small, big, small, big, small, big };
}
void add(int u, int v, auto& jump, auto& data, auto& depth, int max_jump, int n) {
    depth[n] = depth[u] + 1;
    jump[0][n] = u;
    data[0][n] = init(v);
    rep(i, 1, max_jump) {
        jump[i][n] = jump[i-1][jump[i-1][n]];
        data[i][n] = join(data[i-1][n], data[i-1][jump[i-1][n]]);
    }
}
void solve() {
    int N; cin >> N;
    int max_jump = (N == 1) ? 1 : __lg(N - 1) + 1;
    auto jump = mvec<int>(max_jump, N + 1, 0);
    auto data = mvec<info>(max_jump, N + 1, ta(0,0,0,0,0,0,0));
    vector<int> depth(N + 1, -1);
    int node = 0;
    add(0, 1, jump, data, depth, max_jump, node++);
    rep(q, 0, N) {
        char c; cin >> c;
        if (c == '+') {
            int u, v; cin >> u >> v; u--;
            add(u, v, jump, data, depth, max_jump, node++);
        }   else {
            int u, v, k; cin >> u >> v >> k; u--; v--;
            //actual lca time
            if (depth[u] < depth[v]) { swap(u, v); }
            info ui = data[0][u], vi = data[0][v];
            rev(i, max_jump, 0) {  //actual use for these, incredible
                if (depth[u] - depth[v] & 1 << i) {
                    u = jump[i][u];
                    ui = join(ui, data[i][u]);
                }
            }
            if (u != v) {
                rev(i, max_jump, 0) {
                    if (jump[i][u] != jump[i][v]) {
                        u = jump[i][u];
                        v = jump[i][u];
                        ui = join(ui, data[i][u]);
                        vi = join(vi, data[i][v]);
                    }
                }
                int lca = jump[0][u];
                ui = join(ui, data[0][lca]);
                swap(vi[3], vi[5]);
                swap(vi[4], vi[6]);
                ui = join(ui, vi);
            }
            if (ui[1] <= k && k <= ui[2]) { cout << "yes" << "\n"; }
            else { cout << "no" << "\n"; }
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //we receive the parent rep of a tree
    //wait this is not even that bad
    //oh its a div3 f that's why
    //basically find the mins and max along the path
    //if max - min >= k then ok
    //and to update structure just perform binlift lol
    int T; cin >> T; while(T--) { solve(); }
}
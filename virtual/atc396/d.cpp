#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;
const i64 INF = 4e18 + 7e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vec<vec<arr<i64, 2>>> con(N);
    rep(i, M) {
        int u, v; cin >> u >> v; u--; v--;
        i64 w; cin >> w;
        con[u].push_back({v, w});
        con[v].push_back({u, w});
    }
    //wait literally just
    //brute force all permutations
    i64 ans = INF;
    auto check = [&](vec<int> p) {
        int len = p.size();
        if (p[0] != 0 || p.back() != N - 1) { return INF; }
        i64 cost = 0;
        rep(i, len - 1) {
            bool ok = false;
            for (auto [v, w] : con[p[i]]) {
                if (v == p[i+1]) {
                    cost ^= w;
                    ok = true;
                    break;
                }
            }
            if (!ok) { return INF; }
        }
        return cost;
    };
    rep(mask, 1, 1 << N) {
        vec<int> perm;
        rep(b, N) {
            if (mask & 1 << b) { perm.push_back(b); }
        }
        ans = min(ans, check(perm));
            if (check(perm) == 1) {
                rep(i, perm.size()) {
                    cout << perm[i] << " ";
                }
                cout << "\n";
            }
        vec<int> end = perm;
        next_permutation(perm.begin(), perm.end());
        while (perm != end) {
            ans = min(ans, check(perm));
            if (check(perm) == 1) {
                rep(i, perm.size()) {
                    cout << perm[i] << " ";
                }
                cout << "\n";
            }
            next_permutation(perm.begin(), perm.end());
        }
    }
    cout << ans << "\n";
}
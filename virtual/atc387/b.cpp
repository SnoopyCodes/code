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
    int N; cin >> N;
    vec<vec<int>> G(N, vec<int>(N));
    int ans = 0;
    rep(i, 9) {
        rep(j, 9) {
            if ((i + 1) * (j + 1) != N) {
                ans += (i + 1) * (j + 1);
            }
        }
    }
    cout << ans << "\n";
}
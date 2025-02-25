#include <bits/stdc++.h>

#define vec vector
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //im guessing we overshoot
    //we start with a starting thing
    //and then basically for each edge we don't delete
    //they r gonna have ta be fwends w/ di ones we not fwends
    //with
    //consider the ones we are friends with right now
    //figure out, at minimum, how many edges we have to add??
    //uhhh
    //if some node doesn't have any edges, that means no edges overall
    //
    int N, M; cin >> N >> M;
    int ans = M;
    vec<vec<bool>> is_friend(N, vec<bool>(N));
    rep(i, M) {
        int u, v; cin >> u >> v; u--; v--;
        is_friend[u][v] = true; //hurrah!
        is_friend[v][u] = true;
    }
    vec<int> best(1 << N, M);
    best[0] = 0;
    rep(mask, 1 << N) {
        int rem = 0;
        rep(u, N) {
            if (mask & 1 << u) { continue; }
            rep(v, u+1, N) {
                if (mask & 1 << v) { continue; }
                rem += is_friend[u][v];
            }
        }
        ans = min(best[mask] + rem, ans);
        rep(u, N) {
            if (mask & 1 << u) { continue; }
            //sum up all that dont exist already
            int sum = 0;
            rep(v, N) {
                if (mask & 1 << v) { continue; }
                if (u == v) { continue; }
                sum += !is_friend[u][v];
            }
            best[mask | 1 << u] = min(best[mask | 1 << u], best[mask] + sum);
        }
    }
    cout << ans << "\n";
}
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
    int N, K; cin >> N >> K;
    vec<int> type(N);
    rep(i, N) {
        cin >> type[i];
        type[i]--;
    }
    vec<vec<bool>> likes(K, vec<bool>(K));  //liking is often a one sided thing!
    rep(i, K) {
        rep(j, K) {
            char c; cin >> c;
            likes[i][j] = c == '1';
        }
    }
    //precalculate cl, cr
    vec<vec<int>> cl(N+1, vec<int>(K, -1)), cr(N, vec<int>(K, N));
    rep(i, N - 1) {
        cl[i+1] = cl[i];
        cl[i+1][type[i]] = i;
    }
    rep(i, N - 1, 0) {
        cr[i-1] = cr[i];
        cr[i-1][type[i]] = i;
    }
    vec<int> dist(N, INF);
    dist[0] = 0;
    priority_queue<arr<int, 2>> pq; pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        d = -d;
        if (d != dist[u]) { continue; }
        auto put = [&](int cur, int v) {
            if (v == -1 || v == N || dist[cur] + abs(cur - v) >= dist[v]) { return; }
            dist[v] = dist[cur] + abs(cur - v);
            pq.push({-dist[v], v});
        };
        rep(t, K) {
            //if we like them OR (we equal ourselves AND we don't equal 0) we go
            if (likes[type[u]][t] || t == type[u] && u != 0) {
                put(u, cl[u][t]);
                put(u, cr[u][t]);
            }
        }
    }

    if (dist[N-1] == int(INF)) { cout << -1 << "\n"; }
    else { cout << dist[N-1] << "\n"; }
}
/*
racism
*/
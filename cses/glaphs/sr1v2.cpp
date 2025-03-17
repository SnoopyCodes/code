#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;

vector<int> seg;
vec<i64> dist;
int SN;
int comb(int a, int b) { return dist[a] < dist[b] ? a : b; }
int query(int l, int r) {
    int res = l;
    for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
        if (l & 1) { res = comb(res, seg[l++]); }
        if (r & 1) { res = comb(res, seg[--r]); }
    }
    return res;
}
void alter(int p, i64 val) {
    dist[p] = val;
    for (p = (p + SN) / 2; p > 0; p /= 2) {
        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vec<vec<arr<int, 2>>> flights(N);
    dist.resize(N, 1e18);
    rep(i, M) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        flights[u].push_back({v, w});
    }
    SN = N;
    seg.resize(2 * SN);
    rep(i, N, 2 * N) {
        seg[i] = i - N;
    }
    rep(i, -N) {
        seg[i] = seg[2 * i];
    }
    int visited = 0;
    alter(0, 0);
    vec<i64> fd(N, -1);
    while (visited < N) {
        visited++;
        int u = query(0, N);
        fd[u] = dist[u];
        for (auto const&[v, d] : flights[u]) {
            if (dist[u] + d < dist[v] && fd[v] == -1) {
                alter(v, dist[u] + d);
            }
        }
        alter(u, 1e18);
    }
    rep(i, N) {
        cout << fd[i] << " \n"[i == N - 1];
    }
}
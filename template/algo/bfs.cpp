#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    mt<int> G(N);
    vt<int> q;
    q.add(0);
    vt<bool> vis(N);
    vis[0] = 1;
    // memory opt.
    // while (q.size()) {
    //     auto tmp = q; q.clear();
    //     for (int u : tmp) {
    //         for (int v : G[u]) {
    //             if (vis[v]) { continue; }
    //             vis[v] = true;
    //             q.add(v);
    //         }
    //     }
    // }

    mt<int> in_d(N);
    in_d[0].add(0);
    //store depths.
    for (int i = 0; i < N; i++) {
        for (int u : in_d[i]) {
            for (int v : G[u]) {
                if (vis[v]) { continue; }
                vis[v] = true;
                in_d[i + 1].add(v);
            }
        }
    }

    vis = vt<bool>(N);
    vis[0] = 1;

    queue<int> qq;
    qq.push(0);
    while (!qq.empty()) {
        int u = qq.front(); qq.pop();
        for (int v : G[u]) {
            if (vis[v]) { continue; }
            vis[v] = true;
            qq.push(v);
        }
    }
}
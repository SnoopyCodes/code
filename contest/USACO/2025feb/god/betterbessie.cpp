#include <bits/stdc++.h>

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

using namespace std;

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;

vec<vec<int>> radj;
vec<int> F, C;
arr<i64, 2> dfs(int u, int p) {
    arr<i64, 2> res { C[u], 0 };
    for (int v : radj[u]) {
        if (v == p) { continue; }
        auto x = dfs(v, p);
        res[0] += min(x[1], x[0]);
        res[1] += x[0];
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    F.resize(N), C.resize(N), radj.resize(N);
    vec<bool> visited(N);
    rep(i, N) {
        cin >> F[i]; F[i]--;
    }
    rep(i, N) {
        cin >> C[i];
        if (F[i] == i) { C[i] = 0; }
        else { radj[F[i]].push_back(i); }
    }

    i64 ans = 0;
    vec<bool> in_path(N);
    rep(i, N) {
        if (visited[i]) { continue; }
        int u = i;
        stack<int> path;
        while (!visited[u]) {
            in_path[u] = true;
            visited[u] = true;
            path.push(u);
            u = F[u];
        }
        if (in_path[u]) {
            vec<int> cyc;
            while (in_path[u]) {
                int v = path.top(); path.pop();
                in_path[v] = false;
                cyc.push_back(v);
            }
            auto res = dfs(cyc[0], cyc[0]);
            i64 add = min(res[0], res[1] + C[cyc[0]]);
            if (cyc.size() > 1) {
                res = dfs(cyc[1], cyc[1]);
                add = min(add, min(res[0], res[1] + C[cyc[1]]));
            }
            ans += add;
        }
        while (!path.empty()) {
            int v = path.top(); path.pop();
            in_path[v] = false;
        }
    }
    cout << ans << "\n";
}
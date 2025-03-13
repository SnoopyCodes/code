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

const int MOD = 998244353;

vec<vec<int>> radj;
vec<vec<i64>> res;
vec<bool> visited;
int M;
void dfs(int u, int ban) {
    visited[u] = true;
    for (int v : radj[u]) {
        if (v == ban) { continue; }
        dfs(v, ban);
        i64 cur = 0;
        rep(i, M) {
            cur = (cur + res[v][i]) % MOD;
            //it multiplies...
            res[u][i] = (res[u][i] * cur) % MOD;
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N >> M;
    //this is a functional graph...
    //but treat the cycle as a node itself, and tree dp commences
    //yes i udnerstand it now
    i64 ans = 1;
    res.resize(N, vec<i64>(M, 1));
    radj.resize(N);
    visited.resize(N);
    vec<int> nxt(N);

    rep(i, N) {
        int x; cin >> x; x--;
        radj[x].push_back(i);
        nxt[i] = x;
    }
    rep(i, N) {
        if (visited[i]) { continue; }
        int u = i;
        stack<int> path;
        while (!visited[u]) {
            visited[u] = true;
            path.push(u);
            u = nxt[u];
        }
        //nah it just goes to root and then we move?
        //we should always be at a new cc
        vec<int> cyc;
        while (cyc.empty() || cyc.back() != u) {
            cyc.push_back(path.top());
            path.pop();
        }
        //treat each of these as new heads. the ones that they cant go to
        //are the ones in front of them
        vec<i64> total(M, 1);
        rep(i, cyc.size()) {
            dfs(cyc[i], cyc[(i+1) % cyc.size()]);
            rep(j, M) {
                total[j] = (total[j] * res[cyc[i]][j]) % MOD;
            }
        }
        int cc_ans = 0;
        rep(i, M) {
            cc_ans = (cc_ans + total[i]) % MOD;
        }
        ans = (ans * cc_ans) % MOD;
    }
    cout << ans << "\n";
}
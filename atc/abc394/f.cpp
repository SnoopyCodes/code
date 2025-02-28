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

vec<vec<int>> T;
vec<int> res;  //choose best 3, or just be thing
int ans = -1;

void dfs(int u, int p) {
    for (int v : T[u]) {
        if (v == p) { continue; }
        dfs(v, u);
    }
    //if we suppose this to be the root
    //we must choose 4 best child
    priority_queue<int> child_killer_machine;
    int sum = 1;
    for (int v : T[u]) {
        if (v == p) { continue; }
        child_killer_machine.push(-res[v]);
        sum += res[v];
        #define kill pop
        if (child_killer_machine.size() > 4) {
            sum += child_killer_machine.top();
            child_killer_machine.kill();
        }
    }
    //directly choose 4
    if (child_killer_machine.size() == 4) {
        ans = max(ans, sum);
        sum += child_killer_machine.top();
        child_killer_machine.kill();
    }
    if (child_killer_machine.size() == 3) {
        if (p != -1) {
            ans = max(sum + 1, ans);
        }
        res[u] = sum;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    T.resize(N);
    res.resize(N, 1);
    rep(i, N - 1) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(0, -1);
    cout << ans << "\n";
}
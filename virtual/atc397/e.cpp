#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;

vec<vec<int>> T;

int dfs(int u, int from, int k) {
    int addto = 0;
    for (int v : T[u]) {
        if (v == from) { continue; }
        int res = dfs(v, u, k);
        if (res < 0) { return -1; }
        if (res == k) { continue; }
        if (!addto) { addto = res; }
        else {
            if (addto != -3 && addto + res + 1 == k) {
                addto = -3;
            }   else {
                return -1;
            }
        }
    }
    if (addto == -3) { return k; }
    return addto + 1;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    //this is NOT the same as delegation- usaco gold.
    //all vertices belong to one path only.
    //we have choice to combine also bruh
    T.resize(N * K);
    rep(i, N * K - 1) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    if (dfs(0, -1, K) == K) { cout << "Yes" << "\n"; }
    else { cout << "No" << "\n"; }
}
#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
struct graph {
    vt<int> h, nxt;
    vt<int> e;
    graph(int n): h(n, -1) {}
    void adde(int u, int v) {
        nxt.add(h[u]);
        h[u] = size(e);
        e.add(v);
    }
    
};
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int M = 5;
    int N = 5;
    vt<int> h(N, -1);
    vt<int> e;
    vt<int> nxt;
    auto adde = [&](int u, int v) {
        nxt.add(h[u]);
        h[u] = size(e);
        e.add(v);
    };
    //for (int i = h[u]; ~i; i = nxt[i]) //v = h[i]
}
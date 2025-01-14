#include <bits/stdc++.h>
#define long int64_t
using namespace std;

vector<vector<int>> cow;
vector<int> order, in, out;

void dfs(int u, int p) {
    in[u] = order.size();
    order.push_back(u);
    for (int v : cow[u]) {
        if (v == p) { continue; }
        dfs(v, u);
    }
    out[u] = order.size();
}

int N;
vector<int> sub;
vector<int> root;  //subtree, root segtrees

void init() {
    sub.resize(N), root.resize(N);
}

void subupd(int p, int val) {
    sub[p + N] += val;
    for (p = (p + N) / 2; p > 0; p /= 2) {
        sub[p] += val;
    }
}
void subsum(int l, int r) {
    int res = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { res += sub[l++]; }
        if (r & 1) { res += sub[--r]; }
    }
}

void rootupd(int l, int r, int val) {
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { root[l++] += val; }
        if (r & 1) { root[--r] += val; }
    }
}
int rootsum(int p) {
    int res = 0;
    for (p += N; p > 0; p /= 2) {
        res += root[p];
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);
    int Q; cin >> N >> Q;
    cow.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        cow[u].push_back(v);
        cow[v].push_back(u);
    }
    dfs(0, -1);
    vector<set<int>> has(N); //snowball
    vector<set<array<int, 2>>> at(1e5);  //color
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int u, c; cin >> u >> c; u--; c--;
            has[u].insert(c);
            at[c].insert({in[u], u});
            auto it = ++at[c].find({in[u], u});
            while (it != at[c].end() && (*it)[0] <= out[u]) {
                auto [o, v] = *it;
                has[v].erase(c);
                //erase from segtrees
                rootupd(in[v], out[v] + 1, -1);
                subupd(in[v], -1);
                it = at[c].erase(it);
            }
                
        }   else {
            int u; cin >> u; u--;
            //this is fine, these affect all
            //oh nah is it lazy segtree bruh
            //this might be lazy segtree guys
            //looks like we gotta lazy segtree...
            long ans = (long) (out[u] + 1 - in[u]) * rootsum(in[u]);

        }
    }


}
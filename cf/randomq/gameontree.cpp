#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    /*
    so take a path down a tree
    what do we do for a round?
    dp, rerooting?
    inside of a subtree, we can easily know who wins a round through dp
    then we must reroot it
    times like these we wish for a rerooting dp template
    */

    int N, R; cin >> N >> R;
    vt<vt<int>> T(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].add(v);
        T[v].add(u);
    }

    vt<int> rwin(N);
    
    auto dfs = [&](auto &&self, int u, int p) -> void {
        //we want to know if this one wins
        //by default, ron loses
        //however, if there are children in which ron loses, we just use that one
        for (int v : T[u]) {
            if (v == p) { continue; }
            self(self, v, u);
            rwin[u] |= !rwin[v];
        }
    };
    dfs(dfs, 0, -1);
    //easy enough, but this only solves for 1
    vt<int> fin(N);
    auto reroot = [&](auto &&self, int u, int p, int pv)  -> void {
        int ctr = pv;
        //for each child we have to answer the question: if we are ron and can't move to them
        //do we win?
        //if we are ron, we win iff there is >= 1 branch that has a hermione win
        //give !win to child.
        for (int v : T[u]) {
            if (v == p) { continue; }
            ctr += !rwin[v];
        }
        fin[u] = ctr;
        for (int v : T[u]) {
            if (v == p) { continue; }
            ctr -= !rwin[v];
            self(self, v, u, !ctr);
            ctr += !rwin[v];
        }
    };
    reroot(reroot, 0, -1, 0);
    while (R --> 0) {
        int u; cin >> u; u--;
        cout << (fin[u] ? "Ron" : "Hermione") << "\n";
    }
}
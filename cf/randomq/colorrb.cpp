#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

const int N = 2e5 + 5;
int f[N];
vt<int> T[N];
bool r_i[N];



void solve() {
    int N; cin >> N;
    string s; cin >> s;
    vt<vt<int>> T(N);
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v; u--; v--;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    /*
    this is a tree dp problem (shocking)
    the red nodes split the tree into further trees; we dp over
    black components. the main part to decide is when the current node turns red,
    relative to all of its subtrees (and the cut-tree above it)
    let f[u] define if the cut-tree above u turns red before u itself,
    and g[u] define otherwise. (i believe g[u] >= f[u])
    obviously, if there are no reds in u's subtree, then g[u] is undefined.
    similarly, if there are no reds in the cut-tree above u, then f[u] is undefined.
    suppose we have degree d, and n neighbors turn red before ourselves
    it takes expected d/n to turn us red (i think, pretty sure due to stats formulas)
    we want to iterate through our positions 1...n+1. we cannot be red first (we are a white node) so 2...n+1. choose the child with minimum difference between g[u] - f[u] to go.
    how do we deal with undefined values?
    undefined values are forced into one or the other. 
    this is just a matter of implementing most cleanly.
    we can select roots surely

    we probably don't need to split it, just dfs from one root.
    ok
    the parent being active allows for u to come first

    */
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
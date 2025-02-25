#include <bits/stdc++.h>

#define vec vector
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

using namespace std;


vec<vec<int>> dict;
vec<int> leaf;
vec<int> depth;
void dfs(int u, int d) {
    depth[u] = d;
    if (dict[u].size() == 0) {
        leaf.push_back(u);
    }   else {
        for (int v : dict[u]) {
            dfs(v, d + 1);
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //LOCK IN LLOCK IN
    //NO WORD IN THE BANK IS A PREFIX OF ANOTHER WORD IN THE BANK
    //...what in the ad hoc
    int N; cin >> N;
    depth.resize(N);
    N++;
    vec<int> W(N);  //basically parent
    dict.resize(N);
    rep(i, 1, N) {
        cin >> W[i];
        dict[W[i]].push_back(i);
    }
    dfs(0, 0);
    vec<bool> visited(N);
    //the 0th is the empty string, okay
    //it does not tell us M, bruh
    //wait! this is a tree!
    //DFS IS BACK CHAT LETS GOOOOOOOOOOOOOO
    //M = number of leaves in the tree
    //then we have some order of traversal
    //subtasks 6-10: brute force is OK
    //so bessie traverses down from root in this order
    //then, we uniquely identify the answer once we get on a path
    //that has no other traversals on it
    //(therefore we should do lct for dynamic path add path subtract)
    //jk
    vec<int> queries(leaf.size());
    rep(q, leaf.size()) {
        cin >> queries[q];
    }
    //reverse and run while loop
    vec<int> ans(leaf.size());
    reverse(queries.begin(), queries.end());
    rep(q, leaf.size()) {
        int u = queries[q];
        while (!visited[u]) {
            visited[u] = true;
            u = W[u];
        }
        ans[q] = depth[u];
        if (q) { ans[q]++; }
    }
    reverse(ans.begin(), ans.end());
    rep(q, leaf.size()) {
        cout << ans[q] << "\n";
    }
}
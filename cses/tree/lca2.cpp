#include <bits/stdc++.h>

using namespace std;
struct Node {
    int p, e, n, i, s;  //yes
    int d;
    vector<int> adj;
};
int n;
vector<Node> nodes;
vector<int> order;
int euler = 0;
void dfs(int v, int d) {
    order[euler] = v;
    nodes[v].s = euler;
    nodes[v].d = d;
    euler++;
    for (int x : nodes[v].adj) {
        dfs(x, d + 1);
    }
    nodes[v].e = euler;
}
vector<int> seg;
int comp(int u, int v) {
    if (u == -1) { return v; }
    return nodes[v].d < nodes[u].d ? v : u;
}
void init() {
    seg.resize(2 * n);
    for (int i = 0; i < n; i++) {
        seg[i + n] = order[i];
    }
    for (int i = n - 1; i > 0; i--) {
        seg[i] = comp(seg[i * 2], seg[i * 2 + 1]);
    }
}
int query(int l, int r) {  //u < v
    int ans = -1;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) { ans = comp(ans, seg[l++]); }
        if (r & 1) { ans = comp(ans, seg[--r]); }
    }
    // cout << ans << "\n";
    return ans;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int q; cin >> n >> q;
    nodes.resize(n);
    order.resize(n);
    for (int i = 1; i < n; i++) {
        int b; cin >> b; b--;
        nodes[b].adj.push_back(i);
        nodes[i].p = b;
    }
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        nodes[order[i]].i = i;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << order[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < n; i++) {
    //     cout << nodes[order[i]].d << " ";
    // }
    // cout << "\n";
    init();
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--; b--;
        if (nodes[b].i < nodes[a].i) { swap(a, b); }
        if (nodes[a].e >= nodes[b].e) { cout << a+1 << "\n"; continue; }
        cout << nodes[query(nodes[a].s, nodes[b].s + 1)].p + 1 << "\n";
        //okay so we need lca somehow
        //we have an ordering
        //we can get like depths and stuff
        //1 2 5 6 3 4 7
        //0 1 2 2 1 1 2
        //helphelphlephelphelp
        //so if we query for 5 and 7
        //if one does not encompass the other
        
    }
}
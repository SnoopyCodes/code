#include <bits/stdc++.h>
//i need to fix
using namespace std;
vector<vector<int>> graph;
vector<int> vals;

vector<int> euler;
vector<int> newi;

vector<int> seg;
vector<vector<int>> flavors;  //when flavors occur
vector<int> depth;
void dfs(int v, int from, int d) {
    //binary search stuff
    flavors[vals[v]].push_back(euler.size());
    depth[v] = d;
    //euler stuff
    newi[v] = euler.size();
    euler.push_back(v);
    for (int x : graph[v]) {
        if (x != from) {
            dfs(x, v, d+1);
            flavors[vals[v]].push_back(euler.size());
            euler.push_back(v);
        }
    }
}

int segn;
int comp(int a, int b) {  //2 node indexes
    if (a == -1) { return b; }
    if (b == -1) { return a; }
    if (depth[a] < depth[b]) { return a; }
    return b;
}
void init() {
    for (int i = 0; i < segn; i++) {
        seg[segn + i] = euler[i];
    }
    for (int i = segn - 1; i > 0; i--) {
        seg[i] = comp(seg[i << 1],  seg[i << 1 | 1]);
    }
}
int lca(int l, int r) {
    int m = -1;
    for (l += segn, r += segn; l < r; l >>= 1, r >>= 1) {
        if (l & 1) { m = comp(m, seg[l++]); }
        if (r & 1) { m = comp(m, seg[--r]); }
    }
    return m;
}
bool chk(int i, int j, int v) {  //see if there is any occurrence from l to r in occurrences[v]
    
}
bool query(int l, int r, int v) {
    //find lca of l, r in node form
    //now find closest occurrence of lca to l, and closest to r
    //we can do this easily by saying l...l+(depth[l] - depth[lca]) for l
    //to bs in
    int ca = lca(newi[l], newi[r]+1);
    if (chk(l, l + depth[l] - depth[ca] + 1, v) || chk(r, r + depth[r] + depth[ca] + 1, v)) {
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    // freopen("milkvisits.in", "r", stdin);
    // freopen("milkvisits.out", "w", stdout);
    int N, M; cin >> N >> M;
    graph.resize(N);
    vals.resize(N);
    depth.resize(N);
    flavors.resize(N+1);
    newi.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1, 0);
    segn = euler.size();
    seg.resize(2 * segn, -1);
    init();
    
    // for (int i = 0; i < segn; i++) {
    //     cout << seg[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < segn; i++) {
    //     cout << seg[i + segn] << " ";
    // }
    // cout << "\n";
    for (int q = 0; q < M; q++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        if (b < a) { swap(a, b); }
        cout << query(a, b, c);
    }
}
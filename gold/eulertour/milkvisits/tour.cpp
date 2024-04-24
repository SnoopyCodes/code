#include <bits/stdc++.h>
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
    return depth[a] < depth[b] ? a : b;
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
bool chk(int i, int j, int v) { //inclusive
    //find the closest occurrence <= j, then check if > i
    int s = 0, e = flavors[v].size();
    cout << "chk" << "\n";
    cout << i << " " << j << " " << v << "\n";
    for (int x : flavors[v]) {
        cout << x << " ";
    }
    cout << "\n";
    while (s + 1 < e) {
        int m = (s + e) / 2;
        if (flavors[v][m] <= j) { s = m; }
        else { e = m; }
    }
    if (flavors[v].size() == 0 || flavors[v][s] > j || flavors[v][s] < i) { return false; }
    return true;
}
int query(int l, int r, int v) {
    //find lca of l, r in node form
    //now find closest occurrence of lca to l, and closest to r
    //we can do this easily by saying l...l+(depth[l] - depth[lca]) for l
    int ca = lca(newi[l], newi[r]+1);
    cout << ca << "\n";
    if (chk(newi[l] - depth[l] + depth[ca], newi[l], v) 
    || chk(newi[r] - depth[r] + depth[ca], newi[r], v)) {
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
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
    seg.resize(2 * segn + 1, -1);
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
        int a, b, c = 0; cin >> a >> b >> c;
        a--; b--;
        if (newi[b] < newi[a]) { swap(a, b); }
        if (q == 1)
        cout << query(a, b, c);
    }
}
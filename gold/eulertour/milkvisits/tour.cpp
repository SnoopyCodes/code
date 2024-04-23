#include <bits/stdc++.h>
//i need to fix
using namespace std;
vector<vector<int>> graph;
vector<int> vals;

vector<int> euler;
vector<int> newi;

vector<int> seg;
vector<multiset<int>> path;
multiset<int> cur;
void dfs(int v, int from) {
    //binary search stuff
    cur.insert(vals[v]);
    path[v] = cur;  //this is literally overpowered, O(1) storage wtf
    //euler stuff
    newi[v] = euler.size();
    euler.push_back(v);
    for (int x : graph[v]) {
        if (x != from) {
            dfs(x, v);
            euler.push_back(v);
        }
    }
    cur.erase(cur.find(vals[v]));
}

int segn;
int comp(int a, int b) {  //2 node indexes
    if (a == -1) { return b; }
    if (b == -1) { return a; }
    if (path[a].size() < path[b].size()) { return a; }
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
bool chk(int i, int j, int v) {
    int len = path[j].size() - 1;
    auto it = path[i].begin();
    advance(it, len);
    return find(it, path[i].end(), v) != path[i].end();
}
bool query(int l, int r, int v) {
    //find lca of l, r in node form
    int ca = lca(newi[l], newi[r]+1);
    // cout << "left" << " " << l << "\n";
    // for (int x : path[l]) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // cout << "right" << " " << r << "\n";
    // for (int x : path[r]) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // cout << "ancestor" << " " << ca << "\n";
    // for (int x : path[ca]) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    if (chk(l, ca, v) || chk(r, ca, v)) {
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
    path.resize(N);
    newi.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1);
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
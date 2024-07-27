#include <bits/stdc++.h>

using namespace std;

/*
the most important part is that you can get number of colors on a path from an ancestor
to a child by using a vector of int pairs for each color (changes)
each int pair stores the euler time it changes, and the number of values
its important to note that at euler time out, we decrement the color number
this means that at all times the last entry in changes maintains the number of 
colors from the root to the current node
lca from: https://codeforces.com/blog/SnoopyCodes :>
no sparse tables used
*/

vector<int> colors;
vector<vector<array<int, 2>>> changes;  //changes in each color at time what, val what
vector<vector<int>> farms;
vector<int> par;
vector<int> start;
vector<int> depth;
int euler = 0;
void dfs(int v, int from, int d) {
    int col = colors[v];
    depth[v] = d;
    changes[col].push_back({euler, (*changes[col].rbegin())[1] + 1});
    start[v] = euler;
    euler++;
    par[v] = from;
    for (int adj : farms[v]) {
        if (adj == from) { continue; }
        dfs(adj, v, d + 1);
    }
    changes[col].push_back({euler, (*changes[col].rbegin())[1] - 1});
}
int N;
vector<int> seg;
int comp(int u, int v) {
    return depth[v] < depth[u] ? v : u;
}
void init() {
    seg.resize(2 * N);
    for (int i = 0; i < N; i++) {
        seg[start[i] + N] = i;
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = comp(seg[2 * i], seg[2 * i + 1]);
    }
}
int query(int l, int r) {
    int ans = seg[l + N];
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { ans = comp(ans, seg[l++]); }
        if (r & 1) { ans = comp(ans, seg[--r]); }
    }
    return ans;
}
int bs(int t, int c) {  //largest value <= start[t]
    int s = 0, e = changes[c].size();
    while (s + 1 < e) {
        int m = (s + e) / 2;
        if (changes[c][m][0] <= t) {
            s = m;
        }   else {
            e = m;
        }
    }
    return changes[c][s][1];
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int M; cin >> N >> M;
    colors.resize(N);
    farms.resize(N);
    start.resize(N);
    par.resize(N);
    depth.resize(N);
    changes.resize(N, vector<array<int, 2>>(1, {-1, 0}));
    for (int i = 0; i < N; i++) {
        cin >> colors[i]; colors[i]--;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        farms[a].push_back(b);
        farms[b].push_back(a);
    }
    dfs(0, -1, 0);
    init();
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c; a--; b--; c--;
        if (start[b] < start[a]) { swap(a, b); }
        int lca;
        if (a == b) {
            lca = a;
        }   else {
            lca = par[query(start[a]+1, start[b]+1)];
        }
        int lcac = bs(start[lca], c);
        if (colors[lca] == c) { lcac--; }
        int ac = bs(start[a], c);
        int bc = bs(start[b], c);
        cout << bool(ac + bc - 2 * lcac);
    }
    cout << "\n";
}
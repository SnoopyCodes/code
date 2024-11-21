#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> roads;
vector<int> depth;
vector<int> cow;
vector<int> in;
vector<vector<int>> jumps;
vector<vector<array<int, 2>>> changes;  //changes in each color at time what, val what
int euler = 0;

void dfs(int u, int par, int d) {
    jumps[0][u] = par;
    depth[u] = d;
    int c = cow[u];
    changes[c].push_back({euler, changes[c].back()[1] + 1});
    in[u] = euler;
    euler++;
    for (int v : roads[u]) {
        if (v == par) { continue; }
        dfs(v, u, d + 1);
    }
    changes[c].push_back({euler, changes[c].back()[1] - 1});
}

int bs(int t, int c) {  //largest value <= start[t]
    int s = 0, e = changes[c].size();
    while (s + 1 < e) {
        int m = (s + e) / 2;
        if (changes[c][m][0] <= t) { s = m; }
        else { e = m; }
    }
    return changes[c][s][1];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int N, M; cin >> N >> M;
    roads.resize(N);
    cow.resize(N);
    int jump = __lg(N - 1) + 1;
    jumps.resize(jump, vector<int>(N, -1));
    depth.resize(N);
    in.resize(N, -1);
    changes.resize(N, vector<array<int, 2>>(1, {-1, 0}));
    for (int i = 0; i < N; i++) {
        cin >> cow[i]; cow[i]--;
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        roads[u].push_back(v);
        roads[v].push_back(u);
    }
    dfs(0, -1, 0);
    
    for (int i = 1; i < jump; i++) {
        for (int j = 0; j < N; j++) {
            if (jumps[i-1][j] != -1) {
                jumps[i][j] = jumps[i-1][jumps[i-1][j]];
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        int u, v, c; cin >> u >> v >> c; u--; v--; c--;
        int uc = bs(in[u], c);
        int vc = bs(in[v], c);
        int lca;
        //equalize depths
        if (depth[u] < depth[v]) { swap(u, v); }
        //bring u up to v
        int diff = depth[u] - depth[v];
        for (int i = 0; i < jump; i++) {
            if (diff & 1 << i) { u = jumps[i][u]; }
        }
        
        if (u == v) { lca = u; }
        else {
            for (int i = jump - 1; i > -1; i--) {
                if (jumps[i][u] != jumps[i][v]) { u = jumps[i][u]; v = jumps[i][v]; }
            }
            lca = jumps[0][u];
        }
        int lcac = bs(in[lca], c);
        if (cow[lca] == c) { lcac--; }
        cout << bool(uc + vc - 2 * lcac);
    }
    cout << "\n";
}
#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

vt<int> root;
mt<int> G;
int find(int u) {
    if (root[u] != u) { root[u] = find(root[u]); }
    return root[u];
}
#define union zzzz
bool union(int u, int v) {
    int ru = find(u);
    int rv = find(v);
    if (ru == rv) { return false; }
    if (size(G[ru]) < size(G[rv])) { swap(ru, rv); }
    for (int v : G[rv]) { G[ru].add(v); }
    G[rv].clear();
    root[rv] = ru;
    return true;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
    int N, M; cin >> N >> M;
    G.resize(N);
    queue<int> q;
    root.resize(N);
    iota(root.begin(), root.end(), 0);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--; //b admires a
        G[u].add(v);
    }
    for (int i = 0; i < N; i++) {
        q.push(i);
    }
    vt<int> color(N);
    while (!q.empty()) { //something is not right??
        int u = q.front(); q.pop();
        if (G[u].empty()) { continue; }
        int v = *G[u].begin();
        bool change = false;
        for (int w : G[u]) {
            change |= union(v, w);
        }
        if (change) {
            q.push(find(v));
        }
    }
    
    vt<int> group_min(N, BIG);
    for (int i = 0; i < N; i++) {
        group_min[find(i)] = min(group_min[find(i)], i);
    }
    int available_color = 1;
    for (int i = 0; i < N; i++) {
        if (group_min[find(i)] == i) {
            color[i] = available_color++;
        }   else {
            color[i] = color[group_min[find(i)]];
        }
        cout << color[i] << "\n";
    }
}
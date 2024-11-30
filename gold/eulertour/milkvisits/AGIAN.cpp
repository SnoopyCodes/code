#include <bits/stdc++.h>
//idk testing it out
#define rsz resize
using namespace std;

//unique O(N) binlift approach, online O(N + M log^2 N)
//idea from this guys blog below
//queries can be sped up to log N by using umap
//https://vmhl87.github.io/starship/pages/17_binlifting-.html
//so, I'm wondering if there's any static path query problem
//unsolvable with binlift but solvable with euler tour?

vector<int> cow;
vector<vector<int>> roads;

vector<set<int>> jhas;
vector<int> depth, par, jump;

void dfs(int u, int p, int d) {
    jhas[u].insert(cow[u]);
    depth[u] = d;
    par[u] = p;
    for (int v : roads[u]) {
        if (v == p) { continue; }
        if (depth[u] + depth[jump[jump[u]]] == 2 * depth[jump[u]]) {
            jump[v] = jump[jump[u]];
            for (int c : jhas[u]) { jhas[v].insert(c); }
            for (int c : jhas[jump[u]]) { jhas[v].insert(c); }
        }   else {
            jump[v] = u;
            jhas[v].insert(cow[u]);
        }
        dfs(v, u, d + 1);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int N, M; cin >> N >> M;
    cow.rsz(N), roads.rsz(N), depth.rsz(N), par.rsz(N), jump.rsz(N), jhas.rsz(N);
    for (int i = 0; i < N; i++) {
        cin >> cow[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        roads[u].push_back(v);
        roads[v].push_back(u);
    }
    dfs(0, 0, 0);
    for (int i = 0; i < M; i++) {
        int u, v, c; cin >> u >> v >> c; u--; v--;
        if (depth[u] < depth[v]) { swap(u, v); }
        bool has = cow[u] == c || cow[v] == c;
        while (depth[u] > depth[v]) {
            if (depth[jump[u]] >= depth[v]) {
                has |= jhas[u].count(c);
                u = jump[u];
            }   else {
                u = par[u];
                has |= cow[u] == c;
            }
        }
        while (u != v) {
            if (jump[u] != jump[v]) {
                has |= jhas[u].count(c);
                has |= jhas[v].count(c);
                u = jump[u], v = jump[v];
            }   else {
                u = par[u], v = par[v];
                has |= cow[u] == c || cow[v] == c;
            }
        }
        cout << has;
    }
    cout << "\n";
}
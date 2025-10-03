#include <bits/stdc++.h>
//no N * 2 dsu, no parity dsu
//just keep an enemy[] array and update accordingly
using namespace std;

template<class T> using vt = vector<T>;

vt<int> dsu, enemy;

int find(int u) {
    return dsu[u] == u ? u : dsu[u] = find(dsu[u]);
}
#define union heyyy
int union(int u, int v) { //these are roots, u is new root
    if (u == -1 && v == -1) { return -1; }
    else if (u == -1) { return v; }
    else if (v == -1) { return u; }
    return dsu[v] = u;
}

bool set_friends(int u, int v) {
    u = find(u), v = find(v);
    if (enemy[u] == v) { return false; }
    if (u == v) { return true; }
    union(u, v);
    int e = union(enemy[u], enemy[v]);
    enemy[u] = e;
    if (~e) { enemy[e] = u; }
    return true;
}

bool set_enemies(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) { return false; }
    if (enemy[u] == v) { return true; }
    union(u, enemy[v]);
    union(v, enemy[u]);
    enemy[u] = v;
    enemy[v] = u;
    return true;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    enemy = dsu = vt<int>(N, -1);
    iota(begin(dsu), end(dsu), 0);
    while (true) {
        int c, u, v; cin >> c >> u >> v;
        if (!c && !u && !v) { break; }
        if (c == 1) {
            if (!set_friends(u, v)) { cout << -1 << "\n"; }
        }   else if (c == 2) {
            if (!set_enemies(u, v)) { cout << -1 << "\n"; }
        }   else if (c == 3) {
            cout << (find(u) == find(v)) << "\n";
        }   else if (c == 4) {
            cout << (enemy[find(u)] == find(v)) << "\n";
        }
    }
}
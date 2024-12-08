#include <bits/stdc++.h>

using namespace std;

vector<int> dsu;

int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) { return; }
    if (rand() % 2) { dsu[u] = v; }
    else { dsu[v] = u; }
}
//to initialize:
//dsu.resize(N)
//for (int i = 0; i < N; i++) {
//  dsu[i] = i;
//}
//doesnt track component sizes or anything, just merge stuff

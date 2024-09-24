#include <bits/stdc++.h>

using namespace std;

vector<int> dsu;
int find(int v) {
    if (v == dsu[v]) { return v; }
    dsu[v] = find(dsu[v]);
    return dsu[v];
}
void unite(int u, int v) {
    if (u == v) { return; }
    if (rand() % 2) {
        dsu[v] = u;
    }   else {
        dsu[u] = v;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A, B; cin >> N >> A >> B;
    //
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        dsu[i] = i;
    }
    vector<bool> canA(N), canB(N);
    sort(P.begin(), P.end());
    //let there be an edge from p[i] to p[j] if p[i] + p[j] == a || b
    //let's say we form the edges
    //every node has at most 2 edges to iterate over
    //what the hell is a contradiction
    //if 
    
}
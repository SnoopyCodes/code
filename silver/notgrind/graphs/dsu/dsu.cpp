#include <bits/stdc++.h>

using namespace std;
int MAX_N = 200000;
vector<vector<int>> graph;
vector<int> dsu;  //ok
int find(int n) {
    if (dsu[n] != n) {
        dsu[n] = find(dsu[n]);
    }
    return dsu[n];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int Q; cin >> Q;
    dsu.resize(N);
    for (int i = 0; i < N; i++) {
        dsu[i] = i;
    }
    for (int q = 0; q < Q; q++) {
        bool query;
        int u, v;
        cin >> query >> u >> v;
        if (!query) {
            int ru = find(u);
            int rv = find(v);
            if (rand() % 2) {
                dsu[ru] = rv;
            }   else {
                dsu[rv] = ru;
            }
        }   else {
            cout << (find(u) == find(v)) << "\n";
        }
    }
}
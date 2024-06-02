#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //toposorttttttt
    int N, M; cin >> N >> M;
    g.resize(N);
    vector<int> in(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        in[b]++;
    }
    vector<int> order;
    queue<array<int, 2>> bfs;
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) {
            bfs.push({i, 0});
        }
    }
    while (!bfs.empty()) {
        auto v = bfs.front();
        bfs.pop();
        order.push_back(v[1]);
        for (int i = 0; i < g[v[0]].size(); i++) {
            in[g[v[0]][i]]--;
            if (in[g[v[0]][i]] == 0) {
                bfs.push({g[v[0]][i], v[1]+1});
            }
        }
    }
    cout << order[order.size()-1];
}
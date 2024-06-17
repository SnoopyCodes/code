#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> cities;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    cities.resize(N);
    vector<int> in(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        cities[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) { q.push(i); }
    }
    vector<int> toposort;
    while (!q.empty()) {
        int v = q.front();
        toposort.push_back(v);
        q.pop();
        for (int x : cities[v]) {
            in[x]--;
            if (in[x] == 0) { q.push(x); }
        }
    }
    // now we have toposorted. then we can dfs or smth
    // 
}
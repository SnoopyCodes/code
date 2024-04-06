#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> v;
vector<bool> visited;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    //N edges, M connections, all unweighted. find the distance from node 0
    //
    cin >> N >> M;
    v.resize(N);
    visited.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        visited[cur] = true;
        q.pop();
        for (int x : v[cur]) {
            
        }
    }
}
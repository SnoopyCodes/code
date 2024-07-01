#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> network;
vector<int> visited;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    network.resize(N);
    visited.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        network[b].push_back(a);
        network[a].push_back(b);
    }
    queue<int> q; q.push(0);
    visited[0] = -2;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i : network[x]) {
            if (visited[i] == -1) {
                visited[i] = x;
                q.push(i);
            }
        }
    }
    if (visited[N-1] != -1) {
        vector<int> route;
        int path = N - 1;
        while (path != -2) {
            route.push_back(path+1);
            path = visited[path];
        }
        cout << route.size() << "\n";
        for (int i = route.size() - 1; i > -1; i--) {
            cout << route[i];
            if (i != 0) { cout << " "; }
        }
        cout << "\n";
    }   else {
        cout << "IMPOSSIBLE" << "\n";
    }
}
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> visited;
int N, M;
int length = INT_MAX;
void bfs(int i) {
    queue<int> q;
    visited[i] = -2;
    q.push(i);
    while (!q.empty()) {
        cout <<  i << endl;
        i = q.front();
        q.pop();
        for (int x : graph[i]) {
            cout << x << endl;
            if (visited[x] != -1) {
                cout << "it happeend" << endl;
                int dist = 0;
                int tmp = i;
                while (tmp != x) {
                    cout << tmp << endl;
                    tmp = visited[tmp];
                    dist++;
                }
                length = min(dist, length);
                cout << "um" << endl;
            }   else {
                cout << x << endl;
                q.push(x);
                visited[x] = i;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    graph.resize(N);
    visited.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(b);
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] == -1) { bfs(i); }
    }
    if (length == INT_MAX) { cout << -1; }
    else { cout << length; }
}
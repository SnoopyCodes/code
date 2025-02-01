#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> instruct(N);
    vector<int> in(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        instruct[u].push_back(v);
        in[v]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    vector<bool> visited(N);
    int count = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        visited[u] = true;
        count++;
        for (int v : instruct[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    if (count != N) {
        cout << "T_T" << "\n";
        cout << N - count << "\n";
    }   else {
        cout << "o (∩_∩) o" << "\n";
    }
}
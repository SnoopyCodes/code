#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> con(N);
    vector<int> in(N), out(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        con[u].push_back(v);
        in[v]++;
        out[u]++;
    }
    vector<int> main, alt;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    if (q.size() > 2 || *max_element(out.begin(), out.end()) > 2) {
        cout << "NO" << "\n";
        return 0;
    }
    bool use_alt = false;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        main.push_back(q.front());

        if (q.size()) {
            use_alt = true;
        }   else {
            
        }
    }
}
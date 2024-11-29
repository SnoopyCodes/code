#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> paths;
vector<int> color;
void dfs(int u, int c) {
    color[u] = c;
    for (int v : paths[u]) {
        if (color[v] == -1) { dfs(v, c); }
    }
}

void solve() {
    int N, M; cin >> N >> M;
    paths.clear(); paths.resize(N);
    color.clear(); color.resize(N, -1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        paths[u].push_back(v);
        paths[v].push_back(u);
    }
    //if 1 and N are connected, then output 0
    //try connecting 1 and N with 1 path: find min dist from marked
    //find intermediate, if it exists
    //color each one 
    for (int i = 0; i < N; i++) {
        if (color[i] == -1) { dfs(i, i); }
    }
    //for each color, find the closest color 0, and closest color N - 1
    vector<vector<int>> close(N, vector<int>(2, 1e5));
    int lz = -1e5, ln = -1e5;
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) { lz = i; }
        else if (color[i] == color[N-1]) { ln = i; }
        close[color[i]][0] = min(close[color[i]][0], i - lz);
        close[color[i]][1] = min(close[color[i]][1], i - ln);
    }
    lz = 2e5, ln = 2e5;
    for (int i = N - 1; i > -1; i--) {
        if (color[i] == 0) { lz = i; }
        else if (color[i] == color[N-1]) { ln = i; }
        close[color[i]][0] = min(close[color[i]][0], lz - i);
        close[color[i]][1] = min(close[color[i]][1], ln - i);
    }
    long long ans = 1e10;
    close[0][0] = 0; close[color[N-1]][1] = 0;
    for (int i = 0; i < N; i++) {
        ans = min(ans, (long long) close[i][0] * close[i][0] + (long long) close[i][1] * close[i][1]);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
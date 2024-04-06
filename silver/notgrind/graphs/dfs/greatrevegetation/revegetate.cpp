#include <bits/stdc++.h>

using namespace std;
struct Edge {
    int i1, i2;
    bool single, tested = false;
};
vector<vector<Edge>> adjpastures;
vector<int> pastures;
vector<bool> visited;
int dfs(int x, int g) {
    int count = !visited[x];  //so if not visited before, +1!!
    visited[x] = true;
    if (pastures[x] == 0) { pastures[x] = g; }
    else if (pastures[x] != g) { return INT_MIN; }
    for (int i = 0; i < adjpastures[x].size(); i++) {
        if (adjpastures[x][i].tested) { continue; }
        adjpastures[x][i].tested = true;
        int index = adjpastures[x][i].i2;
        if (x == adjpastures[x][i].i2) { index = adjpastures[x][i].i1; }
        if (adjpastures[x][i].single) { dfs(index, g); }
        else { dfs(index, -g); }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    adjpastures.resize(N);
    pastures.resize(N);
    visited.resize(N);
    for (int i = 0; i < M; i++) {
        char c; Edge e;
        cin >> c >> e.i1 >> e.i2;
        e.i1--; e.i2--;
        e.single = c == 'S';
        adjpastures[e.i1].push_back(e);
        adjpastures[e.i2].push_back(e);
    }
    int count = N;
    for (int i = 0; i < N; i++) {
        count -= visited[i];
        if (!visited[i]) {
            int size = dfs(i, 1);
            if (size < 0) { cout << 0; return 0; }  //no way to color this connected component
        }
    }
    cout << "1";
    for (int i = 0; i < count; i++) {
        cout << "0";
    }
}
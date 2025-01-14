#include <bits/stdc++.h>
#define long int64_t
using namespace std;

vector<vector<int>> roads;
vector<int> hay;

vector<vector<array<long, 2>>> weights;
vector<int> in;
int orders;

//returns the amount of hay needed for this subtree
long dfs(int u, int p) {
    long need = 0;
    for (int v : roads[u]) {
        if (v == p) { continue; }
        long res = dfs(v, u);
        if (res > 0) {
            weights[u].push_back({v, res});
            in[v]++;
            orders++;
        }   else if (res < 0) {
            weights[v].push_back({u, -res});
            in[u]++;
            orders++;
        }
        need += res;
    }
    return need - hay[u];
    //hay[u] - needs of all + above help = 0
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    roads.resize(N), hay.resize(N), weights.resize(N), in.resize(N);
    long target = 0;
    for (int i = 0; i < N; i++) {
        cin >> hay[i];
        target += hay[i];
    }
    target /= N;
    for (int i = 0; i < N; i++) {
        hay[i] -= target;
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        roads[u].push_back(v);
        roads[v].push_back(u);
    }
    dfs(0, -1);
    //transform it into a weighted graph
    //there are guaranteed to be no cycles
    //then toposort it
    cout << orders << "\n";
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) { q.push(i); }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : weights[u]) {
            cout << u + 1 << " " << v + 1 << " " << w << "\n";
            in[v]--;
            if (in[v] == 0) { q.push(v); }
        }
    }
}
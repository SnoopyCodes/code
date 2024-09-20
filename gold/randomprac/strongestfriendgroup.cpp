#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> degree;
vector<int> dsu;
vector<int> sizes;
int find(int u) {
    if (dsu[u] != u) { dsu[u] = find(dsu[u]); }
    return dsu[u];
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) { return; }
    if (sizes[u] < sizes[v]) { swap(u, v); }
    sizes[u] += sizes[v];
    dsu[v] = u;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    graph.resize(N);
    degree.resize(N);
    dsu.resize(N);
    sizes.resize(N);
    for (int i = 0; i < N; i++) {
        sizes[i] = 1;
        dsu[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a); // wait
        degree[a]++;
        degree[b]++;
    }
    //so basically for each component
    //so we should remove the ones that have least degree inside of the component
    //yeah
    //yeah
    //
    vector<bool> ingroup(N, true);
    set<array<int, 2>> nodes;

    for (int i = 0; i < N; i++) {
        nodes.insert({degree[i], i});
    }
    vector<int> order;
    while (!nodes.empty()) {
        int deg = (*nodes.begin())[0];
        int u = (*nodes.begin())[1];
        order.push_back(u);
        nodes.erase(nodes.begin());
        ingroup[u] = false;
        for (int v : graph[u]) {
            if (!ingroup[v]) { continue; }
            nodes.erase({degree[v], v});
            degree[v]--;
            nodes.insert({degree[v], v});
        }
    }
    reverse(order.begin(), order.end());
    degree.clear(); degree.resize(N, 0);
    int answer = 0;
    for (int u : order) {
        ingroup[u] = true;
        for (int v : graph[u]) {
            if (ingroup[v]) {
                degree[u]++;
                merge(u, v);
            }
        }
        answer = max(answer, sizes[find(u)] * (int) degree[u]);
    }
    cout << answer << "\n";
}
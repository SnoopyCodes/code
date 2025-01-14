#include <bits/stdc++.h>
#define long int64_t
using namespace std;

//can i just say that it was not fun to constant optimize this
//still 900 ms somehow idk how its that much slower than other sols

int S, E;
vector<vector<array<int, 2>>> roads;
vector<int> par;

vector<long> dijkstra(int source) {
    set<array<long, 2>> s;
    bool setp = source == S;
    vector<long> dist(roads.size(), 1e18);
    dist[source] = 0;
    s.insert({dist[source], source});
    while (!s.empty()) {
        auto [d, u] = *s.begin();
        s.erase(s.begin());
        for (auto [v, dd] : roads[u]) {
            if (dist[v] > dd + d) {
                if (setp) { par[v] = u; }
                s.erase({dist[v], v});
                dist[v] = dd + d;
                s.insert({dist[v], v});
            }
        }
    }
    return dist;
}

vector<vector<int>> tree;
int euler = 0;
vector<int> in, out;
void dfs(int u) {
    in[u] = euler++;
    for (int v : tree[u]) {
        dfs(v);
    }
    out[u] = euler;
}

bool anc(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M >> S >> E; S--; E--;
    roads.resize(N), par.resize(N), tree.resize(N), in.resize(N), out.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v, d; cin >> u >> v >> d; u--; v--;
        roads[u].push_back({v, d});
        roads[v].push_back({u, d});
    }
    
    vector<long> sdist = dijkstra(S), edist = dijkstra(E);

    int K; cin >> K;
    vector<int> lucky(K);
    for (int i = 0; i < K; i++) {
        cin >> lucky[i]; lucky[i]--;
        if (i > 0) { par[lucky[i]] = lucky[i-1]; }
    }
    for (int i = 0; i < N; i++) {
        if (i == S) { continue; }
        tree[par[i]].push_back(i);
    }
    dfs(S);
    
    for (int i = 0; i < K - 1; i++) {
        long ans = 1e18;
        for (int j = 0; j < N; j++) {
            if (!anc(lucky[i + 1], j)) { continue; }
            for (auto &[v, d] : roads[j]) {
                if (v == lucky[i] && j == lucky[i + 1] || anc(lucky[i + 1], v)) { continue; }
                ans = min(sdist[v] + edist[j] + d, ans);
            }
        }
        if (ans == 1e18) { cout << -1 << "\n"; }
        else { cout << ans << "\n"; }
    }
}
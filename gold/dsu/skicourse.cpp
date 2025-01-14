#include <bits/stdc++.h>
#define long int64_t
using namespace std;

vector<vector<array<int, 2>>> root;
vector<vector<int>> sizes, starts;
array<int, 2> find(array<int, 2> u) {
    if (root[u[0]][u[1]] != u) { root[u[0]][u[1]] = find(root[u[0]][u[1]]); }
    return root[u[0]][u[1]];
}
int merge(array<int, 2> u, array<int, 2> v) {
    u = find(u);
    v = find(v);
    if (u == v) { return 0; }
    if (sizes[u[0]][u[1]] < sizes[v[0]][v[1]]) { swap(u, v); }
    sizes[u[0]][u[1]] += sizes[v[0]][v[1]];
    root[v[0]][v[1]] = u;
    starts[u[0]][u[1]] += starts[v[0]][v[1]];
    return sizes[u[0]][u[1]];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);
    int N, M, T; cin >> N >> M >> T;
    vector<vector<int>> elev(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> elev[i][j];
        }
    }
    //sort edges and add stuff
    long ans = 0;
    vector<array<int, 5>> edges;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i + 1 < N) { edges.push_back({abs(elev[i][j] - elev[i+1][j]), i, j, i + 1, j}); }
            if (j + 1 < M) { edges.push_back({abs(elev[i][j] - elev[i][j+1]), i, j, i, j + 1}); }
        }
    }
    sort(edges.begin(), edges.end());
    root.resize(N, vector<array<int, 2>>(M));
    sizes.resize(N, vector<int>(M, 1));
    starts.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> starts[i][j];
            root[i][j] = {i, j};
        }
    }
    
    for (auto e : edges) {
        int d = e[0];
        array<int, 2> u = {e[1], e[2]};
        array<int, 2> v = {e[3], e[4]};
        if (merge(u, v) >= T) {
            auto res = find(u);
            ans += (long) d * starts[res[0]][res[1]];
            starts[res[0]][res[1]] = 0;
        }
    }
    cout << ans << "\n";
}
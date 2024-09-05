#include <bits/stdc++.h>
using namespace std;

vector<int> dsu;
vector<int> sizes;

vector<vector<array<int, 2>>> mst;
vector<int> depths;

int find(int u) {
	if (dsu[u] == u) { return u; }
	dsu[u] = find(dsu[u]);
	return dsu[u];
}
void merge(int u, int v, int d) {
	mst[u].push_back({v, d});
	mst[v].push_back({u, d});
	u = find(u);
	v = find(v);
	if (sizes[u] < sizes[v]) { swap(u, v); }  //merge v to u
	sizes[u] += sizes[v];
	dsu[v] = u;
}
vector<vector<int>> jumps;
vector<vector<int>> vals;
vector<bool> visited;
void dfs(int u, int from, int d, int val) {
	depths[u] = d;
	visited[u] = true;
	jumps[0][u] = from;
    vals[0][u] = val;
	for (auto const&[v, dist] : mst[u]) {
		if (v == from) { continue; }
		dfs(v, u, d + 1, dist);
	}
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int N, M, Q; cin >> N >> M >> Q;
	dsu.resize(N);
	mst.resize(N);
	depths.resize(N);
	for (int i = 0; i < N; i++) { dsu[i] = i; }
	sizes.resize(N, 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b; a--; b--;
		if (find(a) != find(b)) { merge(a, b, i + 1); }
	}
	
	visited.resize(N);
	int max_jumps = __lg(N - 1) + 1;
	jumps.resize(max_jumps, vector<int>(N));
	vals.resize(max_jumps, vector<int>(N));
	for (int i = 0; i < N; i++) {
		if (!visited[i]) { dfs(i, -1, 0, 0); }
	}
	for (int i = 1; i < max_jumps; i++) {
		for (int j = 0; j < N; j++) {
			if (jumps[i-1][j] != -1) {
				jumps[i][j] = jumps[i-1][jumps[i-1][j]];
				vals[i][j] = max(vals[i-1][j], vals[i-1][jumps[i-1][j]]);
			}
		}
	}
	
    for (int q = 0; q < Q; q++) {
        int a, b; cin >> a >> b; a--;  b--;
		if (find(a) != find(b)) { cout << -1 << "\n"; continue; }
        //now we need to find like
		int ma = 0, mb = 0;
        if (depths[b] > depths[a]) { swap(a, b); }
        int equalize = depths[a] - depths[b];
        for (int i = 0; i < max_jumps; i++) {
            if (equalize & 1 << i) {
				ma = max(ma, vals[i][a]);
				a = jumps[i][a];
			}
        }
        for (int i = max_jumps - 1; i > -1; i--) {
            if (jumps[i][a] != jumps[i][b]) {
				ma = max(ma, vals[i][a]);
                a = jumps[i][a];
				mb = max(mb, vals[i][b]);
                b = jumps[i][b];
            }
        }
		if (a != b) {
			ma = max(ma, vals[0][a]);
			mb = max(mb, vals[0][b]);
		}
		cout << max(ma, mb) << "\n";
        //lca obtained, in theory
		//what about 3 5 screws it up?
		//ok why did our lca just die
    }
}

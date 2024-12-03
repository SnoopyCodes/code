// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> in_cyc;
int h;
void dfs(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (visited[v]) {
			if (in_cyc[v] || v == h) { in_cyc[u] = true; }
			continue;
		}
		dfs(v);
		if (in_cyc[v]) { in_cyc[u] = true; }
	}
}
int main() {
	int N; cin >> N;
	adj.resize(N);
	vector<vector<int>> wish(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		bool found = false;
		for (int j = 0; j < N; j++) {
			cin >> wish[i][j]; wish[i][j]--;
			if (wish[i][j] == i) { found = true; }
			if (found) { continue; }
			adj[i].push_back(wish[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		visited.clear(); visited.resize(N);
		in_cyc.clear(); in_cyc.resize(N);
		h = i;
		dfs(i);
		int best;
		for (int j = 0; j < N; j++) {
			if (in_cyc[wish[i][j]] || wish[i][j] == i) { best = wish[i][j]; break; }
		}
		cout << best+1 << "\n";
	}
}

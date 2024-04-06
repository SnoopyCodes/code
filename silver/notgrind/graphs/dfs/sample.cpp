#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> rep;

void dfs(int node) {
	cout << ";-;";
	visited[node] = true;
	for (int u : adj[node])
		if (!visited[u]) dfs(u);
}

int count_components() {
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			count++;
			rep.push_back(i);
			dfs(i);
		}
	}
	return count;
}

int main() {
	int M;
    freopen("input.in", "r", stdin);
	
	cin >> N >> M;
	adj.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = count_components();
	cout << ans - 1 << endl;
	for (int i = 1; i < ans; i++) {
		cout << rep[i - 1] << " " << rep[i] << endl;
	}
}
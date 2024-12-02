#include <bits/stdc++.h>

using namespace std;

vector<vector<array<int, 2>>> cows;
vector<bool> visited;
vector<int> edges;
vector<bool> used;
int back;
void dfs(int u, int p) {
	visited[u] = true;
	for (auto [v, e] : cows[u]) {
        if (visited[v]) {
            if (back == -1 && v != p) {
                used[e] = true;
                back = e;
            }
            continue;
        }
        edges.push_back(e);
        used[e] = true;
        dfs(v, u);
	}
}

vector<int> order;
void dfs2(int u, int p) {
    for (auto [v, e] : cows[u]) {
        if (!used[e] || e == back || p == v) { continue; }
        order.push_back(e);
        dfs2(v, u);
    }
}

int main() {
	int N, M; cin >> N >> M;
	cows.resize(M);
	visited.resize(M);
    used.resize(N);
    vector<array<int, 2>> likes(N);
	for (int i = 0; i < N; i++) {
		int u, v; cin >> u >> v; u--; v--;
        likes[i] = {u, v};
		cows[u].push_back({v, i});
		cows[v].push_back({u, i});
	}

	for (int i = 0; i < M; i++) {
		if (!visited[i]) {
            back = -1;
            dfs(i, -1);
            if (back != -1) {
                order.push_back(back);
                dfs2(likes[back][0], -1);
            }   else {
                for (int x : edges) {
                    order.push_back(x);
                }
            }
            edges.clear();
        }
	}

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (!used[i]) { cnt++; order.push_back(i); }
    }
    cout << cnt << "\n";
    for (int x : order) {
        cout << x + 1 << "\n";
    }
}
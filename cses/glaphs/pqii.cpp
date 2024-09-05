#include <bits/stdc++.h>
using namespace std;
//i am in pain
vector<int> tp;
vector<int> dists; // dist from cycle if not cycle, cycle idx if in
vector<int> in_cycle;
vector<vector<int>> cycles;
stack<int> path;
vector<int> visited;
const int done = 2;
const int stacked = 1;
 
int ncycles = 0;
int dfs(int u) {
	visited[u]++;
	if (visited[tp[u]] == done) {  //we have visited this before
		if (in_cycle[tp[u]] != -1) { dists[u] = 1; } //in cycle
		else { dists[u] = dists[tp[u]] + 1; }  //leads to cycle
		visited[u] = 2;
		return dists[u] + 1;
	}	else if (visited[tp[u]] == stacked) {
		//create cycle..
		cycles.push_back({});
		int ep = tp[u]; //endpoint
		path.push(u);
		int popped = -1;
		int idx = 0;
		while (popped != ep) {
			//wtf
			popped = path.top();
			path.pop();
			in_cycle[popped] = ncycles;
			cycles[ncycles].push_back(popped);
			visited[popped] = 2;
			dists[popped] = idx++;
		}
		ncycles++;
		return 1;
	}	else {
		path.push(u);
		int res = dfs(tp[u]);
		visited[u] = 2;
		//if we are not in cycle, set everything
		if (in_cycle[u] == -1) { path.pop(); dists[u] = res; return res+1; }
		return res;
	}
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
	int N, Q; cin >> N >> Q;
	int max_jumps = __lg(N - 1) + 1;
	vector<vector<int>> jumps(max_jumps, vector<int>(N));
	dists.resize(N, -1);
	tp.resize(N);
	visited.resize(N);
	in_cycle.resize(N, -1);
	
	for (int i = 0; i < N; i++) {
		int k; cin >> k; k--;
		jumps[0][i] = k;
		tp[i] = k;
	}
	for (int i = 1; i < max_jumps; i++) { //this is fine
		for (int j = 0; j < N; j++) {
			jumps[i][j] = jumps[i-1][jumps[i-1][j]];
		}
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) { dfs(i); }
	}
	for (int q = 0; q < Q; q++) {
		int a, b; cin >> a >> b; a--; b--;
		//ok now we need to take in queries...
		int disttocycle = 0;
		if (in_cycle[b] != -1 && in_cycle[a] == -1) { //try to lift a up to cycle
			disttocycle = dists[a];
			for (int i = 0; i < max_jumps; i++) {
				if (disttocycle & 1 << i) { a = jumps[i][a]; }
			}
		}
		if (in_cycle[a] == in_cycle[b] && in_cycle[a] != -1) {  //in same cycle
			cout << disttocycle + (dists[a] - dists[b] + cycles[in_cycle[a]].size())
				% cycles[in_cycle[a]].size() << "\n";
		} 	else if (in_cycle[a] == in_cycle[b]){ //both in tree i guess
			int diff = dists[a] - dists[b];
			if (diff < 0) { cout << -1 << "\n"; continue; }
			for (int i = 0; i < max_jumps; i++) {
				if (diff & 1 << i) { a = jumps[i][a]; }
			}
			if (a != b) { cout << -1 << "\n"; continue; }
			cout << diff << "\n";
		}	else {
			cout << -1 <<"\n";
		}
		
	}
}
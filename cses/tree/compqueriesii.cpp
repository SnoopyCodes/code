#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> glaph;
vector<int> depths;
void dfs(int u, int d) {
	depths[u] = d;
	for (int v : glaph[u]) {
		dfs(v, d + 1);
	}
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
	int N, Q; cin >> N >> Q;
	int max_jumps = __lg(N - 1) + 1;
	vector<vector<int>> jumps(max_jumps, vector<int>(N));
	depths.resize(N);
	glaph.resize(N);  
	jumps[0][0] = 0;
	for (int i = 1; i < N; i++) {
		int k; cin >> k; k--;
		jumps[0][i] = k;
		glaph[k].push_back(i);
	}
	for (int i = 1; i < max_jumps; i++) {
		for (int j = 0; j < N; j++) {
			jumps[i][j] = jumps[i-1][jumps[i-1][j]];
		}
	}
	dfs(0, 0);
	for (int q = 0; q < Q; q++) {
		int a, b; cin >> a >> b; a--; b--;
		if (depths[b] > depths[a]) { swap(a, b); }  //a has higher depth
		int equalize = depths[a] - depths[b];  //jump here
        for (int i = 0; i < max_jumps; i++) {
            if (equalize & 1 << i) { a = jumps[i][a]; }
        }
        if (a == b) { cout << a + 1 << "\n"; continue; }
        for (int i = max_jumps - 1; i > -1; i--) {
            if (jumps[i][a] != jumps[i][b]) { a = jumps[i][a]; b = jumps[i][b]; }
        }
        cout << jumps[0][a] + 1 << "\n";
	}
}
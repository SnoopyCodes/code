// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
vector<vector<int>> flights;
int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int N, M; cin >> N >> M;
	flights.resize(N);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b; a--; b--;
		flights[b].push_back(a);  //a can travel to be
	}
	vector<vector<int>> possible(1 << N, vector<int>(N));  //mask, last
	possible[1][0] = 1;
	for (int mask = 3; mask < 1 << N; mask++) {
		//for every single bit
        if (!(mask & 1)) { continue; }
		for (int b = 1; b < N; b++) {  //destination
			//if there is a way to get from the last added bit to our current one
			//remove the current bit
			if ((mask & (1 << b)) == 0) { continue; }
			int from = mask ^ 1 << b;
			for (int from_b : flights[b]) {
				if (!(from & 1 << from_b)) { continue; }
				possible[mask][b] += possible[from][from_b];
				possible[mask][b] %= MOD;
			}
		}
	}
	cout << possible[(1 << N) - 1][N - 1];
}

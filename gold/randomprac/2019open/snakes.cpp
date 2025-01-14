#include <bits/stdc++.h>
#define vec vector
using namespace std;

int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	int N, K; cin >> N >> K;
	vec<int> snake(N);
	for (int i = 0; i < N; i++) {
		cin >> snake[i];
	}
	vec<vec<vec<int>>> dp(N, vec<vec<int>>(K + 1, vec<int> (N, 1e9)));
	for (int i = 0; i < N; i++) {
		if (snake[i] < snake[0]) { continue; }
		dp[0][0][i] = snake[i] - snake[0];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			int minprev = 1e9;
			if (j > 0) {
				for (int k = 0; k < N; k++) {
					minprev = min(dp[i-1][j-1][k], minprev);
				}
			}
			for (int k = 0; k < N; k++) {
				if (snake[k] < snake[i]) { continue; }
				dp[i][j][k] = dp[i-1][j][k] + snake[k] - snake[i];
				if (j > 0) {
					dp[i][j][k] = min(dp[i][j][k], minprev + snake[k] - snake[i]);
				}
			}
		}
	}
	int ans = 1e9;
	for (int i = 1; i < K + 1; i++) {
		for (int j = 0; j < N; j++) {
			ans = min(ans, dp[N-1][i][j]);
		}
	}
	cout << ans << "\n";
}

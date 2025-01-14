import sys
sys.stdin = open("snakes.in", "r")
sys.stdout = open("snakes.out", "w")
N, K = map(int, input().split())
snake = list(map(int, input().split()))
inf = int(1e9)
dp = [[inf for j in range(N)] for k in range(K + 1)] #min in changes and size
for i in range(N):
	if snake[i] < snake[0]:
		continue
	dp[0][i] = snake[i] - snake[0]
for i in range(1, N):
	for j in range(K, -1, -1):
		if j > 0:
			minprev = min(dp[j-1])
		for k in range(N):
			if snake[k] < snake[i]:
				dp[j][k] = inf
				continue
			dp[j][k] = dp[j][k] + snake[k] - snake[i]
			if j > 0:
				dp[j][k] = min(dp[j][k], minprev + snake[k] - snake[i])
ans = inf
for i in range(K + 1):
	for j in range(N):
		ans = min(ans, dp[i][j])
print(ans)
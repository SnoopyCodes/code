import sys
def il(): return list(map(int, sys.stdin.readline().split()))
def ii(): return int(input())

N = ii()
A = [x - 1 for x in il()]
occ = [[] for i in range(N)]
for i, x in enumerate(A):
    occ[x] += [i]

for i in range(N):
    if len(occ[i]) > 1:
        lst = occ[i].pop()
        while len(occ[i]) > 1:
            occ[i].pop()
        occ[i] += [lst]

# just going to assume my dp is right then?
# then what?
# 

dp = [0] * N
for i in range(N):
    if len(occ[A[i]]) > 1 and i == occ[A[i]][1]:
        j = occ[A[i]][0]
        if j > 0:
            best = max(dp[0:j])
        else:
            best = 0
        for k in range(j + 1, i):
            dp[k] = max(dp[k], best + 1)
            best = max(best + 1, dp[k] - 1)
    dp[i] = dp[i-1]

print(dp[N-1])
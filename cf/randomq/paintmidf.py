import sys
def il(): return list(map(int, sys.stdin.readline().split()))
def ii(): return int(input())

N = ii()
A = [x - 1 for x in il()]
occ = [[] for i in range(N)]
for i, x in enumerate(A):
    occ[x] += [i]

beg = [0] * N
end = [0] * N

for i in range(N):
    if len(occ[i]) > 1:
        first = occ[i][0]
        last = occ[i][-1]
        beg[first] += 1
        end[last] -= 1



dp = [[0,0] for i in range(N)] # not end of segment, is end of segment
overlapped = beg[0] + end[0]

for i in range(1, N):
    overlapped += end[i]
    if end[i]:
        j = occ[A[i]][0]
        if j > 0:
            p = max(dp[j - 1])
        else:
            p = 0
        dp[i][1] = p + i - j - 1
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
    if overlapped:
        dp[i][0] = max(dp[i - 1][0] + 1, dp[i][0])
    overlapped += beg[i]

print(*dp)

print(max(dp[N-1]))
import sys
rd = lambda: list(map(int, sys.stdin.readline().split()))

N, M = rd()
ways = [0] * (N + 1)
ways[N] = 1
suff = [0] * (2 * N + 2)
suff[N] = 1
for i in range(N - 1, 0, -1):
    ways[i] += suff[i + 1]
    mult = 2
    while i * mult <= N:
        ways[i] += suff[i * mult] - suff[(i + 1) * mult] + M
        mult += 1
    ways[i] %= M
    suff[i] = (suff[i + 1] + ways[i]) % M
    
print(ways[1])
"""
floored division
we are suffix summing this...
n <= 4e6 is insane...
"""
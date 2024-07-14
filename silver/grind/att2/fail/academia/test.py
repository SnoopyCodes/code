N, K, L = map(int, input().split())
cites = list(map(int, input().split()))
cites.sort()
def valid(g):
    diff = 0
    if cites[N - g] + K < g: return False
    for i in range(N - g, N):
        diff += max(g - cites[i], 0)
    return diff <= K * L
s = 0
e = N + 1
while s + 1 < e:
    m = (s + e) // 2
    if valid(m):
        s = m
    else:
        e = m
print(s)
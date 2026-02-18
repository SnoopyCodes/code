import sys, math
oo = int(1e9 + 7)
sys.setrecursionlimit(oo)

rd = lambda: list(map(int, sys.stdin.readline().split()))

N, M = rd()
E = [()] * M
uf = []
size = []

def find(u):
    global uf
    if uf[u] == u: return u
    uf[u] = find(uf[u])
    return uf[u]

for i in range(M):
    E[i] = tuple(rd())

lo, hi = 0.01, 101
ansn, ansd = -1, -1
while lo + 1e-3 < hi:
    mid = (lo + hi) / 2
    edges = [(E[i][0], E[i][1], E[i][2] - mid * E[i][3], i) for i in range(M)]
    edges.sort(key=lambda e:e[2],reverse=1)
    uf = [i for i in range(N)]
    size = [1] * N
    cur = 0
    num, den = 0, 0
    for u, v, w, i in edges:
        if find(u) == find(v):
            continue
        u, v = find(u), find(v)
        if size[u] < size[v]:
            u, v = v, u
        size[u] += size[v]
        uf[v] = u
        den += E[i][3]
        num += E[i][2]
        cur += w
    if cur >= 0:
        lo = mid
        ansn, ansd = num, den
    else:
        hi = mid
gcd = math.gcd(ansn, ansd)
print(str(ansn // gcd) + "/" + str(ansd // gcd))
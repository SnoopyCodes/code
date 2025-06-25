import sys
zz, zzi = [], -1
def istr():
    global zzi, zz
    zzi += 1
    if zzi == len(zz): zz, zzi = sys.stdin.readline().split(), 0
    return zz[zzi]
def iint(): return int(istr())

import math

MOD = int(1e9 + 7)

for _ in range(iint()):
    A, B, K = iint(), iint(), iint()
    N = ((A - 1) * K + 1) % MOD
    M = K * (B - 1) * math.comb(N, A) % MOD + 1
    print(N, M)

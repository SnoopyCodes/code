import sys
md, rd, rn = 10**9 + 7, lambda: list(map(int, sys.stdin.readline().split())), range

for _ in rn(rd()[0]):
    N, M = rd()
    A = rd()
    for i in rn(N):
        A[i] -= 1
    curv = [i for i in rn(N)]
    B = [i for i in rn(N)]
    for _ in rn(M):
        i, j = rd()
        i -= 1 ; j -= 1
        
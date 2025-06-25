import sys
zz, zzi = [], -1
def istr():
    global zzi, zz
    zzi += 1
    if zzi == len(zz): zz, zzi = sys.stdin.readline().split(), 0
    return zz[zzi]
def iint(): return int(istr())

for _ in range(iint()):
    N = iint()
    A = [(iint(), i) for i in range(N)]
    # basically, for the ith it means that there are
    # A[i] numbers > -B[i], for whatever value we give it
    A.sort()
    # for A[0], this is our least element
    # suppose we only play permutation
    # if it is 0, assign it -N
    # if it is 1, then A[N - 1] has to = N?
    # if it is 2, then 
    # ok that was what i thought
    # so then 1 and N are either of 2 possibilities

    B = [0] * N
    ok = True
    for i in range(N // 2):
        if A[i][0] == i + 1:
            B[A[i][1]] = -N + i * 2 + 1
            B[A[N - i - 1][1]] = N - i * 2
        elif A[i][0] == i:
            B[A[i][1]] = -N + i * 2
            B[A[N - i - 1][1]] = N - i * 2 - 1
        else:
            ok = False
    if N == 1:
        if A[0][0] == 1:
            print(1)
        else:
            print(-1)
        continue
    if N & 1:
        p = A[(N // 2)][1]
        ct = 1
        for i in range(N):
            if i == p: continue
            if B[i] + (N // 2) > 0:
                ct += 1
        if ct == A[(N // 2)][0]:
            B[p] = (N // 2)
        else:
            ct = 0
            for i in range(N):
                if i == p: continue
                if B[i] + -N // 2 > 0:
                    ct += 1
            if ct == A[(N // 2)][0]:
                B[p] = -(N // 2)
            else:
                ok = False

    if ok:
        print("YES")
        print(*B)
    else:
        print("NO")
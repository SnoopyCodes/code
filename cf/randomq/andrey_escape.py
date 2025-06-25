import sys
zz, zzi = [], -1
def istr():
    global zzi, zz
    zzi += 1
    if zzi == len(zz): zz, zzi = sys.stdin.buffer.readline().split(), 0
    return zz[zzi]
def iint(): return int(istr())

for _ in range(iint()):
    N = iint()
    A = [0] * N
    for i in range(N):
        l, r, a, b = iint(), iint(), iint(), iint()
        A[i] = (l, -b)
    A.sort()
    
    max_right = 0
    cur_left = 0
    seg = []
    for i in range(N):
        if max_right < A[i][0]:
            seg.append((cur_left, max_right))
            cur_left, max_right = A[i][0], -A[i][1]
        else:
            max_right = max(max_right, -A[i][1])
    seg.append((cur_left, max_right))

    Q = iint()
    for i in range(Q):
        x = iint()
        s, e = -1, len(seg)
        while s + 1 < e: # find first <=
            m = (s + e) // 2
            if seg[m][0] <= x: s = m
            else: e = m
        print(max(x, seg[s][1]))
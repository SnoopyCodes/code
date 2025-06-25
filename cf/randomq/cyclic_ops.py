import sys
input_line, input_ind = [], -1
def istr():
    global input_ind, input_line
    input_ind += 1
    if input_ind == len(input_line):
        input_line, input_ind = sys.stdin.readline().split(), 0
    return input_line[input_ind]
def iint(): return int(istr())

def solve():
    N, K = iint(), iint()
    B = [0] * N
    for i in range(N):
        B[i] = iint() - 1
    """
    we select some indices from [1, n]
    and for each i in l, change it to the next one mod k
    this is what we call "nontrivial"
    let's form a graph out of it.
    if K = 1 we can only set A[i] to i
    else we are giving "i" value to smth else
    the path lengths must be divisible by k??
    for the functional
    as long as all cycles are size K ok?
    good problem
    you could simply copy an algo from online
    this is why everyhting is so stupid bro
    """
    status = [0] * N
    in_cycle = [False] * N
    ok = True
    for i in range(N):
        if status[i]: continue
        u = i
        path = []
        while not status[u]:
            status[u] = 1
            path.append(u)
            u = B[u]
        if status[u] == 1:
            cyc_size = 0
            while not in_cycle[u]:
                in_cycle[u] = True
                u = B[u]
                cyc_size += 1
            if cyc_size != K:
                ok = False
                break
        while path: status[path.pop()] = 2
    if K == 1:
        for i in range(N):
            ok &= B[i] == i
    print("Yes") if ok else print("No")

for _ in range(iint()):
    solve()
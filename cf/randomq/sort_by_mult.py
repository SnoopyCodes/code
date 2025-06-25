import sys
input_line, input_ind = [], -1
def istr():
    global input_ind, input_line
    input_ind += 1
    if input_ind == len(input_line):
        input_line, input_ind = sys.stdin.readline().split(), 0
    return input_line[input_ind]
def iint(): return int(istr())

for _ in range(iint()):
    N = iint()
    A = [0] * N
    for i in range(N):
        A[i] = iint()
    
    # we may multiply the front by a negative value
    # then, in this negative, for each time original A[i] < A[i + 1]
    # we have to perform a multiplication
    houzhui = [0] * N
    for i in range(N - 2, -1, -1):
        houzhui[i] = A[i] >= A[i + 1]
        if i < N - 1: houzhui[i] += houzhui[i + 1]
    daan = houzhui[0]
    ct = 1
    for i in range(N - 1):
        # multiply up to i by -1
        daan = min(daan, ct + houzhui[i + 1])
        if A[i] <= A[i + 1]: ct += 1
    print(daan)
        
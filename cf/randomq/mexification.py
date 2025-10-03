import sys
 
input = sys.stdin.readline
 
def il():
    return list(map(int, input().split()))
 
for _ in range(int(input())):
    N, K = il()
    ct = [0] * (N + 1)
    A = il()
    for i in range(N):
        ct[A[i]] += 1
    pref = 0
    while ct[pref] == 1:
        pref += 1
    if pref == N - 1:
        print(N * (N - 1) // 2)
        continue
    mex = 0
    while ct[mex]:
        mex += 1
    pref_sum = pref * (pref - 1) // 2
    rem = N - pref
    rem_sum = 0
    if K == 1:
        ans = 0
        for i in range(N + 1):
            if i > mex:
                ans += ct[i] * mex
            elif ct[i] == 1:
                ans += i
            else:
                ans += ct[i] * mex
        print(ans)
    else:
        if pref != mex:
            # they become pref
            # then if K % 2 == 0 pref, else pref + 1
            rem_sum = rem * (pref if K % 2 == 0 else pref + 1)
        else:
            #if pref = mex
            # 
            rem_sum = rem * (pref + 1 if K % 2 == 0 else pref)
        print(pref_sum + rem_sum)

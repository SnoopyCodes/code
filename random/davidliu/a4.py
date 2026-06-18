import sys
md, rd, rn = 10**9 + 7, lambda: list(map(int, sys.stdin.readline().split())), range

for _ in rn(rd()[0]):
    N = rd()[0]
    if N == 1:
        print(0)
        continue
    primes = []
    it = 2
    while N > 1 and it * it <= N:
        if N % it == 0:
            primes.append(it)
            N //= it
        else:
            it += 1
    if N > 1:
        primes.append(N)
    M = len(primes)
    dp = 1
    cur = primes[0]
    for i in rn(1, M):
        p = primes[i]
        # find (cur * p)' = cur' * p + p' * cur
        ndp = dp * p + cur
        dp = ndp
        cur *= p
    from math import gcd
    print(gcd(cur, dp))

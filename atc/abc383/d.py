import math as math
N = int(input())
pl = int(math.sqrt(N)) + 1
sieve = [False] * pl
primes = []
for i in range(2, pl):
    if not sieve[i]:
        primes += [i]
        for j in range(2 * i, pl, i):
            sieve[j] = True
ans = 0
for p in primes:
    if math.pow(p, 8) <= N:
        ans += 1
for i in range(len(primes)):
    s = -1
    e = i
    while s + 1 < e:
        m = (s + e) // 2
        if primes[m] * primes[m] * primes[i] * primes[i] <= N:
            s = m
        else:
            e = m
    ans += e
print(ans)
T, K = map(int, input().split())
T -= 1

def comb(n, k): # math.comb doesnt exist for usaco
    num, den = 1, 1
    for t in range(1, min(k, n - k) + 1):
        num *= n
        den *= t
        n -= 1
    return num // den

choose = [comb(T, i) / 2**T for i in range(T + 1)]
exp = [i * choose[i] for i in range(T + 1)]

C = [sum(choose[i:]) for i in range(T + 1)] # chance that anything >= i is rolled
E = [sum(exp[i:]) for i in range(T + 1)] # expected value of roll GIVEN THAT the roll >= i

def g(x, n, c):
    return (E[x] - E[x] * (1-C[x])**n) / C[x] + c * (1-C[x])**n

prev, pv = 0, 0
for t in range(1, T + 1):
    s = prev
    e = K + 1
    while s + 1 < e:
        m = (s + e) // 2
        if t > g(t, m - prev - 1, pv):
            s = m
        else:
            e = m
    if s != prev:
        pv = g(t, s - prev, pv)
        prev = s
print(pv + 1)
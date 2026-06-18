import sys
md, rd, rn = 10**9 + 7, lambda: list(map(int, sys.stdin.readline().split())), range

qp = lambda a, b = -1, c = md: pow(a, b, c)
def comb(n):
    f, nf = [1] * (n + 1), [1] * (n + 1)
    for i in rn(2, n + 1): f[i] = f[i - 1] * i % md
    nf[n] = qp(f[n])
    for i in reversed(rn(2, n)): nf[i] = nf[i + 1] * (i + 1) % md
    return f, nf, lambda n, k: 0 if n < k else f[n] * nf[k] * nf[n - k] % md
# ex: fac, ifac, C = comb(N)
N = rd()[0]
# how many ways are there to arrange in mountain, essentially.
fac, ifac, C = comb(N)
print((fac[N] - qp(2, N - 1) + md) % md)
import sys
md, rd, rn = 10**9 + 7, lambda: list(map(str, sys.stdin.readline().split())), range

qp = lambda a, b = -1, c = md: pow(a, b, c)
def comb(n):
    f, nf = [1] * (n + 1), [1] * (n + 1)
    for i in rn(2, n + 1):
        f[i] = f[i - 1] * i % md
    nf[n] = qp(f[n])
    for i in reversed(rn(2, n)):
        nf[i] = nf[i + 1] * (i + 1) % md
    return f, nf, lambda n, k: 0 if n < k else f[n] * nf[k] * nf[n - k] % md

def make_seg(n, d, f):
    t = [d] * 2 * n
    def set(i, v):
        t[(i := i + n)] = v
        while i := i >> 1:
            t[i] = f(t[i << 1], t[i << 1 | 1])
    def query(l, r):
        l, r = l + n, r + n
        resl = resr = d
        while l < r:
            if l & 1: resl = f(resl, t[l]) ; l += 1
            if r & 1: r -= 1 ; resr = f(t[r], resr)
            l, r = l >> 1, r >> 1
        return f(resl, resr)
    return set, query



def make_dsu(n):
    par, size = [i for i in rn(n)], [1] * n
    def find(u):
        while u != par[u]:
            u = par[u] = par[par[u]]
        return u
    def union(u, v):
        u, v = find(u), find(v)
        if u != v:
            if size[u] < size[v]:
                u, v = v, u
            par[v] = u
            size[u] += size[v]
            return 1
        return 0
    return union, find, size
from collections import defaultdict as dd

def make_sieve(n):
    sieve = [0] * (n + 1)
    for i in rn(2, n + 1):
        if sieve[i]:
            continue
        for j in rn(i, n + 1, i):
            sieve[j] = i
    def prime_facs(x):
        res = dd(int)
        while x > 1:
            res[sieve[x]] += 1
            x //= sieve[x]
        return res
    def factors(n):
        all = []
        i = 1
        while i * i <= n:
            if n % i == 0:
                all.append(i)
                if n // i != i:
                    all.append(n // i)
            i += 1
        return all
    return sieve, prime_facs, factors


def make_lz_seg(A, dv, du, S, F, M):
    n, h = len(A), len(A).bit_length() - 1
    t, lz, sz = [0] * n + A, [du] * 2 * n, [1] * 2 * n
    for x in rn(n - 1, 0, -1):
        sz[x] = sz[x << 1] + sz[x << 1 | 1]
        t[x] = S(t[x << 1], t[x << 1 | 1])
    def apply(x, u):
        t[x] = F(t[x], u, sz[x])
        lz[x] = M(lz[x], u)
    def process(l, r, u = du):
        upd, l, r = u != du, l + n, r + n
        for x in l, r - 1:
            for lvl in rn(h, 0, -1):
                y = x >> lvl
                if lz[y] != du:
                    apply(y<<1, lz[y]), apply(y<<1|1, lz[y])
                    lz[y] = du
        a, b = (l, r) if upd else (dv, dv)
        while l < r:
            if l & 1: apply(l, u) if upd else (a := S(a, t[l])) ; l += 1
            if r & 1: r -= 1 ; apply(r, u) if upd else (b := S(t[r], b))
            l, r = l >> 1, r >> 1
        if upd:
            for x in a, b - 1:
                while x := x >> 1:
                    t[x] = F(S(t[x<<1], t[x<<1|1]), lz[x], sz[x])
        else:
            return S(a, b)
    return process
import sys
md, rd, rn = 10**9 + 7, lambda: list(map(int, sys.stdin.readline().split())), range

def comb(n):
    fac, ifac = [1] * (n + 1), [1] * (n + 1)
    for i in rn(2, n + 1): fac[i] = fac[i - 1] * i % md
    ifac[n] = pow(fac[n], -1, md)
    for i in rn(n - 1, 1, -1): ifac[i] = ifac[i + 1] * i % md
    return fac, ifac, lambda n, k: fac[n] * ifac[k] * ifac[n - k] % md

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
        if par[u] != u:
            par[u] = find(par[u])
        return par[u]
    def union(u, v):
        u, v = find(u), find(v)
        if u != v:
            if size[u] < size[v]:
                u, v = v, u
            par[v] = u
            size[u] += size[v]
            return 1
        return 0
    return union, find

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
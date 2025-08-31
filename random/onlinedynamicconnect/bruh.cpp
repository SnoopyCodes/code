#include <bits/stdc++.h>
typedef int LL;
typedef double dl;
#define opt operator
#define pb push_back
#define pii std::pair<LL,LL>
const LL maxn = 5e3 + 9, mod = 998244353, inf = 0x3f3f3f3f;
LL Read() {
    LL x(0), f(1);
    char c = getchar();

    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;

        c = getchar();
    }

    while (c >= '0' && c <= '9') {
        x = (x << 3ll) + (x << 1ll) + c - '0';
        c = getchar();
    }

    return x * f;
}
void Chkmin(LL &x, LL y) {
    if (y < x)
        x = y;
}
void Chkmax(LL &x, LL y) {
    if (y > x)
        x = y;
}
LL add(LL x, LL y) {
    return x += y, x >= mod ? x - mod : x;
}
LL dec(LL x, LL y) {
    return x -= y, x < 0 ? x + mod : x;
}
LL mul(LL x, LL y) {
    return 1ll * x * y % mod;
}
LL Pow(LL base, LL b) {
    LL ret(1);

    while (b) {
        if (b & 1)
            ret = mul(ret, base);

        base = mul(base, base);
        b >>= 1;
    }

    return ret;
}
LL n, m;
LL vis[maxn][maxn], inq[maxn][maxn], dep[maxn][maxn];
struct LCT {
    LL son[maxn][2], rev[maxn], fa[maxn], size[maxn], light_sz[maxn];
    std::set<pii> S[maxn], T[maxn];
    pii Skey[maxn], Tkey[maxn];
    void Init(LL N) {
        for (LL i = 1; i <= N; ++i)
            size[i] = 1;

        for (LL i = 0; i <= N; ++i)
            Skey[i] = Tkey[i] = pii(-1, -1);
    }
    LL Isroot(LL x) {
        return son[fa[x]][0] != x && son[fa[x]][1] != x;
    }
    void Cut_light(LL x, LL y) {
        if (!x || !y)
            return;

        if (Skey[x] != pii(-1, -1))
            S[y].erase(Skey[x]);

        if (Tkey[x] != pii(-1, -1))
            T[y].erase(Tkey[x]);
    }
    void Link_light(LL x, LL y) {
        if (!x || !y)
            return;

        if (Skey[x] != pii(-1, -1))
            S[y].insert(Skey[x]);

        if (Tkey[x] != pii(-1, -1))
            T[y].insert(Tkey[x]);
    }
    void Update(LL x) {
        if (!x)
            return;

        size[x] = size[son[x][0]] + size[son[x][1]] + 1 + light_sz[x];
        Skey[x] = Tkey[x] = pii(-1, -1);

        if (S[x].size())
            Skey[x] = *S[x].begin();

        if (T[x].size())
            Tkey[x] = *T[x].begin();

        if (Skey[son[x][0]] != pii(-1, -1))
            Skey[x] = Skey[son[x][0]];

        if (Skey[son[x][1]] != pii(-1, -1))
            Skey[x] = Skey[son[x][1]];

        if (Tkey[son[x][0]] != pii(-1, -1))
            Tkey[x] = Tkey[son[x][0]];

        if (Tkey[son[x][1]] != pii(-1, -1))
            Tkey[x] = Tkey[son[x][1]];
    }
    void Rev(LL x) {
        std::swap(son[x][0], son[x][1]);
        rev[x] ^= 1;
    }
    void Pushdown(LL x) {
        if (!rev[x])
            return;

        rev[x] = 0;

        if (son[x][0])
            Rev(son[x][0]);

        if (son[x][1])
            Rev(son[x][1]);
    }
    void Rotate(LL x) {
        LL y(fa[x]), z(fa[y]);
        LL l(son[y][1] == x), r(l ^ 1);

        if (!Isroot(y))
            son[z][son[z][1] == y] = x;
        else
            Cut_light(y, z);

        fa[x] = z;
        son[y][l] = son[x][r];
        fa[son[y][l]] = y;
        son[x][r] = y;
        fa[y] = x;
        Update(y);
        Update(x);

        if (Isroot(x))
            Link_light(x, z);
    }
    void Splay(LL x) {
        static LL sta[maxn];
        LL tot(0);
        LL y(x);

        while (!Isroot(y))
            sta[++tot] = y, y = fa[y];

        sta[++tot] = y;

        while (tot)
            Pushdown(sta[tot--]);

        while (!Isroot(x)) {
            LL y(fa[x]), z(fa[y]);

            if (!Isroot(y))
                Rotate((son[z][1] == y) ^ (son[y][1] == x) ? x : y);

            Rotate(x);
        }
    }
    void Acc(LL x) {
        for (LL t = 0; x; t = x, x = fa[x]) {
            Splay(x);
            Cut_light(t, x);
            Link_light(son[x][1], x);
            light_sz[x] += -size[t] + size[son[x][1]];
            son[x][1] = t;
        }
    }
    void Make_root(LL x) {
        Acc(x);
        Splay(x);
        Rev(x);
    }
    void Link(LL x, LL y) {
        Make_root(x);
        Acc(y);
        Splay(y);
        fa[x] = y;
        size[y] += size[x];
        light_sz[y] += size[x];
        Link_light(x, y);
        Update(y);
    }
    void Cut(LL x, LL y) {
        Make_root(x);
        Acc(y);
        Splay(y);
        son[y][0] = fa[x] = 0;
        size[y] -= size[x];
        Update(y);
    }
    void Insert(LL x, LL y, LL op) {
        Acc(x);
        Splay(x);

        if (op)
            T[x].insert(pii(x, y));
        else
            S[x].insert(pii(x, y));

        Update(x);
    }
    void Erase(LL x, LL y, LL op) {
        Acc(x);
        Splay(x);

        if (op)
            T[x].erase(pii(x, y));
        else
            S[x].erase(pii(x, y));

        Update(x);
    }
    LL Find_root(LL x) {
        Acc(x);
        Splay(x);

        while (son[x][0])
            x = son[x][0];

        Splay(x);
        return x;
    }
    LL Get_size(LL x) {
        Acc(x);
        Splay(x);
        return size[x];
    }
    pii Tree_edge(LL x) {
        Acc(x);
        Splay(x);
        return Tkey[x];
    }
    pii NTree_edge(LL x) {
        Acc(x);
        Splay(x);
        return Skey[x];
    }
} TR[20];
void Link(LL x, LL y) {
    LL fx(TR[0].Find_root(x)), fy(TR[0].Find_root(y));

    if (fx ^ fy) {
        inq[x][y] = inq[y][x] = 1;
        TR[0].Link(x, y);
    }

    dep[x][y] = dep[y][x] = 0;
    TR[0].Insert(x, y, fx ^ fy);
    TR[0].Insert(y, x, fx ^ fy);
    vis[x][y] = vis[y][x] = 1;
}
void Cut(LL x, LL y) {
    LL d(dep[x][y]);
    vis[x][y] = vis[y][x] = 0;

    if (!inq[x][y]) {
        TR[d].Erase(x, y, 0);
        TR[d].Erase(y, x, 0);
    } else {
        inq[x][y] = inq[y][x] = 0;

        for (LL i = 0; i <= d; ++i)
            TR[i].Cut(x, y);

        TR[d].Erase(x, y, 1);
        TR[d].Erase(y, x, 1);

        for (LL i = d; i >= 0; --i) {
            LL flag(0);
            LL s1(TR[i].Get_size(x)), s2(TR[i].Get_size(y));

            if (s1 > s2)
                std::swap(x, y);

            while (true) {
                pii Tmp(TR[i].Tree_edge(x));

                if (Tmp == pii(-1, -1))
                    break;

                LL _x(Tmp.first), _y(Tmp.second);
                TR[i].Erase(_x, _y, 1);
                TR[i].Erase(_y, _x, 1);
                TR[i + 1].Link(_x, _y);
                TR[i + 1].Insert(_x, _y, 1);
                TR[i + 1].Insert(_y, _x, 1);
                dep[_x][_y] = dep[_y][_x] = i + 1;
            }

            while (true) {
                pii Tmp(TR[i].NTree_edge(x));

                if (Tmp == pii(-1, -1))
                    break;

                LL _x(Tmp.first), _y(Tmp.second);
                TR[i].Erase(_x, _y, 0);
                TR[i].Erase(_y, _x, 0);
                LL fx(TR[i].Find_root(_x)), fy(TR[i].Find_root(_y));

                if (fx ^ fy) {
                    for (LL j = 0; j <= i; ++j)
                        TR[j].Link(_x, _y);

                    TR[i].Insert(_x, _y, 1);
                    TR[i].Insert(_y, _x, 1);
                    inq[_x][_y] = inq[_y][_x] = 1;
                    flag = 1;
                    break;
                } else {
                    dep[_x][_y] = dep[_y][_x] = i + 1;
                    TR[i + 1].Insert(_x, _y, 0);
                    TR[i + 1].Insert(_y, _x, 0);
                }
            }

            if (flag)
                break;
        }
    }
}
int main() {
    n = Read();
    m = Read();

    for (LL i = 0; i < 19; ++i)
        TR[i].Init(n);

    LL lstans(0);

    while (m--) {
        LL op(Read()), x(Read()), y(Read());
        x ^= lstans;
        y ^= lstans;

        if (!op)
            Link(x, y);
        else if (op == 1)
            Cut(x, y);
        else {
            LL fx(TR[0].Find_root(x)), fy(TR[0].Find_root(y));

            if (fx ^ fy)
                puts("N"), lstans = y;
            else
                puts("Y"), lstans = x;
        }
    }

    return 0;
}



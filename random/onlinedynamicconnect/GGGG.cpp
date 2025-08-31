#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define ID(u,v) ((LL)u*N+v)

using namespace std;
const int N = 5005, K = 20;
typedef long long LL;
int n, m, ans;

namespace Input_Space {
const int BS = (1 << 24) + 5;
char Buffer[BS], *HD, *TL;
char gc() {
    if (HD == TL)
        TL = (HD = Buffer) + fread(Buffer, 1, BS, stdin);

    return (HD == TL) ? EOF : *HD++;
}
inline int getint() {
    char ch;

    while (!isdigit(ch = gc()));

    int x = ch - 48;

    while (isdigit(ch = gc()))
        x = x * 10 + ch - 48;

    return x;
}
}
using Input_Space::getint;

namespace Holm_de_Lichtenberg_Thorup {
unordered_map <LL, int> id;
struct List {
    int l, x, n;
} ;

struct lct {
    int f[N], l[N], r[N], L[N], R[N];
    int siz[N], sizx[N], t[N][2], h[N][2];
    unordered_set <int> edg[N][2];
    List p[N][2];
    bool cur[N];

    bool isroot(int x) {
        return l[f[x]] != x && r[f[x]] != x;
    }

    int find(int tp, int x) {
        if (!h[x][tp])
            return 0;

        return p[h[x][tp]][tp].x;
    }

    void pushup(int x) {
        siz[x] = siz[l[x]] + siz[r[x]] + 1 + sizx[x];
        L[x] = l[x] ? L[l[x]] : x;
        R[x] = r[x] ? R[r[x]] : x;
        rep(i, 0, 1)
        t[x][i] = max(max(t[l[x]][i], t[r[x]][i]), max(find(i, x), edg[x][i].empty() ? 0 : x));
    }

    void turn(int x) {
        if (!x)
            return;

        cur[x] ^= 1, swap(l[x], r[x]), swap(L[x], R[x]);
    }

    void pushdown(int x) {
        if (cur[x])
            turn(l[x]), turn(r[x]), cur[x] = 0;
    }

    void rotate(int x) {
        int y = f[x], z = f[y];

        if (l[z] == y)
            l[z] = x;

        if (r[z] == y)
            r[z] = x;

        f[x] = z, f[y] = x;

        if (l[y] == x)
            f[l[y] = r[x]] = y, r[x] = y;
        else
            f[r[y] = l[x]] = y, l[x] = y;

        f[0] = 0, pushup(y), pushup(x);
    }

    void dfs(int x) {
        if (!isroot(x))
            dfs(f[x]);

        pushdown(x);
    }

    void splay(int x) {
        for (dfs(x); !isroot(x); rotate(x)) {
            int y = f[x], z = f[y];

            if (!isroot(y))
                rotate((l[z] == y) ^ (l[y] == x) ? x : y);
        }
    }

    void linklist(int tp, int x, int y, int w) {
        if (h[x][tp])
            p[h[x][tp]][tp].n = y;

        p[y][tp] = (List) {h[x][tp], w, 0}, h[x][tp] = y;
    }

    void linkx(int x, int y) {
        if (!x || !y)
            return;

        sizx[x] += siz[y];
        rep(i, 0, 1)

        if (t[y][i])
            linklist(i, x, L[y], t[y][i]);
    }

    void cutlist(int tp, int x, int y) {
        if (h[x][tp] == y)
            h[x][tp] = p[y][tp].l;

        int u = p[y][tp].l, v = p[y][tp].n;

        if (u)
            p[u][tp].n = v;

        if (v)
            p[v][tp].l = u;
    }

    void cutx(int x, int y) {
        if (!x || !y)
            return;

        sizx[x] -= siz[y];
        rep(i, 0, 1)

        if (t[y][i])
            cutlist(i, x, L[y]);
    }

    void access(int x) {
        for (int t = 0; x; t = x, x = f[x])
            splay(x), linkx(x, r[x]), r[x] = t, cutx(x, t), pushup(x);
    }

    void rever(int x) {
        access(x), splay(x), turn(x);
    }

    void link(int x, int y) {
        rever(x), rever(y), f[y] = x, linkx(x, y), pushup(x);
    }

    int get(int x, int tp) {
        return rever(x), t[x][tp];
    }

    void cut(int x, int y) {
        rever(x), access(y), splay(y), l[y] = f[x] = 0, pushup(y);
    }

    bool is_connected(int x, int y) {
        rever(x), access(y), splay(y);
        return L[y] == x;
    }

    void insg(int u, int v) {
        if (edg[u][1].size() == 0)
            access(u), splay(u), edg[u][1].insert(v), pushup(u);
        else
            edg[u][1].insert(v);
    }

    void inst(int u, int v) {
        if (edg[u][0].size() == 0)
            access(u), splay(u), edg[u][0].insert(v), pushup(u);
        else
            edg[u][0].insert(v);
    }

    void delg(int u, int v) {
        if (edg[u][1].size() == 1)
            access(u), splay(u), edg[u][1].erase(v), pushup(u);
        else
            edg[u][1].erase(v);
    }

    void delt(int u, int v) {
        if (edg[u][0].size() == 1)
            access(u), splay(u), edg[u][0].erase(v), pushup(u);
        else
            edg[u][0].erase(v);
    }

    void init() {
        rep(i, 1, n) {
            siz[i] = 1;
            h[i][0] = h[i][1] = sizx[i] = cur[i] = l[i] = r[i] = f[i] = t[i][0] = t[i][1] = 0;
            L[i] = R[i] = i;
            p[i][0] = p[i][1] = (List) {
                0, 0, 0
            };
            edg[i][0].clear(), edg[i][1].clear();
        }
    }
} t[K];

void init() {
    rep(i, 0, K - 1) t[i].init();
}

bool is_connected(int u, int v) {
    return t[0].is_connected(u, v);
}

void insg(int u, int v, int lv) {
    id[ID(u, v)] = id[ID(v, u)] = lv;
    t[lv].insg(u, v);
    t[lv].insg(v, u);
}

void inst(int u, int v, int lv) {
    id[ID(u, v)] = id[ID(v, u)] = lv;
    t[lv].inst(u, v);
    t[lv].inst(v, u);
}

void delg(int u, int v, int lv) {
    t[lv].delg(u, v);
    t[lv].delg(v, u);
}

void delt(int u, int v, int lv) {
    t[lv].delt(u, v);
    t[lv].delt(v, u);
}

bool replace(int u, int v, int lv) {
    t[lv].rever(u), t[lv].rever(v);

    if (t[lv].siz[u] > t[lv].siz[v])
        swap(u, v);

    int ret = 0, tmp = u;

    while (u = t[lv].get(u, 0)) {
        unordered_set <int> &st = t[lv].edg[u][0];

        while (st.size()) {
            v = *st.begin();
            delt(u, v, lv), inst(u, v, lv + 1);
            t[lv + 1].link(u, v);
        }
    }

    u = tmp;

    while (u = t[lv].get(u, 1)) {
        unordered_set <int> &st = t[lv].edg[u][1];

        while (st.size()) {
            v = *st.begin();

            if (t[lv].is_connected(u, v))
                delg(u, v, lv), insg(u, v, lv + 1);
            else {
                delg(u, v, lv), inst(u, v, lv);
                rep(i, 0, lv) t[i].link(u, v);
                return 1;
            }
        }
    }

    return 0;
}

void cut(int u, int v) {
    int lv = id[ID(u, v)];

    if (t[lv].edg[u][1].count(v))
        delg(u, v, lv);
    else {
        rep(i, 0, lv) t[i].cut(u, v);
        delt(u, v, lv);

        repd(i, lv, 0) if (replace(u, v, i))
            break;
    }
}

void link(int u, int v) {
    if (is_connected(u, v))
        insg(u, v, 0);
    else
        inst(u, v, 0), t[0].link(u, v);
}
}

using Holm_de_Lichtenberg_Thorup::is_connected;
using Holm_de_Lichtenberg_Thorup::link;
using Holm_de_Lichtenberg_Thorup::cut;
using Holm_de_Lichtenberg_Thorup::init;

int main() {
    n = getint(), m = getint(), init();

    while (m--) {
        int tp = getint(), u = getint()^ans, v = getint()^ans;

        if (tp == 0)
            link(u, v);

        if (tp == 1)
            cut(u, v);

        if (tp == 2)
            is_connected(u, v) ? (puts("Y"), ans = u) : (puts("N"), ans = v);
    }

    return 0;
}

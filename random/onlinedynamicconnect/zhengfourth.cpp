#include <cstdio>
#define N 65001
#define M 1000000
// https://loj.ac/s/805850
int n, m, sz[N], csz[N];
int l[N], r[N], fa[N];
bool rz[N];
int to[M], le[M], cnt = 0;
template <int SIZE> struct linkedlist {
    int pr[SIZE], ne[SIZE];
    int remove(int x) {
        if (pr[x] == x)
            return -1;

        ne[pr[x]] = ne[x];
        pr[ne[x]] = pr[x];
        return pr[x];
    }
    void insert(int &x, int v) {
        if (x == -1) {
            pr[v] = ne[v] = v;
            x = v;
            return;
        }

        ne[v] = ne[x];
        pr[ne[x]] = v;
        ne[x] = v;
        pr[v] = x;
        x = v;
    }
};
linkedlist<M> ed;
linkedlist<N> c1, c2;
bool h1[N];
int ed1[N], ch1[N];
bool h2[N];
int ed2[N], ch2[N];
#define notroot(x) (x==l[fa[x]]||x==r[fa[x]])
void pushdown(int x) {
    if (rz[x]) {
        l[x] ^= r[x] ^= l[x] ^= r[x];
        rz[l[x]] ^= 1;
        rz[r[x]] ^= 1;
        rz[x] = 0;
    }
}
void pushall(int x) {
    if (notroot(x))
        pushall(fa[x]);

    pushdown(x);
}
void pushup(int x) {
    sz[x] = sz[l[x]] + sz[r[x]] + csz[x] + 1;
    h1[x] = h1[l[x]] || h1[r[x]] || (ch1[x] != -1) || (ed1[x] != -1);
    h2[x] = h2[l[x]] || h2[r[x]] || (ch2[x] != -1) || (ed2[x] != -1);
}
void rotateL(int t) {
    int nt = l[r[t]];
    l[r[t]] = t;

    if (t == l[fa[t]])
        l[fa[t]] = r[t];

    if (t == r[fa[t]])
        r[fa[t]] = r[t];

    fa[r[t]] = fa[t];
    fa[t] = r[t];
    r[t] = nt;

    if (nt)
        fa[nt] = t;
}
void rotateR(int t) {
    int nt = r[l[t]];
    r[l[t]] = t;

    if (t == r[fa[t]])
        r[fa[t]] = l[t];

    if (t == l[fa[t]])
        l[fa[t]] = l[t];

    fa[l[t]] = fa[t];
    fa[t] = l[t];
    l[t] = nt;

    if (nt)
        fa[nt] = t;
}
int splay(int x) {
    pushall(x);
    int last = x;

    while (notroot(x)) {
        int p = fa[x], g = fa[p];
        last = g;

        if (l[g] == p) {
            if (l[p] == x) {
                rotateR(g);
                rotateR(p);
            } else {
                rotateL(p);
                rotateR(g);
            }

            pushup(g);
        } else if (r[g] == p) {
            if (r[p] == x) {
                rotateL(g);
                rotateL(p);
            } else {
                rotateR(p);
                rotateL(g);
            }

            pushup(g);
        } else {
            last = p;

            if (l[p] == x)
                rotateR(p);
            else
                rotateL(p);
        }

        pushup(p);
    }

    pushup(x);
    return last;
}
void access(int x) {
    int y = 0;

    while (x) {
        int rd = splay(x);

        if (rd != x && fa[x]) {
            if (h1[x]) {
                ch1[fa[x]] = c1.remove(rd);
                c1.insert(ch1[fa[x]], x);
            }

            if (h2[x]) {
                ch2[fa[x]] = c2.remove(rd);
                c2.insert(ch2[fa[x]], x);
            }
        }

        if (h1[y])
            ch1[x] = c1.remove(y);

        if (h2[y])
            ch2[x] = c2.remove(y);

        if (h1[r[x]])
            c1.insert(ch1[x], r[x]);

        if (h2[r[x]])
            c2.insert(ch2[x], r[x]);

        csz[x] += sz[r[x]] - sz[y];
        r[x] = y;
        y = x;
        x = fa[x];
    }
}
void setroot(int x) {
    access(x);
    splay(x);
    rz[x] ^= 1;
}
int getroot(int x) {
    access(x);
    splay(x);

    while (l[x]) {
        x = l[x];
        pushdown(x);
    }

    splay(x);
    return x;
}
void link(int e) {
    int x = to[e] + n * le[e], y = to[e ^ 1] + n * le[e];
    setroot(x);

    if (getroot(y) == x) {
        ed.insert(ed2[x], e ^ 1);
        h2[x] = true;
        setroot(y);
        ed.insert(ed2[y], e);
        h2[y] = true;
    } else {
        setroot(y);
        ed.insert(ed1[x], e ^ 1);
        ed.insert(ed1[y], e);
        h1[x] = h1[y] = true;
        fa[x] = y;
        csz[y] += sz[x];
        c1.insert(ch1[y], x);

        if (h2[x])
            c2.insert(ch2[y], x);

        pushup(y);
    }
}
void del(int e) {
    int x = to[e] + n * le[e], y = to[e ^ 1] + n * le[e];
    int rx = to[e], ry = to[e ^ 1];
    setroot(x);
    getroot(y);

    if (fa[y] == x && !l[y]) {
        fa[y] = r[x] = 0;
        ed1[x] = ed.remove(e ^ 1);
        pushup(x);
        setroot(y);
        ed1[y] = ed.remove(e);
        pushup(y);

        for (int k = le[e] - 1; k >= 0; k--) {
            x = rx + k * n;
            y = ry + k * n;
            setroot(x);
            getroot(y);
            fa[y] = r[x] = 0;
            pushup(x);
        }

        for (int k = le[e]; k >= 0; k--) {
            x = rx + k * n;
            y = ry + k * n;
            setroot(x);
            setroot(y);

            if (sz[x] > sz[y])
                x ^= y ^= x ^= y;

            while (h1[x]) {
                while (ed1[x] == -1) {
                    if (h1[l[x]])
                        x = l[x];
                    else if (h1[r[x]])
                        x = r[x];
                    else
                        x = ch1[x];
                }

                setroot(x);

                while (ed1[x] != -1) {
                    int es = ed1[x];
                    int v = to[es] + k * n;
                    ed1[x] = ed.remove(es);
                    pushup(x);
                    setroot(v);
                    ed1[v] = ed.remove(es ^ 1);
                    pushup(v);
                    setroot(x);
                    le[es]++;
                    le[es ^ 1]++;
                    link(es);
                }

                pushup(x);
            }

            int found = -1;

            while (found == -1 && h2[x]) {
                while (ed2[x] == -1) {
                    if (h2[l[x]])
                        x = l[x];
                    else if (h2[r[x]])
                        x = r[x];
                    else
                        x = ch2[x];
                }

                setroot(x);

                while (ed2[x] != -1) {
                    int es = ed2[x];
                    int v = to[es] + k * n;

                    if (getroot(v) != x) {
                        ed2[x] = ed.remove(es);
                        setroot(v);
                        ed2[v] = ed.remove(es ^ 1);
                        pushup(v);
                        found = es;
                        break;
                    } else {
                        ed2[x] = ed.remove(es);
                        pushup(x);
                        setroot(x + n);
                        ed.insert(ed2[x + n], es);
                        pushup(x + n);
                        setroot(v);
                        ed2[v] = ed.remove(es ^ 1);
                        pushup(v);
                        setroot(v + n);
                        ed.insert(ed2[v + n], es ^ 1);
                        pushup(v + n);
                        setroot(x);
                        le[es]++;
                        le[es ^ 1]++;
                    }
                }

                pushup(x);
            }

            if (found != -1) {
                link(found);

                for (int p = k - 1; p >= 0; p--) {
                    x = to[found] + p * n;
                    y = to[found ^ 1] + p * n;
                    setroot(x);
                    setroot(y);
                    fa[x] = y;
                    csz[y] += sz[x];

                    if (h1[x])
                        c1.insert(ch1[y], x);

                    if (h2[x])
                        c2.insert(ch2[y], x);
                }

                return;
            }
        }
    } else {
        ed2[x] = ed.remove(e ^ 1);
        pushup(x);
        setroot(y);
        ed2[y] = ed.remove(e);
        pushup(y);
    }
}
int eid[5001][5001];
void add(int x, int y) {
    eid[x][y] = cnt;
    to[cnt++] = y;
    eid[y][x] = cnt;
    to[cnt++] = x;
    link(cnt - 2);
}
void dele(int x, int y) {
    del(eid[x][y]);
}
bool query(int x, int y) {
    setroot(x);
    return (getroot(y) == x);
}
int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i < N; i++) {
        ch1[i] = ch2[i] = ed1[i] = ed2[i] = -1;
        sz[i] = 1;
    }

    int last = 0;

    while (m--) {
        int o, x, y;
        scanf("%d%d%d", &o, &x, &y);
        x ^= last;
        y ^= last;

        if (o == 0) {
            add(x, y);
        } else if (o == 1) {
            dele(x, y);
        } else {
            if (query(x, y)) {
                puts("Y");
                last = x;
            } else {
                puts("N");
                last = y;
            }
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
int p1 = 1000000, p2 = 0;
char buf[1000005], wb[1000005];
int gc() {
    if (p1 >= 1000000)
        fread(buf, 1, 1000000, stdin), p1 = 0;

    return buf[p1++];
}
#define gc getchar
#define Loli true
#define Kon xor true
long long getint() {
    long long ret = 0, flag = 1;
    char c = gc();

    while (c < '0' || c > '9') {
        if (c == '-')
            flag = -1;

        c = gc();
    }

    while (c <= '9' && c >= '0') {
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = gc();
    }

    return ret * flag;
}
void pc(char x) {
    if (p2 >= 1000000)
        fwrite(wb, 1, 1000000, stdout), p2 = 0;

    wb[p2++] = x;
}
void wrt(long long x) {
    if (x < 0)
        pc('-'), x = -x;

    int c[24] = {0};

    if (!x)
        return pc('0'), void();

    while (x)
        c[++c[0]] = x % 10, x /= 10;

    while (c[0])
        pc(c[c[0]--] + '0');
}
int n, m, ans;
struct LCT {
    map<int, int> e[5005];
    struct node {
        int ch[2], fa, rev, tag, stag, pre, suf, sz, csz;
        multiset<int> s;
        node() {
            s.clear(), ch[0] = ch[1] = fa = rev = sz = pre = suf = 0, tag = stag = 1e9;
        }
    } v[5005];
    LCT() {
        for (int i = 1; i <= 5000; i++)
            e[i].clear(), v[i] = node(), push_up(i);
    }
    bool isroot(int x) {
        return v[v[x].fa].ch[0] != x && v[v[x].fa].ch[1] != x;
    }
    void push_up(int rt) {
        v[rt].sz = v[v[rt].ch[0]].sz + v[v[rt].ch[1]].sz + v[rt].csz + 1;
        v[rt].pre = v[rt].ch[0] ? v[v[rt].ch[0]].pre : rt;
        v[rt].suf = v[rt].ch[1] ? v[v[rt].ch[1]].suf : rt;

        v[rt].stag = v[rt].tag;

        if (v[rt].s.size())
            v[rt].stag = min(v[rt].stag, *v[rt].s.begin());

        if (v[v[rt].ch[0]].stag)
            v[rt].stag = min(v[rt].stag, v[v[rt].ch[0]].stag);

        if (v[v[rt].ch[1]].stag)
            v[rt].stag = min(v[rt].stag, v[v[rt].ch[1]].stag);
    }
    void push_rev(int x) {
        if (!x)
            return;

        v[x].rev ^= 1, swap(v[x].ch[0], v[x].ch[1]), swap(v[x].pre, v[x].suf);
    }
    void push_down(int x) {
        if (v[x].rev) {
            push_rev(v[x].ch[0]);
            push_rev(v[x].ch[1]);
            v[x].rev = 0;
        }
    }
    void rot(int x) {
        int p = v[x].fa, g = v[p].fa;
        bool d = v[p].ch[1] == x;

        if (!isroot(p))
            v[g].ch[v[g].ch[1] == p] = x;

        v[p].ch[d] = v[x].ch[d ^ 1];
        v[v[x].ch[d ^ 1]].fa = p;
        v[x].ch[d ^ 1] = p;
        v[p].fa = x, v[x].fa = g;
        push_up(p), push_up(x);
    }
    void pre_push_down(int rt) {
        if (!isroot(rt))
            pre_push_down(v[rt].fa);

        push_down(rt);
    }
    void splay(int x) {
        pre_push_down(x);

        while (!isroot(x)) {
            int p = v[x].fa, g = v[p].fa;

            if (!isroot(p))
                rot(((v[g].ch[0] == p) ^ (v[p].ch[0] == x)) ? x : p);

            rot(x);
        }
    }
    void ins(int x, int y) {
        v[x].csz += v[y].sz;

        if (!y)
            return;

        v[x].s.insert(v[y].stag);
    }
    void del(int x, int y) {
        v[x].csz -= v[y].sz;

        if (!y)
            return;

        if (v[x].s.find(v[y].stag) == v[x].s.end())
            exit(233);

        v[x].s.erase(v[x].s.find(v[y].stag));
    }
    void access(int x) {
        for (int y = 0; x; y = x, x = v[x].fa)
            splay(x), del(x, y), ins(x, v[x].ch[1]), v[x].ch[1] = y, push_up(x);
    }
    void makeroot(int x) {
        access(x), splay(x), push_rev(x);
    }
    void link(int x, int y) {
        access(x), splay(x), makeroot(y), v[y].fa = x, v[x].ch[1] = y, push_up(x);
        e[x][y] = e[y][x] = 1;
    }
    void cut(int x, int y) {
        makeroot(x), access(y), splay(y), v[v[y].ch[0]].fa = 0, v[y].ch[0] = 0, push_up(y);
        e[x].erase(y), e[y].erase(x);
    }
    bool check(int x, int y) {
        if (x == y)
            return 1;

        return makeroot(x), access(y), splay(y), v[x].fa;
    }
    void settag(int x) {
        access(x), splay(x), v[x].tag = x, push_up(x);
    }
    void deltag(int x) {
        access(x), splay(x), v[x].tag = 1e9, push_up(x);
    }
} T[17];
map<int, int> g_level[10005];
set<int> G[17][10005];
bool link(int x, int y) {
    g_level[x][y] = 0, g_level[y][x] = 0;
    G[0][x].insert(y), G[0][y].insert(x);

    if (!T[0].check(x, y))
        return T[0].link(x, y), T[0].settag(x), T[0].settag(y), 1;

    return T[0].settag(x), T[0].settag(y), 0;
}
void level_up(int x, int y, int level) {
    if (G[level][x].empty())
        T[level].deltag(x);

    if (G[level][y].empty())
        T[level].deltag(y);

    ++g_level[x][y], ++g_level[y][x];
    G[level + 1][x].insert(y), G[level + 1][y].insert(x);

    if (!T[level + 1].check(x, y))
        T[level + 1].link(x, y);

    T[level + 1].settag(x), T[level + 1].settag(y);
}
void solve1(int x, int i) {
    auto it = G[i][x].begin();

    while (it != G[i][x].end()) {
        if (T[i].e[x].count(*it)) {
            int y = *it;
            G[i][y].erase(G[i][y].find(x));
            it = G[i][x].erase(it), level_up(x, y, i);
        } else ++it;
    }
}
int r1, r2;
vector<int> vec;
bool solve2(int x, int i, int y) {
    auto it = G[i][x].begin();

    while (it != G[i][x].end()) {
        if (T[i].check(*it, y)) {
            for (int k = 0; k <= i; k++)
                T[k].link(x, *it);

            return r1 = x, r2 = *it, 1;
        } else {
            int y = *it;
            G[i][y].erase(G[i][y].find(x));
            it = G[i][x].erase(it), level_up(x, y, i);
        }
    }

    return 0;
}
void cut(int x, int y) {
    int level = g_level[x][y];
    g_level[x].erase(g_level[x].find(y));
    g_level[y].erase(g_level[y].find(x));
    G[level][x].erase(G[level][x].find(y));
    G[level][y].erase(G[level][y].find(x));

    if (T[0].e[x].count(y)) {
        for (int i = 0; i <= level; i++)
            T[i].cut(x, y);

        for (int i = level; i >= 0; i--) {
            T[i].makeroot(x), T[i].makeroot(y);
            int sx = T[i].v[x].sz, sy = T[i].v[y].sz;

            if (sy < sx)
                swap(x, y), swap(sx, sy);

            vec.clear();

            while (T[i].makeroot(x), T[i].v[x].stag != 1e9)
                vec.push_back(T[i].v[x].stag), T[i].deltag(T[i].v[x].stag);

            for (int t : vec) {
                solve1(t, i);

                if (G[i][t].size())
                    T[i].settag(t);
            }

            while (T[i].makeroot(x), T[i].v[x].stag != 1e9)
                if (solve2(T[i].v[x].stag, i, y))
                    return;
        }

        r1 = r2 = 0;
        return;
    }

    r1 = -1, r2 = 0;
    return;
}
bool ask(int x, int y) {
    if (x == y)
        return 1;

    return T[0].check(x, y);
}
int main() {
    n = getint(), m = getint();

    for (int i = 1; i <= m; i++) {
        int opt = getint(), x = getint()^ans, y = getint()^ans;

        if (opt == 0)
            link(x, y);

        if (opt == 1)
            cut(x, y);

        if (opt == 2)
            ask(x, y) ? (ans = x, puts("Y")) : (ans = y, puts("N"));
    }

    fwrite(wb, 1, p2, stdout);
    return Loli Kon;
}

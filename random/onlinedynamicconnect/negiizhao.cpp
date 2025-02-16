#include <bits/stdc++.h>

typedef unsigned int uint;

const int Max_V = 5005, Max_E = 500005;

const bool nontree = false, tree = true;

struct Euler_Tour_Tree {
    struct Splay_Tree {
        Splay_Tree *ch[2], *parent;
        int cnt, size;
        bool active[2], agg[2];

        Splay_Tree() : size(1) {
            ch[0] = ch[1] = parent = Null;
            active[0] = active[1] = agg[0] = agg[1] = false;
        }

        void pushup() {
            size = ch[0]->size + ch[1]->size + 1;
            agg[0] = active[0] || ch[0]->agg[0] || ch[1]->agg[0];
            agg[1] = active[1] || ch[0]->agg[1] || ch[1]->agg[1];
        }

        bool dir() const {
            return parent->ch[1] == this;
        }

        Splay_Tree *sch(const int d, Splay_Tree *c) {
            return ch[d] = c, c->parent = this;
        }

        Splay_Tree *rotate() {
            Splay_Tree *p = parent;
            bool d = dir();

            if (parent = p->parent, p->parent != Null)
                p->parent->ch[p->dir()] = this;

            p->sch(d, ch[!d])->pushup(), sch(!d, p)->pushup();
            return this;
        }

        Splay_Tree *splay(Splay_Tree *o = Null) {
            for (; parent != o; rotate())
                if (parent->parent != o)
                    (parent->dir() == dir() ? parent : this)->rotate();

            return this;
        }

        template<bool d>
        Splay_Tree *splay_m() {
            Splay_Tree *o = this;

            for (; o->ch[d] != Null;)
                o = o->ch[d];

            return o->splay(parent);
        }

        template<bool type>
        Splay_Tree *splay_a() {
            Splay_Tree *o = this;

            for (; o->ch[0]->agg[type] || !o->active[type];)
                o = o->ch[!o->ch[0]->agg[type]];

            return o->splay();
        }
    };

    static Splay_Tree *Null;

    Splay_Tree *node0, *enode0;

    Euler_Tour_Tree(const int N, const int M) : node0(new Splay_Tree[N + 1]), enode0(new Splay_Tree[M * 2 + 2]) {
        static bool init((Null->size = 0, Null->ch[0] = Null->ch[1] = Null->parent = Null, true));
    }

    void reroot(Splay_Tree *o) {
        if (o->splay()->ch[0] != Null)
            o->ch[0]->splay_m<0>()->sch(0, o->ch[1])->pushup(), o->sch(1, o->ch[0])->pushup(), o->ch[0] = Null;
    }

    void link(Splay_Tree *o1, Splay_Tree *o2, Splay_Tree *e1, Splay_Tree *e2) {
        reroot(o1), reroot(o2), e1->sch(0, o1)->sch(1, o2)->pushup(), e2->sch(0, e1)->pushup();
    }

    void cut(Splay_Tree *e1, Splay_Tree *e2) {
        reroot(e1), e1->ch[1] = e1->ch[1]->parent = Null, e2->splay(),
                                           e2->ch[0] = e2->ch[1] = e2->ch[0]->parent = e2->ch[1]->parent = Null;
    }

    bool is_connected(Splay_Tree *o1, Splay_Tree *o2) {
        return o1 == o2 || (o1->splay(), o2->splay(), o1->parent != Null);
    }

    int component_size(Splay_Tree *o) {
        return o->splay()->size;
    }

    template<bool type>
    void set(Splay_Tree *o, bool active) {
        o->splay()->active[type] = active, o->pushup();
    }

    Splay_Tree *node(const int x) {
        return node0 + x;
    }

    Splay_Tree *enode(const int x) {
        return enode0 + x;
    }

    void link(const int v, const int w, const int eid) {
        link(node(v), node(w), enode(eid), enode(eid ^ 1));
    }

    void cut(const int eid) {
        cut(enode(eid), enode(eid ^ 1));
    }

    bool is_connected(const int v, const int w) {
        return is_connected(node(v), node(w));
    }

    int component_size(const int v) {
        return component_size(node(v));
    }

    void set_tree(const int eid, const bool active) {
        set<tree>(enode(eid), active);
    }

    void set_nontree(const int v, const bool active) {
        set<nontree>(node(v), active);
    }
};
Euler_Tour_Tree::Splay_Tree *Euler_Tour_Tree::Null = new Euler_Tour_Tree::Splay_Tree;

struct Fully_Dynamic_Connectivity {
    int V;
    std::vector<Euler_Tour_Tree> forest;
    int ecnt, eid[Max_V][Max_V], elevel[Max_E * 2];

    static const int Max_L = 12;

    int prev[Max_E * 2 + 2 * Max_L * Max_V], next[Max_E * 2 + 2 * Max_L * Max_V],
        to[Max_E * 2 + 2 * Max_L * Max_V];

    int ebegin(const int level, const int v) const {
        return Max_E * 2 + level * Max_V + v;
    }

    int eend(const int level, const int v) const {
        return Max_E * 2 + (Max_L + level) * Max_V + v;
    }

    void link(const int cur1, const int cur2) {
        next[cur1] = cur2, prev[cur2] = cur1;
    }

    void eset(const int v, const int w, const int level) {
        int cur = ebegin(level, v);
        link(eid[v][w], next[cur]), link(cur, eid[v][w]);
        cur = ebegin(level, w);
        link(eid[w][v], next[cur]), link(cur, eid[w][v]);

        if (prev[eid[v][w]] >= Max_E * 2 && next[eid[v][w]] >= Max_E * 2)
            forest[level].set_nontree(v, true);

        if (prev[eid[w][v]] >= Max_E * 2 && next[eid[w][v]] >= Max_E * 2)
            forest[level].set_nontree(w, true);
    }

    void ereset(const int v, const int w, const int level) {
        link(prev[eid[v][w]], next[eid[v][w]]);
        link(prev[eid[w][v]], next[eid[w][v]]);

        if (prev[eid[v][w]] >= Max_E * 2 && next[eid[v][w]] >= Max_E * 2)
            forest[level].set_nontree(v, false);

        if (prev[eid[w][v]] >= Max_E * 2 && next[eid[w][v]] >= Max_E * 2)
            forest[level].set_nontree(w, false);
    }

    Fully_Dynamic_Connectivity(const int N, const int M) : V(N), ecnt(2) {
        for (int l = 0; l != Max_L; ++l)
            forest.push_back(Euler_Tour_Tree(N, M));

        for (int i = 0; i != Max_L * Max_V; ++i)
            link(Max_E * 2 + i, Max_E * 2 + Max_L * Max_V + i);
    }

    void insert(const int v, const int w) {
        eid[v][w] = ecnt++, eid[w][v] = ecnt++;
        elevel[eid[v][w]] = elevel[eid[w][v]] = 0;
        to[eid[v][w]] = w, to[eid[w][v]] = v;

        if (!forest[0].is_connected(v, w))
            forest[0].link(v, w, eid[v][w]), forest[0].set_tree(eid[v][w], true), forest[0].set_tree(eid[w][v], true);
        else
            eset(v, w, 0);
    }

    void erase(int v, int w) {
        bool type = forest[0].is_connected(forest[0].node(v), forest[0].enode(eid[v][w])) ? tree : nontree;
        int level = elevel[eid[v][w]];

        if (type == nontree)
            ereset(v, w, level);
        else {
            for (int l = 0; l <= level; ++l)
                forest[l].cut(eid[v][w]);

            int x = -1, y = -1;

            do {
                Euler_Tour_Tree &F = forest[level];

                if (F.component_size(v) > F.component_size(w))
                    std::swap(v, w);

                Euler_Tour_Tree::Splay_Tree *o = F.node(v);

                while (o->splay()->agg[tree])
                    if (o = o->splay_a<tree>(), o->active[tree] = false, o->pushup(), (o - F.enode0) & 1)
                        push_tree_edge(o - F.enode0);

                while (o->splay()->agg[nontree])
                    if (o = o->splay_a<nontree>(), (y = find_replacement_edge(level, x = o - F.node0, w)) != -1)
                        break;

                if (y != -1) {
                    for (int l = 0; l <= level; ++l)
                        forest[l].link(x, y, eid[x][y]);

                    forest[level].set_tree(eid[x][y], true), forest[level].set_tree(eid[y][x], true);
                    return;
                }
            } while (level--);
        }
    }

    void push_tree_edge(const int _id) {
        int v = to[_id ^ 1], w = to[_id];
        ++elevel[_id], ++elevel[_id ^ 1];
        forest[elevel[_id]].link(v, w, _id), forest[elevel[_id]].set_tree(_id, true),
               forest[elevel[_id]].set_tree(_id ^ 1, true);
    }

    int find_replacement_edge(const int level, const int v, const int t) {
        for (int _id = next[ebegin(level, v)]; _id != eend(level, v); _id = next[ebegin(level, v)]) {
            int w = to[_id];
            ereset(v, w, level);

            if (forest[level].is_connected(w, t))
                return w;
            else
                eset(v, w, level + 1), ++elevel[_id], ++elevel[_id ^ 1];
        }

        return -1;
    }

    bool is_connected(int v, int w) {
        return forest[0].is_connected(v, w);
    }
};

int N, M, lastans;

int main(int argc, char **argv) {
    std::cin >> N >> M;
    Fully_Dynamic_Connectivity FDC(N + 1, M);
    char c;
    while (M--)
        std::cin >> c;
        switch (c) {
            int v, w;

        case 0:
            std::cin >> v >> w;
            v ^= lastans, w ^= lastans;
            FDC.insert(v, w);
            break;

        case 1:
            std::cin >> v >> w;
            v ^= lastans, w ^= lastans;
            FDC.erase(v, w);
            break;

        case 2:
            std::cin >> v >> w;
            v ^= lastans, w ^= lastans;

            if (FDC.is_connected(v, w))
                std::cout << 'Y' << '\n', lastans = v;
            else
                std::cout << 'N' << '\n', lastans = w;

            break;
        }

    return 0;
}

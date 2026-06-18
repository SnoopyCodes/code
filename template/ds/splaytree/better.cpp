#include <bits/stdc++.h>

using namespace std;

struct node {
    int val, size = 1;
    array<node*, 2> c{};
    node *p = nullptr;
    bool flip = false;
 
    node(int v): val(v) {}

    void push() {
        if (!flip) { return; }
        flip = false;
        swap(c[0], c[1]);
        for (auto &x : c) if (x) { x->flip ^= 1; }
    }
    //-1 if root, 0 or 1 for child. the () condition is unneeded if not lct
    inline int dir() { return !p || (p->c[0] != this && p->c[1] != this) ? -1 : p->c[1] == this; }
    void rel(node *v, int d) { //set the relationship b/w the two
        if (~d) { c[d] = v; }
        if (v) { v->p = this; }
        size = (c[0] ? c[0]->size : 0) + 1 + (c[1] ? c[1]->size : 0);
    }
    void rot() { //needs p
        int d = dir();
        node *o = p;
        o->p->rel(this, o->dir());
        o->rel(c[d ^ 1], d);
        rel(o, d ^ 1);
    }
    void par_push() { if (~dir()) p->par_push(); push(); }
    void splay() { //cursed rot() location
        for (par_push(); ~dir(); rot()) {
            if (~p->dir()) { (dir() == p->dir() ? p : this)->rot(); }
        }
    }
    node* find(int k) {  //find the kth node, 0-indexed:
        int l_sz = c[0] ? c[0]->size : 0;
        if (l_sz == k) { splay(); return this; }
        if (l_sz > k) { return c[0]->find(k); }  //move left
        return c[1]->find(k - l_sz - 1);
    }
};
array<node*, 2> split(node *root, int piv) { //split into [0, piv) and [piv, size)
    root->find(piv);
    node *l = root->c[0];
    root->c[0] = l->p = nullptr;
    root->size = 1 + (root->c[1] ? root->c[1]->size : 0);
    return { l, root };
}
node *join(node *l, node *r) {
    if (!l || !r) { return l ? l : r; }
    l->find(l->size - 1);
    l->rel(r, 1);
    return l;
}



/*
maintain sizes, so we can find() an element
do array<node*, 2> split(node* n) and node *merge(node *l, node *r)
let's be fr what do we want to be able to do
we can oset already probably
*/
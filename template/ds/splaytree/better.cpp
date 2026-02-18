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
    friend void rel(node *u, node *v, int d) { //set the relationship b/w the two
        if (~d) { u->c[d] = v; } //this if guard isnt needed if not lct
        if (v) { v->p = u; }
        u->size = (u->c[0] ? u->c[0]->size : 0) + 1 + (u->c[1] ? u->c[1]->size : 0);
    }
    void rot() { //needs p
        int d = dir();
        node *o = p;
        rel(o->p, this, o->dir());
        rel(o, c[d ^ 1], d);
        rel(this, o, d ^ 1);
    }
    void par_push() { if (~dir()) p->par_push(); push(); } //yes, i like this
    void splay() { //cursed rot() location
        for (par_push(); ~dir(); rot()) { //this is like, bad because it's just not understandable in any way.
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
    rel(l, r, 1);
    return l;
}



/*
maintain sizes, so we can find() an element
do array<node*, 2> split(node* n) and node *merge(node *l, node *r)
let's be fr what do we want to be able to do
we can oset already probably

then to extend to treap operations we are basically almost there.. 
do i want to do this?
basically just insert at position, delete at position?
and with split we give it a value to split at so like x
this isn't too bad, a good like 20 lines of code or so.
*/
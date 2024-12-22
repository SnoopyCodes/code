#include <bits/stdc++.h>

using namespace std;
//https://usaco.guide/adv/link-cut-tree?lang=cpp
//mit pdf lmao
//zeocool impl orz!
//this doesn't actually implement bst ops, mainly to be used with lct
struct node {
    array<node*, 2> c{};
    node* p;
    int key = 0;
    node(int k) { key = k; }
    
    bool side() { return this == p->c[1]; }
    void attach(node* n, bool x) {
        c[x] = n;
        if (n) { n->p = this; }
    }
    void rot() {
        bool x = side();
        node* o = p;  //original parent
        if (o->p) { o->p->attach(this, o->side()); }
        else { p = nullptr; }
        o->attach(c[!x], x);
        attach(o, !x);
    }
    void splay() {
        while (p) {
            if (side() == p->side()) { p->rot(); }
            else { rot(); }
            rot();
        }
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    node *a = new node(1), *b = new node(2), *c = new node(3), *d = new node(4), *e = new node(5);
    d->attach(a, 1);
    a->attach(b, 0);
    a->attach(c, 1);
    b->attach(e, 1);
    b->rot();
    cout << "\n";
    if (b->c[0]) {
        cout << b ->c[0] -> key << "\n";
        cout << "left acquired" << endl;
    }
    if (b->c[1]) {
        cout << b->c[1]->key << endl;
        cout << b->c[1]->c[0]->key << endl;
        cout << b->c[1]->c[1]->key << endl;
    }
    if (b->p) {
        cout << b->p->key << "\n";
    }
}
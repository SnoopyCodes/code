#include <bits/stdc++.h>

using namespace std;

//support link, cut, path aggregate, add subtree sum later

struct node {
    array<node*, 2> c{};
    node *p, *aux;  //auxiliary connection
    int key = 0;
    bool rev = false;  //reroot
    node(int k) { key = k; }
    
    void push() {
        if (rev) {
            rev = false;
            swap(c[0], c[1]);
            c[0]->rev = true;
            c[1]->rev = true;
        }
    }

    bool side() { return this == p->c[1]; }

    //attach node n to this
    void attach(node* n, bool x) {
        c[x] = n;
        if (n) { n->p = this; }
    }
    
    void detach() {  //from parent
        p->c[side()] = nullptr;
        p = nullptr;
    }

    //move to parent's placement
    void rot() {
        bool x = side();
        node* o = p;  //original parent
        //if par is root, move aux to this node
        aux = o->aux;
        o->aux = nullptr;
        //o's parent is ours
        if (o->p) { o->p->attach(this, o->side()); }
        else { p = nullptr; }
        //move o and child being kicked
        o->attach(c[!x], x);
        attach(o, !x);
    }
    void splay() {
        //while not at root, splay step
        while (p) {
            if (side() == p->side()) { p->rot(); }
            else { rot(); }
            rot();
        }
    }

    void access() {
        //become root
        splay();
        //kick left child (pref path down to this)
        if (c[1]) {
            c[1]->detach();
            c[1]->aux = this;
        }
        //while not at root of aux tree, make this the root of splay, and also set pref path from root to this
        //(root to us is splay tree)
        while (!aux) {
            aux->splay();
            if (aux->c[1]) {
                aux->c[1]->detach();
                aux->c[1]->aux = aux;
            }
            aux->c[1] = this;
            aux = nullptr;
            splay();
        }
    }
    //make this REAL ROOT of tree
    void reroot() {
        access();
        if (c[0]) {
            c[0]->rev ^= true;
            //?? what does any of this do
        }
    }
    node* find() {
        node* tmp = this;
        while (tmp->c[0] != nullptr) { tmp = c[0]; }
        tmp->splay();
        return tmp;
    }
    void cut(node* v) {  //from parent
        access();
        if (v != c[0]) { v->cut(this); return; }
        v->detach();
    }
    void link(node* v) {
        reroot();
        access();
        v->access();
        //bruh this version doesn't work bc it can't do rerooting smh
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}
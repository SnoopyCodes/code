#include <bits/stdc++.h>

using namespace std;

//support link, cut, path aggregate, add subtree sum later

struct node {
    array<node*, 2> c{};
    node *p, *aux;
    int key = 0;
    node(int k) { key = k; }
    
    bool side() { return this == p->c[1]; }
    void attach(node* n, bool x) {
        c[x] = n;
        if (n) { n->p = this; }
    }
    void detach() {  //from parent
        p->c[side()] = nullptr;
        p = nullptr;
    }
    void rot() {
        bool x = side();
        node* o = p;  //original parent
        aux = o->aux;
        o->aux = nullptr;
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

    void access() {
        splay();
        if (c[1]) {
            c[1]->detach();
            c[1]->aux = this;
        }
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
    node* find() {
        node* tmp = this;
        while (tmp->c[0] != nullptr) { tmp= c[0]; }
        //there was a debate about this, actually-- splay or access() ?
        //acces() limits use of splay() to just access (and thus clearly defines lct vs splay)
        //but splay() makes it so that the definition of "access" is cleaner- accessing
        //means smth that is passed to a function like link, cut, etc.
        tmp->splay();
        return tmp;  //pointer or not?
    }
    void cut(node* v) {  //from parent
        access();
        if (v != c[0]) { v->cut(this); return; }
        v->detach();
    }
    void link(node* v) {
        access();
        v->access();
        //bruh this version doesn't work bc it can't do rerooting smh
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}
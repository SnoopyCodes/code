#include <bits/stdc++.h>

using namespace std;

/*
peak data structure
a few notes
the mit lecture doesn't cover rerooting, which is pretty necessary
the *aux pointer can be reused into just the parent pointer
which is what the standard thing is doing
this is probably faster but more confusing if you don't know it
0.23 seconds
*might* try removing the *aux pointer in the future
*/

//splay tree node
struct node {
    array<node*, 2> c{};
    node* p = nullptr;
    node *aux = nullptr;
    int key;
    bool rev = false; //lazy

    node(int k) { key = k; }

    void push() {
        if (!rev) { return; }
        rev = false;
        swap(c[0], c[1]);
        if (c[0]) { c[0]->rev ^= true; }
        if (c[1]) { c[1]->rev ^= true; }
    }
    
    bool side() { return this == p->c[1]; }  //req parent

    void attach(node* v, bool x) {
        c[x] = v;
        if (v) { v->p = this; }
    }

    void detach() { p = p->c[side()] = nullptr; }  //req parent

    void rot() {  //req parent
        p->push();
        push();
        bool x = side();
        aux = p->aux;
        p->aux = nullptr;
        node* o = p;
        if (o->p) { o->p->attach(this, o->side()); }
        else { p = nullptr; }
        o->attach(c[!x], x);
        attach(o, !x);
    }

    void splay() {  //become root of splay tree
        while (p) {
            if (!p->p) {}
            else if (side() == p->side()) { p->rot(); }
            else { rot(); }
            rot();
        }
    }

    void access() {
        push();
        splay();
        if (c[1]) {
            c[1]->aux = this;
            c[1]->detach();
        }
        while (aux) {
            aux->splay();
            aux->push();
            if (aux->c[1]) {
                aux->c[1]->aux = aux;
                aux->c[1]->p = nullptr;
            }
            aux->attach(this, 1);
            aux = nullptr;
            splay();
        }
        push();
    }

    void reroot() {
        access();
        if (!c[0]) { return; }
        c[0]->rev ^= true;
        c[0]->aux = this;
        c[0]->detach();
    }

    node *find() {
        access();
        node *res = this;
        while (res->c[0]) { res = res->c[0]; }
        res->access();  //do not forget to do this!
        return res;
    }

    //u is a root vertex, make v parent
    friend void link(node *u, node *v) {
        v->access();
        u->access();
        v->attach(u, 1);
    }

    //remove u from its parent (guaranteed non root)
    friend void cut(node *u) {
        u->access();
        u->c[0]->detach();
    }

    friend bool con(node *u, node *v) { return u->find() == v->find(); }

    friend node* lca(node *u, node *v) {
        con(u, v);
        u->access();
        v->access();
        return u->aux ? u->aux : u;
    }
};

template<class T> using vt = vector<T>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vt<node*> tree(N);
    for (int i = 0; i < N; i++) {
        tree[i] = new node(i);
    }
    while (Q--) {
		string a;
		cin >> a;
		int b, c;
		cin >> b; b--;
        if (a != "cut") { cin >> c; c--; }
		if (a == "link") { link(tree[b], tree[c]); }
		if (a == "cut") { cut(tree[b]); }
		if (a == "lca") { cout << lca(tree[b], tree[c])->key + 1 << "\n"; }
    }
}
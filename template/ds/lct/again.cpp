#include <bits/stdc++.h>

using namespace std;

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
        push();  //whoops! i didn't have this before
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
        res->access();
        return res;
    }

    friend void link(node *u, node *v) {  //v becomes par of u
        u->reroot();
        v->access();
        v->attach(u, 1);
    }

    friend void cut(node *u, node *v) {
        u->reroot();
        v->access();
        u->detach();
    }

    friend void cut(node *u) {  //WARNING: u cannot be root
        u->access();
        u->c[0]->detach();
    }

    friend node* lca(node *u, node *v) {
        u->access();
        v->access();
        u->splay();
        return u->aux ? u->aux : u;
    }

    friend bool con(node *u, node *v) { return u->find() == v->find(); }
};

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vec<node*> tree(N);
    rep(i, N) {
        tree[i] = new node(i);
    }
    rep(q, Q) {
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
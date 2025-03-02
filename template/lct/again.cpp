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

    void cut(node *v) {
        reroot();
        v->access();
        detach();
    }

    void link(node *v) {
        reroot();
        v->access();
        v->attach(this, 1);
    }

    bool con(node *v) { return find() == v->find(); }
};

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vec<node*> lct(N);
    rep(i, N) {
        lct[i] = new node(i);
    }
    rep(q, Q) {
		string a;
		cin >> a;
		int b, c;
		cin >> b >> c; b--; c--;
		if (a == "add") { lct[b]->link(lct[c]); }
		if (a == "rem") { lct[b]->cut(lct[c]); }
		if (a == "conn") { cout << (lct[b]->con(lct[c]) ? "YES" : "NO") << "\n"; }
    }
}
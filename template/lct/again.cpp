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

    void splay() {  //become root
        while (p) {
            if (!p->p) {}
            else if (side() == p->side()) { p->rot(); }
            else { rot(); }
            rot();
        }
    }

    void print() {
        if (c[0]) { c[0]->print(); }
        cout << key << " ";
        if (c[1]) { c[1]->print(); }
    }

    void access() {
        splay();
        if (c[1]) {
            c[1]->aux = this;
            c[1]->detach();
        }
        while (aux) {
            auto v = aux;
            v->splay();
            if (v->c[1]) {
                v->c[1]->aux = v;
                v->c[1]->p = nullptr;
            }
            v->attach(this, 1);
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
    bool con(node *v) {
        access();
        v->access();
        return p;
    }
};

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;

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
		if (a == "add") { lct[b]->link(lct[c]); assert(lct[b]->con(lct[c])); }
		if (a == "rem") { lct[b]->cut(lct[c]); }
		if (a == "conn") { cout << (lct[b]->con(lct[c]) ? "YES" : "NO") << "\n"; }
    }
}
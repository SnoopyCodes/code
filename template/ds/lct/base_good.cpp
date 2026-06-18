#include <bits/stdc++.h>
 
using namespace std;
 
#define add push_back
template<class T> using vt = vector<T>;
//is dir() unclean?
//splitting into !is_root() improves perf by .02 s
struct node {
    int val, size = 1;
    node *p, *c[2];
    bool flip = false;
 
    node(int v): val(v) {}

    void push() {
        if (!flip) { return; }
        flip = false;
        swap(c[0], c[1]);
        for (auto &x : c) if (x) { x->flip ^= 1; }
    }
    inline int dir() { return !p || (p->c[0] != this && p->c[1] != this) ? -1 : p->c[1] == this; }
    void rel(node *v, int d) { //set the relationship b/w the two
        if (~d) { c[d] = v; }
        if (v) { v->p = this; }
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
 
    void access() {
        for (node *v = this, *prev = nullptr; v; prev = v, v = v->p) {
            v->splay();
            v->rel(prev, 1);
        }
        splay();
    }
    void reroot() {
        access();
        flip ^= 1;
    }
    node *find() {  
        access();
        node *res = this;
        while (res->c[0]) { res = res->c[0]; }
        res->access();
        return res;
    }
};
void link(node *u, node *v) {
    u->reroot();
    v->access();
    v->rel(u, 1);
}
void cut(node *u, node *v) {
    u->reroot();
    v->access();
    v->c[0] = u->p = nullptr;
}
bool con(node *u, node *v) { return u->find() == v->find(); }
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vt<node> tree; tree.reserve(N);
    vt<int> a(N);
    for (int i = 0; i < N; i++) {
        tree.emplace_back(i); }
    while (Q--) {
		string a;
		cin >> a;
		int u, v; cin >> u >> v; u--; v--;
        if (a == "add") { link(&tree[u], &tree[v]); }
        else if (a == "conn") { cout << (con(&tree[u], &tree[v]) ? "YES" : "NO") << "\n"; }
        else { cut(&tree[u], &tree[v]); }
    }
} 

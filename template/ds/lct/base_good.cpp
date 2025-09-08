#include <bits/stdc++.h>
 
using namespace std;
 
#define long long long
#define add push_back
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;
 
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
    inline bool is_root() { return p ? p->c[0] != this && p->c[1] != this : 1; } //is splay tree root
    inline int dir() { return is_root() ? -1 : p->c[1] == this; }
    friend void rel(node *u, node *v, int d) { //set the relationship b/w the two
        if (d >= 0) { u->c[d] = v; }
        if (v) { v->p = u; }
    }
    void rot() { //needs p
        p->push(); push();
        int x = dir();
        node *o = p;
        rel(o->p, this, o->dir());
        rel(o, c[x ^ 1], x);
        rel(this, o, x ^ 1);
    }
    void splay() {
        while (!is_root()) {
            if (!p->is_root()) { (dir() == p->dir() ? p : this)->rot(); }
            rot();
        }
        push();
    }
 
    void access() {
        for (node *v = this, *prev = nullptr; v; prev = v, v = v->p) {
            v->splay();
            rel(v, prev, 1);
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
    friend void link(node *u, node *v) {
        u->reroot();
        v->access();
        rel(v, u, 1);
    }
    friend void cut(node *u, node *v) {
        u->reroot();
        v->access();
        v->c[0] = u->p = nullptr;
    }
    friend bool con(node *u, node *v) { return u->find() == v->find(); }
};
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vt<node> tree; tree.reserve(N);
    for (int i = 0; i < N; i++) {
        tree.emplace_back(i);
    }
    while (Q--) {
		string a;
		cin >> a;
		int u, v; cin >> u >> v; u--; v--;
        if (a == "add") { link(&tree[u], &tree[v]); }
        else if (a == "conn") { cout << (con(&tree[u], &tree[v]) ? "YES" : "NO") << "\n"; }
        else { cut(&tree[u], &tree[v]); }
    }
} 

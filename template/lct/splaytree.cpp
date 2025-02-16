#include <bits/stdc++.h>

using namespace std;
//https://usaco.guide/adv/link-cut-tree?lang=cpp
//mit pdf lmao
struct splaytree {
    struct node {
        array<node*, 2> c{};
        node* p = nullptr;
        int key;
        node(int k) { key = k; }
        
        bool side() { return this == p->c[1]; }
        void attach(node* n, bool x) {
            c[x] = n;
            if (n) { n->p = this; }
        }
        void detach() {  //from parent
            p = p->c[side()] = nullptr;
        }
 
        void rot() {  //default rotation
            bool x = side();
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
 
        node* find(int k) {  //find the node closest to k
            if (key == k) { splay(); return this; }
            else if (key < k && c[1]) { return c[1]->find(k); }
            else if (key > k && c[0]) { return c[0]->find(k); }
            splay();
            return this;
        }
        node* findmin() {
            if (c[0]) { return c[0]->findmin(); }
            splay();
            return this;
        }
        node* findmax() {
            if (c[1]) { return c[1]->findmax(); }
            splay();
            return this;
        }
        void print() {
            if (c[0]) { c[0]->print(); }
            cout << key << " ";
            if (c[1]) { c[1]->print(); }
        }
    } *root = nullptr;
 
    void join(node *v) {  //joins root to a tree less than itself
        if (root) {
            root = root->findmin();
            root->attach(v, 0);
        }   else { root = v; }
    }
    node *split(int piv) { //returns tree with nodes < piv
        find(piv);
        node *l = root->c[0];
        if (root->key >= piv) {
            if (l) { l->detach(); }
        }   else {
            l = root;
            root = root->c[1];
            if (root) { root->detach(); }
        }
        return l;
    }
 
    void add(int k) {
        if (!root) { root = new node(k); return; }
        node *l = split(k);
        node *v = new node(k);
        v->attach(l, 0);
        v->attach(root, 1);
        root = v;
    }
    void rem(int k) {
        if (!root) { return; }
        find(k);
        if (root->key != k) { return; }
        node *left = root->c[0], *right = root->c[1];
        if (left) { left->detach(); }
        if (right) { right->detach(); }
        delete root;
        root = right;
        join(left);
    }
    void print() {
        if (root) { root->print(); }
        cout << endl;
    }
    void find(int x) {  //sets root to be closest node to x
        if (root) { root = root->find(x); }
    }
    void ub(int x) { //first >
        if (!root) { return; }
        find(x);
        if (root->key > x || !root->c[1]) { return; }
        root = root->c[1]->findmin();
    }
    void lb(int x) {  //last <=
        if (!root) { return; }
        find(x);
        if (root->key <= x || !root->c[0]) { return; }
        root = root->c[0]->findmax();
    }
    void min() { root = root->findmin(); }
    void max() { root = root->findmax(); }
};


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // freopen("in.txt", "r", stdin);
    int N, M; cin >> N >> M;
    splaytree t;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        t.add(x);
    }
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        t.lb(x);
        int k = t.root ? t.root->key : 2e9;
        if (k <= x) {
            cout << k << "\n";
            t.rem(k);
        }   else { cout << -1 << "\n"; }
    }

}
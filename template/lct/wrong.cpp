#include <bits/stdc++.h>
 
using namespace std;
//https://usaco.guide/adv/link-cut-tree?lang=cpp
//mit pdf lmao
//zeocool impl orz!
//this doesn't actually implement bst ops, mainly to be used with lct
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
 
        //tree ops, just set
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
    } *root = new node(2e9);  //"end" of the tree
 
    void join(node *v) {  //joins root to a tree less than itself
        if (root) {
            root = root->findmin();
            root->attach(v, 0);
        }   else {
            root = v;
        }
    }
    node *split(int piv) { //returns tree with nodes < piv
        lb(piv);  //all nodes to the left are < piv
        node *l = root->c[0];
        if (root->key >= piv) {
            if (l) { l->detach(); }
        }
        return l;
    }
 
    void add(int k) {
        node *l = split(k);
        node *v = new node(k);
        v->attach(l, 0);
        v->attach(root, 1);
        root = v;
    }
    void rem(int k) {
        lb(k);
        if (root->key != k) { return; }
        node *left = root->c[0], *right = root->c[1];
        if (left) { left->detach(); }
        if (right) { right->detach(); }
        root = right;
        join(left);
    }
    void print() {
        if (root) { root->print(); }
        cout << endl;
    }
    void find(int x) {  //sets root to be closest node to x
        root = root->find(x);
    }
    void ub(int x) {  //root is first node > x
        find(x);
        node *v = root;
        while (v->c[1] && v->key <= x) { v = v->c[1]; }
        root = v;
        root->splay();
    }
    void lb(int x) {  //root is first node >= x
        find(x);
        node *v = root;
        while (v->key < x) { v = v->c[1]; }
        while (v->c[0] && v->c[0]->key == x) { v = v->c[0]; }
        root = v;
        root->splay();
    }
    void min() { root = root->findmin(); }
    void max() { root = root->findmax()->c[0]; }
};
vector<int> v;
 
void trav(auto r) {
    if (r->c[0]) { trav(r->c[0]); }
    v.push_back(r->key);
    if (r->c[1]) { trav(r->c[1]); }
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    splaytree t;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        //insert
        t.add(x);
    }
    trav(t.root);
    for (int i = 0; i < N; i++) {
        assert(v[i] <= v[i + 1]);
    }
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        t.ub(x);
        auto res = t.root;
        res = res->c[0];
        if (res) {
            cout << res->key << "\n";
            t.rem(res->key);
        }
        else { cout << -1 << "\n"; }
    }
}

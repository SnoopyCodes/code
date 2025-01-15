#include <bits/stdc++.h>

using namespace std;
//https://usaco.guide/adv/link-cut-tree?lang=cpp
//mit pdf lmao
//zeocool impl orz!
//this doesn't actually implement bst ops, mainly to be used with lct
struct node {
    array<node*, 2> c{};
    node* p = nullptr;
    int key = 0;
    node(int k) { key = k; }
    
    bool side() { return this == p->c[1]; }
    void attach(node* n, bool x) {
        c[x] = n;
        if (n) { n->p = this; }
    }
    //assumes p exists
    void rot() {
        bool x = side();
        node* o = p;
        if (o->p) { o->p->attach(this, o->side()); }
        else { p = nullptr; }
        o->attach(c[!x], x);
        attach(o, !x);
    }
    void splay() {
        while (p) {
            if (!p->p) { rot(); }
            else if (side() == p->side()) { p->rot(); rot(); }
            else { rot(); rot(); }
        }
    }

    void detach() {  //from parent
        p->c[side()] = nullptr;
        p = nullptr;
    }

    //tree ops, just set
    node* find(int k) {
        if (key == k) { splay(); return this; }
        else if (key < k) {
            if (c[0]) { return c[0]->find(k); }
            splay();
            return nullptr;
        }
        if (c[1]) { return c[1]->find(k); }
        splay();
        return nullptr;
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
    void join(node *v) {  //to right side
        findmax();
        attach(v, 1);
    }
    void print() {
        if (c[0]) { c[0]->print(); }
        cout << key << " ";
        if (c[1]) { c[1]->print(); }
    }
};
struct splaytree {
    node *root = nullptr;
    node* split(int k) {
        root->find(k);
        if (root->key > k) {
            auto x = root;
            root = nullptr;
            return x;
        }
        if (k == 7) { cout << root->key << endl; }
        node *r = root->c[1];
        if (r) { r->detach(); }
        return r;
    }
    void insert(int k) {
        if (!root) { root = new node(k); }
        else {
            auto r = split(k);
            node *l = new node(k);

            l->attach(r, 1);
            l->attach(root, 0);
            root = l;
        }
    }
    int get(int k) {
        //find the first element <= it
        root->find(k);
        node *x;
        if (root->key == k) { x = root; }
        else if (!root->c[0]) { return -1; }
        x = root->c[0];
        int val = x->key;
        //delete x
        auto r = split(k);
        auto p = x; x = x->c[0];
        x->detach();
        x->join(r);
        return val;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    splaytree t;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        t.insert(x);
        t.root->print();
        cout << endl;
    }
    t.root->print();
    // for (int i = 0; i < M; i++) {
    //     cout << endl;
    //     int x; cin >> x;
    //     cout << t.get(x) << "\n";
    // }
}
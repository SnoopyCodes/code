#include <bits/stdc++.h>

using namespace std;

struct splaytree {
    struct node {
        array<node*, 2> c{};
        node* p = nullptr;
        int key, size = 1;
        node(int k) { key = k; }
        void upd() {
            size = 1;
            if (c[0]) { size += c[0]->size; }
            if (c[1]) { size += c[1]->size; }
        }
        
        bool side() { return this == p->c[1]; }  //req parent
        void attach(node* v, bool x) {
            c[x] = v;
            if (v) { v->p = this; }
        }
        void detach() { p = p->c[side()] = nullptr; }  //req parent
 
        void rot() {  //req parent
            bool x = side();
            node* o = p;
            if (o->p) { o->p->attach(this, o->side()); }
            else { p = nullptr; }
            o->attach(c[!x], x);
            attach(o, !x);
            o->upd();
            upd();
        }
        void splay() {  //become root
            while (p) {
                if (!p->p) {}
                else if (side() == p->side()) { p->rot(); }
                else { rot(); }
                rot();
            }
        }
 
        node* find(int k) {  //find the kth node, 0-indexed
            int l_sz = c[0] ? c[0]->size : 0;
            if (l_sz == k) { splay(); return this; }
            if (l_sz > k) { return c[0]->find(k); }  //move left
            else { return c[1]->find(k - l_sz - 1); }
        }
        void print() {
            if (c[0]) { c[0]->print(); }
            cout << key << "_" << size << " ";
            if (c[1]) { c[1]->print(); }
        }
    } *root = nullptr;
 
    void join(node *v) {  //joins root to a tree > itself
        if (root) {
            root = root->find(root->size - 1);
            root->attach(v, 1);
            root->upd();
        }   else { root = v; }
    }
    node *split(int piv) { //returns tree with nodes < piv
        find(piv);
        node *l = root->c[0];
        if (l) { l->detach(); root->upd(); }
        return l;
    }
 
    int find(int p) {  //set root to pth, p < sz
        if (root) { root = root->find(p); }
        return root->key;
    }
    void add(int key, int p) {
        node *v = new node(key);
        if (!root || p == root->size) { v->attach(root, 0); }
        else {
            node *l = split(p);
            v->attach(l, 0);
            v->attach(root, 1);
        }
        v->upd();
        root = v;
    }
    void rem(int p) {  //position
        if (!root) { return; }
        find(p);
        node* del = root;
        node *r = root->c[1];
        if (r) { r->detach(); }
        root = root->c[0];
        if (root) { root->detach(); }
        delete del;
        join(r);
    }
};

#define long int64_t
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long uld(long a, long b) { return uniform_int_distribution<long>(a, b)(rng); }

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int ops = 1000000;
    int sz = 0;
    vector<array<int, 2>> oper(2 * ops);
    for (int i = 0; i < ops; i++) {
        int pos = uld(0, sz - 1);
        sz++;
        oper[i] = {0, pos};
    }
    for (int i = 0; i < ops; i++) {
        int t = uld(0, 2);
        int pos = uld(0, sz - 1);
        oper[i + ops] = {t, pos};
        if (t == 0) { sz++; }
        else if (t == 1) { sz--; }
    }
    auto beg = chrono::system_clock::now();
    splaytree t;
    for (auto const&[type, p] : oper) {
        if (type == 0) {
            t.add(0, p);
        }   else if (type == 1) {
            t.rem(p);
        }   else {
            t.find(p);
        }
    }
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed = end - beg;
    cout << elapsed.count() << "\n";
    //~1 second for 500k insertions, 500k random ops
    //2.5 seconds for 1 million insertions, 1 million ops
    //damn constant factor is tuff
}
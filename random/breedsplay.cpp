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
 
    void find(int p) { if (root) { root = root->find(p); } }
    
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
    int operator[](int i) { find(i); return root->key; }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout); 
    splaytree t;
    int N, Q; cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int b; cin >> b; b--;
        t.add(b, i);
    }
    splaytree one, two, three;
    one.add(0, 0), two.add(0, 0), three.add(0, 0);
    for (int i = 1; i <= N; i++) {
        one.add(one.root->key, i);
        two.add(two.root->key, i);
        three.add(three.root->key, i);
        t.find(i-1);
        if (t.root->key == 0) { one.rem(i); one.add(one.root->key + 1, i); }
        else if (t.root->key == 1) { two.rem(i); two.add(two.root->key + 1, i); }
        else { three.rem(i); three.add(three.root->key + 1, i); }
    }
    for (int q = 0; q < Q; q++) {
        int l, r; cin >> l >> r; l--;
        cout << one[r] - one[l] << " ";
        cout << two[r] - two[l] << " ";
        cout << three[r] - three[l] << "\n";
    }

}
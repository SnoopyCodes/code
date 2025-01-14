#include <bits/stdc++.h>

using namespace std;

struct node {
    array<node*, 2> c{};
    node *p = nullptr, *aux = nullptr;  //auxiliary connection
    int key = 0;
    bool rev = false;  //reroot
    node(int k) { key = k; }
    
    void push() {
        if (rev) {
            rev = false;
            swap(c[0], c[1]);
            if (c[0]) { c[0]->rev = true; }
            if (c[1]) { c[1]->rev = true; }
        }
    }

    bool side() { return this == p->c[1]; }

    //attach node n to this
    void attach(node* v, bool x) {
        c[x] = v;
        if (v) { v->p = this; }
    }
    
    void detach() {  //from parent
        p->c[side()] = nullptr;
        p = nullptr;
    }

    //move to parent's placement
    void rot() {
        bool x = side();
        p->push(); push();
        node* o = p;  //original parent
        //if par is root, move aux to this node
        aux = o->aux;
        o->aux = nullptr;
        //o's parent is ours
        if (o->p) { o->p->attach(this, o->side()); }
        else { p = nullptr; }
        //move o and child being kicked
        o->attach(c[!x], x);
        attach(o, !x);
    }
    void splay() {
        //while not at root, splay step
        while (p) {
            p->push(); push();
            if (!p->p) { rot(); }
            else if (side() == p->side()) { p->rot(); rot(); }
            else { rot(); rot(); }
        }
    }

    void access() {
        //become root
        splay();
        //kick right child (pref path down to this)
        if (c[1]) {
            c[1]->aux = this;
            c[1]->detach();
        }
        //while not at root of aux tree, make this the root of splay, and also set pref path from root to this
        //(root to us is splay tree)
        while (aux) {
            aux->splay();
            if (aux->c[1]) {
                aux->c[1]->aux = aux;
                aux->c[1]->detach();
            }
            aux->c[1] = this;
            aux = nullptr;
            splay();
        }
    }
    //make this REAL ROOT of tree
    void reroot() {
        access();
        rev ^= true;
        push();
    }
    node* find() {
        access();
        node* tmp = this;
        while (tmp->c[0] != nullptr) { tmp = c[0]; }
        tmp->splay();
        return tmp;
    }
    void cut(node* v) {
        access();
        if (v != c[0]) { v->cut(this); return; }
        v->detach();
    }
    void link(node* v) {
        reroot();
        v->access();
        v->attach(this, 1);
    }
};
vector<node*> lct;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    lct.resize(N);
    for (int i = 0; i < N; i++) { lct[i] = new node(i); }
    lct[0]->link(lct[1]);
    lct[0]->link(lct[2]);
    for (int i = 0; i < N; i++) {
        if (lct[i]->p) { cout << lct[i]->p->key << " " << lct[i]->side() << "_";}
        else { cout << -1 << " ";}
    }
    cout << "\n";
    cout << lct[1]->find()->key << "\n";
    for (int i = 0; i < N; i++) {
        if (lct[i]->p) { cout << lct[i]->p->key << " " << lct[i]->side() << "_";}
        else { cout << -1 << " ";}
    }
    cout << "\n";
	// for (int i = 0; i < Q; i++) {
	// 	string a;
	// 	cin >> a;
	// 	int b, c;
    //     for (int i = 0; i < N; i++) {
    //         if (lct[i]->p) { cout << lct[i]->p->key << " ";}
    //         else { cout << -1 << " ";}
    //     }
    //     cout << "\n";
	// 	cin >> b >> c; b--; c--;
	// 	if (a == "add") { lct[b]->link(lct[c]); }
	// 	if (a == "rem") { lct[b]->cut(lct[c]); }
	// 	if (a == "conn") { cout << lct[b]->find()->key << " " << lct[c]->find()->key << endl; }
    //     cout << "?" << endl;
	// }
}
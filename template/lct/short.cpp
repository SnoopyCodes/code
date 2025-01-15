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
    
    void attach(node* v, bool x) {
        c[x] = v;
        if (v) { v->p = this; }
    }
    
    void detach() {
        p->c[side()] = nullptr;
        p = nullptr;
    }

    void rot() {
        bool x = side();
        p->push(); push();
        node* o = p;  //original parent
        aux = o->aux;
        o->aux = nullptr;
        if (o->p) { o->p->attach(this, o->side()); }
        else { p = nullptr; }
        o->attach(c[!x], x);
        attach(o, !x);
    }

    void splay() {
        while (p) {
            p->push(); push();
            if (!p->p) { rot(); }
            else if (side() == p->side()) { p->rot(); rot(); }
            else { rot(); rot(); }
        }
    }

    void access() {
        splay();
        if (c[1]) {
            c[1]->aux = this;
            c[1]->detach();
        }
        while (aux) {
            aux->splay();
            if (aux->c[1]) {
                aux->c[1]->aux = aux;
                aux->c[1]->detach();
            }
            aux->attach(this, 1);
            aux = nullptr;
            splay();
        }
    }
    
    void reroot() {
        access();
        rev ^= true;
        push();
    }

    node* find() {
        access();
        node* tmp = this;
        while (tmp->c[0] != nullptr) { tmp = tmp->c[0]; }
        tmp->splay();
        return tmp;
    }

    void cut(node* v) {
        reroot();
        v->access();
        detach();
    }

    void link(node* v) {
        reroot();
        v->access();
        v->attach(this, 1);
    }

    void print() {
        cout << "par: " << (p ? p->key : -1) << " ";
        cout << "aux: " << (aux ? aux ->key : -1) << endl;
        cout << "left: " << (c[0] ? c[0]->key : -1) << " " << "right: " << (c[1] ? c[1]->key : -1) << endl;
    }
};
vector<node*> lct;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("test_case.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N, Q; cin >> N >> Q;
    lct.resize(N);
    for (int i = 0; i < N; i++) { lct[i] = new node(i); }
	for (int i = 0; i < Q; i++) {
		string a;
		cin >> a;
		int b, c;
		cin >> b >> c; b--; c--;
		if (a == "add") { lct[b]->link(lct[c]); }
		if (a == "rem") { lct[b]->cut(lct[c]); }
		if (a == "conn") { cout << ((lct[b]->find()->key == lct[c]->find()->key) ? "YES" : "NO") << "\n"; }
	}
}
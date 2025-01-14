#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// BeginCodeSnip{Benq Link Cut Tree}
typedef struct snode *sn;
struct snode {         //////// VARIABLES
	sn p, c[2];        // parent, children
	bool flip = 0;     // subtree flipped or not
	ll val;            // value in node
	snode(int _val) : val(_val) {
		p = c[0] = c[1] = NULL;
	}
	void prop() {  // lazy prop
		if (!flip) return;
		swap(c[0], c[1]);
		flip = 0;
		for (int i = 0; i < 2; i++)
			if (c[i]) c[i]->flip ^= 1;
	}
	//////// SPLAY TREE OPERATIONS
	int dir() {
		if (!p) return -2;
		for (int i = 0; i < 2; i++)
			if (p->c[i] == this) return i;
		return -1;  // p is path-parent pointer
	}  // -> not in current splay tree
	// test if root of current splay tree
	bool isRoot() { return dir() < 0; }
	friend void setLink(sn x, sn y, int d) {
		if (y) y->p = x;
		if (d >= 0) x->c[d] = y;
	}
	void rot() {  // assume p and p->p propagated
		int x = dir();
		sn pa = p;
		setLink(pa->p, this, pa->dir());
		setLink(pa, c[x ^ 1], x);
		setLink(this, pa, x ^ 1);
	}
	void splay() {
		while (!isRoot() && !p->isRoot()) {
			p->p->prop(), p->prop(), prop();
			dir() == p->dir() ? p->rot() : rot();
			rot();
		}
		if (!isRoot()) p->prop(), prop(), rot();
		prop();
	}
	//////// BASE OPERATIONS
	void access() {  // bring this to top of tree, propagate
		for (sn v = this, pre = NULL; v; v = v->p) {
			v->splay();  // now switch virtual children
			v->c[1] = pre;
			pre = v;
		}
		splay();
	}
	void makeRoot() {
		access();
		flip ^= 1;
		access();
	}
	//////// QUERIES
	friend sn lca(sn x, sn y) {
		if (x == y) return x;
		x->access(), y->access();
		if (!x->p) return NULL;
		x->splay();
		return x->p ?: x;  // y was below x in latter case
	}  // access at y did not affect x -> not connected
	friend bool connected(sn x, sn y) { return lca(x, y); }
	// # nodes above
	sn getRoot() {  // get root of LCT component
		access();
		sn a = this;
		while (a->c[0]) a = a->c[0], a->prop();
		a->access();
		return a;
	}
	//////// MODIFICATIONS
	void set(int v) {
		access();
		val = v;
	}
	friend void link(sn x, sn y, bool force = 0) {
		if (force) y->makeRoot();  // make x par of y
		else {
			y->access();
		}
		x->access();
		setLink(y, x, 0);
	}
	friend void cut(sn y) {  // cut y from its parent
		y->access();
		y->c[0]->p = NULL;
		y->c[0] = NULL;
	}
	friend void cut(sn x, sn y) {  // if x, y adj in tree
		x->makeRoot();
		y->access();
		cut(y);
	}
};

const int MAX_N = 1e5;
sn LCT[MAX_N];

int main() {
	int n;
	int q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) { LCT[i] = new snode(i + 1); }

	for (int i = 0; i < q; i++) {
		string t;
		cin >> t;
		if (t == "link") {
			int u, v;
			cin >> u >> v;
			u--, v--;
			link(LCT[v], LCT[u], 1);
		} else if (t == "cut") {
			int u;
			cin >> u;
			u--;
			cut(LCT[u]);
		} else if (t == "lca") {
			int u, v;
			cin >> u >> v;
			u--, v--;
			cout << lca(LCT[u], LCT[v])->val << "\n";
		}
	}
}
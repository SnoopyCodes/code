#include <bits/stdc++.h>


using namespace std;
 
struct node {
	int l, r;
	int val = 1e9;
	node *lc = nullptr, *rc = nullptr;
	node(int lb, int rb) { l = lb, r = rb; }
 
	void extend() {
		if (!lc && l + 1 < r) {
			int m = (l + r) / 2;
			lc = new node(l, m);
			rc = new node(m, r);
		}
	}
	void add(int p, int v) {
		extend();
		if (lc) {
			if (p < lc->r) { lc->add(p, v); }
			else { rc->add(p, v); }
            val = min(lc->val, rc->val);
		}	else {
			val = v;
		}
	}
	int query(int ql, int qr) {
		if (ql <= l && r <= qr) { return val; }
		if (max(l, ql) >= min(r, qr)) { return 1e9; }
		extend();
		return min(lc->query(ql, qr), rc->query(ql, qr));
	}
};
 
int main() {
	int N, Q; cin >> N >> Q;
	node *seg = new node(0, N);
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		seg->add(i, x);
	}
	for (int q = 0; q < Q; q++) {
		int t; cin >> t;
		if (t & 1) {
			int k, x; cin >> k >> x; k--;
			seg->add(k, x);
		}	else {
			int l, r; cin >> l >> r; l--;
			cout << seg->query(l, r) << endl;
		}
	}
}
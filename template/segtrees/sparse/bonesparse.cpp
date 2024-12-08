#include <bits/stdc++.h>

using namespace std;
using ll = long long;
 
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
	void upd(int p, int v) {
		extend();
		if (lc) {
			if (p < lc->r) { lc->upd(p, v); }
			else { rc->upd(p, v); }
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
    cin.tie(0) -> sync_with_stdio(0);
    
}
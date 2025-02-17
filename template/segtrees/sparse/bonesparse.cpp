#include <bits/stdc++.h>

using namespace std;

//min example
struct node {
	int l, r;
	int val = 0;
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
            val = max(lc->val, rc->val);
		}	else {
			val = v;
		}
	}
	int query(int ql, int qr) {
        if (qr <= l || r <= ql) { return 1e9; }
		if (ql <= l && r <= qr) { return val; }
		extend();
		return max(lc->query(ql, qr), rc->query(ql, qr));
	}
	int walk(int x, int ql, int qr) {  //find leftmost element >= x in range [ql, qr)

	}
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}
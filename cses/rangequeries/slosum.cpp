#include <bits/stdc++.h>
 
using namespace std;

 
struct node {
	int l, r;
	long long val = 0;
	node *lc = nullptr, *rc = nullptr;
	node(int lb, int rb) { l = lb, r = rb; }
 
	void extend() {
		if (!lc && l + 1 < r) {
			int m = (l + r) / 2;
			lc = new node(l, m);
			rc = new node(m, r);
		}
	}
	void add(int p, long long v) {
		extend();
		if (lc) {
			if (p < lc->r) { lc->add(p, v); }
			else { rc->add(p, v); }
			val = lc->val + rc->val;
		}	else {
			val = v;
		}
	}
	long long query(int ql, int qr) {
		if (ql <= l && r <= qr) { return val; }
		if (max(l, ql) >= min(r, qr)) { return 0; }
		extend();
		return lc->query(ql, qr) + rc->query(ql, qr);
	}
};
 
int main() {
    cin.tie(0) ->sync_with_stdio(0);
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

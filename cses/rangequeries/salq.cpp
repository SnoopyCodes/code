#include <bits/stdc++.h>
#include <chrono> // Include chrono for timing


using namespace std;
using namespace chrono; // For convenience

struct node {
    int val = 0;
    int l, r;
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
        val += v;
        if (lc) {
            if (p < lc->r) { lc->upd(p, v); }
            else { rc->upd(p, v); }
        }
    }
    int query(int ql, int qr) {
        if (ql <= l && r <= qr) { return val; }
        if (qr <= l || r <= ql) { return 0; }
        extend();
        return lc->query(ql, qr) + rc->query(ql, qr);
    }
};

int main() {
    auto start = high_resolution_clock::now();
    cin.tie(0) -> sync_with_stdio(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N, Q; cin >> N >> Q;
    vector<int> sals(N);
    node seg(0, 1e9 + 1);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        sals[i] = x;
        seg.upd(x, 1);
    }
    for (int q = 0; q < Q; q++) {
        char c; cin >> c;
        if (c == '!') {
            int p, x; cin >> p >> x; p--;
            seg.upd(sals[p], -1);
            sals[p] = x;
            seg.upd(x, 1);
        }   else {
            int l, r; cin >> l >> r;
            cout << seg.query(l, r + 1) << "\n";
        }

    }
     auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() / 1000.0 << "\n";
}
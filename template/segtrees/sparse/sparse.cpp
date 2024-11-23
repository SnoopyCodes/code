#include <bits/stdc++.h>

using namespace std;
template<typename T>
struct node {
    T def = 0, data = def;
    long long l, r;
    node *lc = nullptr, *rc = nullptr;
    node(int lb, int rb) { l = lb, r = rb; }
    T comb(T t1, T t2) { return max(t1, t2); }
    void extend() {
        if (!lc && l + 1 < r) {
            int m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void upd(long long p, T v) {
        extend();
        if (lc) {
            if (p < lc->r) { lc->upd(p, v); }
            else { rc->upd(p, v); }
            data = comb(lc->data, rc->data);
        }   else {
            data = v;
        }
    }
    T query(long long ql, long long qr) {
        if (ql <= l && r <= qr) { return data; }
        if (l >= qr || r <= ql) { return def; }
        extend();
        return comb(lc->query(ql, qr), rc->query(ql, qr));
    }
    long long walk(T val) {
        if (val > data) { return l - 1; }
        if (l + 1 == r) { return l; }
        extend();
        if (lc->data >= val) { return lc->walk(val); }
        return rc->walk(val);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    node<int> *seg = new node<int>(0, N);
    for (int i = 0; i < N; i++) {
        int h; cin >> h;
        seg->upd(i, h);
    }
    for (int i = 0; i < M; i++) {
        int r; cin >> r;
        int h = seg->walk(r);
        cout << h + 1 << " ";
        if (h != -1) { seg->upd(h, seg->query(h, h + 1) - r); }
    }
    cout << "\n";
}
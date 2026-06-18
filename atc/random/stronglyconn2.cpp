#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
const int P = 998244353;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

template<class V, class U, V defv, U defu, auto comb, auto agg, auto act>
struct node {
    node *lc, *rc;
    int l, r, m;
    V val = defv;
    U lz = defu;
    node(int l, int r):l(l),r(r),m((l+r)/2) {
        if (l + 1 == r) { return; }
        lc = new node(l, m);
        rc = new node(m, r);
    }
    void apply(U u) {
        val = act(u, val, l, r);
        lz = agg(u, lz);
    }
    void push() {
        lc->apply(lz);
        rc->apply(lz);
        lz = defu;
    }
    V qry(int ql, int qr) {
        if (qr <= l || r <= ql) { return defv; }
        if (ql <= l && r <= qr) { return val; }
        push();
        return comb(lc->qry(ql, qr), rc->qry(ql, qr));
    }
    void upd(int ql, int qr, U u) {
        if (qr <= l || r <= ql) { return; }
        if (ql <= l && r <= qr) { return apply(u); }
        push();
        lc->upd(ql, qr, u), rc->upd(ql, qr, u);
        val = comb(lc->val, rc->val);
    }

    void upd_pt(int i, int u) {
        if (l == i && i + 1 == r) {
            (val += u) %= P;
            return;
        }
        push();
        (i < m ? lc : rc)->upd_pt(i, u);
        val = comb(lc->val, rc->val);
    }
};

int comb(int a, int b) { return (a + b) % P; }
int act(int u, int v, int l, int r) { return u * v % P; }
int agg(int a, int b) { return a * b % P; }

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vt<vt<int>> range(N);
    for (int i = 0; i < M; i++) {
        int j, k; cin >> j >> k; j--; k--;
        range[j].add(k);
    }
    
    node<int, int, 0, 1, comb, agg, act> seg(0, N);
    seg.upd_pt(0, 1);

    vt dp(N, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j : range[i]) {

            seg.upd(j, N, 2);
            seg.upd_pt(j, seg.qry(i, j));
        }
    }

    cout << seg.qry(N - 1, N) << "\n";
}
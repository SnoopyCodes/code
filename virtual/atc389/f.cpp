#include <bits/stdc++.h>

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(i, s, e) for (int i = s; i!=e; s<e?i++:i--)
#define rep2(i, e) rep3(i, (e > 0 ? 0 : -(e)-1), (e>0?e:-1))

using namespace std;

template<typename V, typename U>
struct SegTree {
    int N, ql, qr;
    vector<V> data; 
    vector<U> change;
    V defv = 0, val;
    U defu = 0, alt;
    void init(int _N) {
        N = _N;
        data.resize(4 * N, defv);
        change.resize(4 * N, defu);
    }
    V comb(V a, V b) { return max(a, b); }
    void apply(int n, int l, int r, U u) {
        //change stuff, consider how updates stack
        change[n] += u;
        data[n] += u;
    }
    #define m ((l+r)/2)
    void push(int n, int l, int r) {
        apply(2*n, l, m, change[n]);
        apply(2*n+1, m, r, change[n]);
        change[n] = defu;
    }
    V qry(int n, int l, int r) {
        if(r <= ql || qr <= l) { return defv; }
        if(ql <= l && r <= qr) { return data[n]; }
        push(n, l, r);
        return comb(qry(2*n, l, m), qry(2*n+1, m, r));
    }
    void upd(int n, int l, int r) {
        if (r <= ql || qr <= l) { return; }
        if (ql <= l && r <= qr) {
            apply(n, l, r, alt);
        }   else {
            push(n, l, r);
            upd(2*n, l, m);
            upd(2*n+1, m, r);
            data[n] = comb(data[2*n], data[2*n+1]);
        }
    }
    int wlk(int n, int l, int r) {
        if (data[n] < val || r <= ql || qr <= l) { return -1; }
        if (l + 1 == r) { return l; }
        push(n, l, r);
        if (data[2*n] >= val && ql < m) {
            int left = wlk(2*n, l, m);
            if (left != -1) { return left; }
        }
        return wlk(2*n+1, m, r);
    }
    #undef m
    V query(int l, int r) { ql = l, qr = r; return qry(1, 0, N); }
    void update(int l, int r, U v) { ql = l, qr = r, alt = v; upd(1, 0, N); }
    int walk(V x, int l, int r) { val = x, ql = l, qr = r; return wlk(1, 0, N); }
};

int main() {
    cin.tie(0) ->sync_with_stdio(0);
    int N; cin >> N;
    const int MAX = 5e5;
    SegTree<int, int> seg; seg.init(MAX);
    rep(i, MAX) {
        seg.update(i, i + 1, i);
    }
    rep(i, N) {
        int l, r; cin >> l >> r; l--; r--;
        //increment all in the range[l, r]
        int li = seg.walk(l, 0, 5e5);
        int ri = seg.walk(r + 1, 0, 5e5);
        if (ri == -1) { ri = MAX; }
        if (seg.query(li, li + 1) > r) { continue; } //
        seg.update(li, ri, 1);
    }
    int Q; cin >> Q;
    rep(i, Q) {
        int x; cin >> x; x--;
        cout << seg.query(x, x + 1) + 1 << "\n";
    }
}
#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=(s);x!=(e);(s)<(e)?x++:x--)
#define rep2(x,e) rep3(x,e>0?0:-e-1,e>0?e:-1)

const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

struct upd {
    long val;
    bool add;
};
//61 lines, not too bad
template<typename V, typename U>
struct SegTree {
    int SN, ql, qr;
    vector<V> data; 
    vector<U> change;
    V defv = 0, val;
    U defu = {0, true}, alt;
    void init(int N) {
        SN = N;
        data.resize(4 * N, defv);
        change.resize(4 * N, defu);
    }
    V comb(V a, V b) { return a + b; }
    void apply(int n, int l, int r, U u) {
        //change stuff, consider how updates stack
        if (u.add) {
            change[n].val += u.val;
            data[n] += (r - l) * u.val;
        }   else {
            change[n] = u;
            data[n] = (r - l) * u.val;
        }
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
        return wlk(2*n+1, l, r);
    }
    #undef m
    V query(int l, int r) { ql = l, qr = r; return qry(1, 0, SN); }
    void update(int l, int r, U v) { ql = l, qr = r, alt = v; upd(1, 0, SN); }
    int walk(V x, int l, int r) { val = x, ql = l, qr = r; return wlk(1, 0, SN); }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //range updates and sums
    int N, Q; cin >> N >> Q;
    SegTree<long, upd> seg; seg.init(N);
    rep(i, N) {
        int x; cin >> x;
        seg.update(i, i + 1, {x, false});
    }
    rep(q, Q) {
        int t, l, r; cin >> t >> l >> r; l--;
        if (t == 1) {
            int x; cin >> x;
            seg.update(l, r, {x, true});
        }   else if (t == 2) {
            int x; cin >> x;
            seg.update(l, r, {x, false});
        }   else {
            cout << seg.query(l, r) << "\n";
        }
    }
}
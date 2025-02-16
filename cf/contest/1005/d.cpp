#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int fl(int x) {
    for (int b = 30; b > -1; b--) {
        if (x & 1 << b) { return b; }
    }
}

template<typename V>
struct node {
    V def = 0, val = def;
    V comb(V v1, V v2) { return max(v1, v2); }
    long l, r;
    node *lc = nullptr, *rc = nullptr;
    node(long lb, long rb) { l = lb, r = rb; }
    void extend() {
        if (!lc && l + 1 < r) {
            long m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void upd(long p, V v) {
        extend();
        if (lc) {
            if (p < lc->r) { lc->upd(p, v); }
            else { rc->upd(p, v); }
            val = comb(lc->val, rc->val);
        }   else {
            val = v;
        }
    }
    V query(long ql, long qr) {
        if (ql <= l && r <= qr) { return val; }
        if (qr <= l || r <= ql) { return def; }
        extend();
        return comb(lc->query(ql, qr), rc->query(ql, qr));
    }
    long walk(V v, long ql = -INFL, long qr = INFL + 1) {
        if (v > val) { return -INFL - 1; }
        if (qr <= l || r <= ql) { return -INFL - 1; }
        if (l + 1 == r) { return l; }
        extend();
        if (lc->val >= v && ql < (l + r) / 2) {
            long res =  lc->walk(v, ql, qr);
            if (res != -INFL - 1) { return res; }
        }
        return rc->walk(v, ql, qr);
    }
};

void solve() {
    int N, Q; cin >> N >> Q;
    vec<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    node<int> *seg = new node<int> (0, N);
    reverse(W.begin(), W.end());
    vec<int> px(N+1);
    for (int i = 0; i < N; i++) {
        seg->upd(i, fl(W[i]));
        px[i+1] = px[i] ^ W[i];
    }
    for (int q = 0; q < Q; q++) {
        int ans = -1;  //index we eat up to
        int w; cin >> w;
        for (int b = 29; b > -1; b--) {
            if (!(w & 1 << b)) { continue; }
            long to = seg->walk(b, ans + 1, N);
            if (to == -INFL - 1) { ans = N - 1; break; }
            w ^= px[to] ^ px[ans+1];
            ans = to - 1;
            if (W[to] > w) { break; }
            w ^= W[to];
            ans++;
        }
        cout << ans+1 << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
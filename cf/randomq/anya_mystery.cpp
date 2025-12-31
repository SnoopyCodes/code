#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
#define rep(i,a,b) for (auto i=a; i<(b); i++)


int f(int a, int b) { return (a + b) % 26; }

template<class V, class U, V defv, U defu, V (*comb)(V, V), U (*agg) (U, U)>
struct node {
    array<node*, 2> c{};
    int l, r;
    V val = defv;
    U lz = defu;
    node() {}
    void apply(U u) {
        val = comb(val, u * (r - l));
        lz = agg(u, lz);
    }
    void push() {
        c[0]->apply(lz);
        c[1]->apply(lz);
        lz = defu;
    }
    V qry(int ql, int qr) {
        if (qr <= l || r <= ql) { return defv; }
        if (ql <= l && r <= qr) { return val; }
        push();
        return comb(c[0]->qry(ql, qr), c[1]->qry(ql, qr));
    }
    void upd(int ql, int qr, U u) {
        if (qr <= l || r <= ql) { return; }
        if (ql <= l && r <= qr) { return apply(u); }
        push();
        c[0]->upd(ql, qr, u);
        c[1]->upd(ql, qr, u);
        val = comb(c[0]->val, c[1]->val);
    }
};

vt<node<int, int, 0, 0, f, f>> storage;
node<int, int, 0, 0, f, f> vals;
node<int, int, 0, 0, f, f> *set_links(int n, int l, int r) {
    storage[n].l = l, storage[n].r = r;
    if (l + 1 == r) { return &storage[n]; }
    // cout << n << " " << l << " " << r << endl;
    storage[n].c[0] = set_links(2 * n, l, (l + r) / 2);
    storage[n].c[1] = set_links(2 * n + 1, (l + r) / 2, r);
    return &storage[n];
}
void init(int n) {
    storage.clear();
    storage.resize(4 * n);
    vals = *set_links(1, 0, n);
}

int ck_eq_adj(int i) {
    return vals.qry(i, i + 1) == vals.qry(i + 1, i + 2);
}
int ck_eq_out(int i) {
    return vals.qry(i - 1, i) == vals.qry(i + 1, i + 2);
}



template<class T, T def, T (*f)(T, T)> struct SegmentTree {
    vector<T> t; int N;
    SegmentTree(int n):N(n),t(2 * n, def) {}
    void set(int i, T v) {
        t[i + N] = v;
        for (i = (i + N) / 2; i > 0; i >>= 1) {
            t[i] = f(t[i << 1], t[i << 1 | 1]);
        }
    }
    T query(int l, int r) {
        T resl = def, resr = def;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { resl = f(resl, t[l++]); }
            if (r & 1) { resr = f(t[--r], resr); }
        }
        return f(resl, resr);
    }
};
int g(int a, int b) { return a + b; }
SegmentTree<int, 0, g> adj(1), out(1);

void solve() {
    int N, M; cin >> N >> M;
    string s; cin >> s;
    init(N);
    adj = SegmentTree<int, 0, g>(N); //checks i, i + 1
    out = SegmentTree<int, 0, g>(N); //checks i - 1, i + 1


    rep(i, 0, N) {
        int v = s[i] - '0';
        vals.upd(i, i + 1, v);
    }
    rep(i, 0, N - 1) {
        adj.set(i, ck_eq_adj(i));
    }
    rep(i, 1, N - 1) {
        out.set(i, ck_eq_out(i));
    }

    auto adjok = [&](int i) {
        return i >= 0 && i < N - 1;
    };
    auto outok = [&](int i) {
        return i > 0 && i < N - 1;
    };
    while (M --> 0) {
        int t; cin >> t;
        if (t & 1) {
            int l, r, x; cin >> l >> r >> x; l--; r--;
            x %= 26;

            vals.upd(l, r + 1, x);

            //for 2-pair, l - 1 and r could be affected
            if (adjok(l - 1)) adj.set(l - 1, ck_eq_adj(l - 1));
            if (adjok(r)) adj.set(r, ck_eq_adj(r));
            //for 3 pair, [l - 1, l] and [r, r + 1] can be affected
            if (outok(l - 1)) out.set(l - 1, ck_eq_out(l - 1));
            if (outok(r)) out.set(r, ck_eq_out(r));
            if (outok(l)) out.set(l, ck_eq_out(l));
            if (outok(r + 1)) out.set(r + 1, ck_eq_out(r + 1));

        }   else {
            int l, r; cin >> l >> r; l--; r--;
            bool yes = false;
            yes |= adj.query(l, r); //query range [l, r - 1]
            yes |= out.query(l + 1, r); //query range [l + 1, r - 1]
            if (!yes) {
                cout << "yes" << "\n";
            }   else {
                cout << "no" << "\n";
            }
        }
    }

    

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
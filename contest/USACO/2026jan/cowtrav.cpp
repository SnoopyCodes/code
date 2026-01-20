#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
vt<int> par;
vt<vt<int>> radj;
vt<bool> visited;
vt<int> in_ds;
vt<int> type;
vt<int> in, subsz;
int nds = 0;
int euler;

struct rsps { //range set point sum
    int N;
    vector<int> seg;
    rsps(int n):N(n), seg(2 * N) {}

    void alter(int l, int r, int val) {
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                if (in[val-1] > in[seg[l]-1])
                seg[l] = val;
                l++;
            }
            if (r & 1) {
                if (in[val-1] > in[seg[r]-1])
                seg[r] = val;

                --r;
            }
        }
    }

    int query(int p) {
        for (p += N; p > 0; p /= 2) {
            if (seg[p]) { return seg[p]; }
        }
        return -1;
    }
};

struct node {
    node *lc, *rc;
    int l, r;
    int val = 0;
    int lz = -1;
    node() {}
    node(int l, int r):l(l),r(r) {
        if (l + 1 == r) { return; }
        lc = new node(l, (l + r) / 2);
        rc = new node((l + r) / 2, r);
    }
    void apply(int u) {
        if (u == -1) { return; }
        val += (r - l) * u;
        lz += u;
    }
    void push() {
        lc->apply(lz);
        rc->apply(lz);
        lz = -1;
    }
    int qry(int ql, int qr) {
        if (qr <= l || r <= ql) { return 0; }
        if (ql <= l && r <= qr) { return val; }
        push();
        return lc->qry(ql, qr) + rc->qry(ql, qr);
    }
    void upd(int ql, int qr, int u) {
        if (qr <= l || r <= ql) { return; }
        if (ql <= l && r <= qr) { return apply(u); }
        push();
        lc->upd(ql, qr, u);
        rc->upd(ql, qr, u);
        val = lc->val + rc->val;
    }
};


struct ds {
    vt<int> nodes;
    node seg;
    rsps layer;
    int n;
    set<ii<2>> s;
    ds(vt<int> v, int t):nodes(v), n(size(v)), seg(0, size(v)), layer(size(v)) {
        int rt = v[0];
        // cout << "init " << rt << " " << subsz[rt] << "\n";
        seg.upd(0, 1, subsz[rt]); //point set range sum
        layer.alter(0, n, (rt + 1)); //range set point sum
    }
    /*
    
    */

    int query_sub(int u) { return seg.qry(in[u], in[u] + subsz[u]); }
    ii<3> query(int u, int t) {
        //range set point update
        if (type[u] != -1) {
            // cout << "yo!" << "\n";
            if (type[u] == t) { return { 0, 0, 0 }; }
            else {
                // cout << u << " " << in[u] << "\n";
                int sub = seg.qry(in[u], in[u] + 1);
                // cout << sub << "\n";
                ii<3> res = {};
                res[t] += sub;
                res[type[u]] -= sub;
                return res;
            }
        }
        int par = layer.query(u) - 1;
        int amt = subsz[u] - query_sub(u); //how much we have here
        ii<3> res = {};
        res[t] = amt;
        seg.upd(in[par], in[par] + 1, -amt); //no longer has
        res[type[par]] -= amt;
        seg.upd(in[u], in[u] + 1, amt); //i forgot to update this?
        //range set, if it's not already set...
        layer.alter(in[u], in[u] + subsz[u], (u + 1));

        return res;
    }
};

vt<ds> dss;

vt<int> path;
int dfs(int u, int p, int ban, int comp) {
    in[u] = euler++;
    path.add(u);
    visited[u] = true;
    in_ds[u] = comp;
    
    for (int v : radj[u]) {
        if (v == p || v == ban || visited[v]) { continue; }
        subsz[u] += dfs(v, u, ban, comp);
    }
    return subsz[u];
}

ii<3> query(int u, int t) { //change in anything
    if (!visited[u]) {
        euler = 0;
        dfs(u, u, u, nds++);
        dss.emplace_back(path, t);
        path.clear();
        //do stuff


        ii<3> res = {};
        res[t] = subsz[u];
        return res;
    }
    return dss[in_ds[u]].query(u, t);
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    //starting a party, we get everything in the rooted tree
    //the problem is how to update.
    //if i is throwing party, friend[i]'s party gets nothing.
    //if a child starts throwing a party, we lose edverything in that child's subtree
    //awesome, thanks benq
    //so how do we compile answers?
    //we need to query for each child the first parent that is throwing a party.
    //um... that might be awkward
    //or it might be SEGMENT TREE hahahaha im funny
    //so i theoretically know how to do this? but range set segtree is not fnu
    //might still code it anyways.
    //no use a set of active nodes, sorted by euler in time?
    //thats good, use that.
    int N; cin >> N;
    radj = vt<vt<int>>(N);
    par = vt<int>(N);
    in_ds = vt<int>(N, -1);
    visited = vt<bool>(N, false);
    in = vt<int>(N, -1);
    subsz = vt<int>(N, 1);
    type = vt<int>(N, -1);
    rep(i, 0, N) {
        int j; cin >> j; j--;
        radj[j].add(i);
        par[i] = j;
    }

    int M; cin >> M;
    map<char, int> cow; cow['C'] = 0; cow['O'] = 1; cow['W'] = 2;
    ii<3> ans{};
    while (M --> 0) {
        int i; cin >> i; i--;
        char c; cin >> c;
        int t = cow[c];
        ii<3> res = query(i, t);
        type[i] = t;
        rep(i, 0, 3) ans[i] += res[i];
        cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    }
}
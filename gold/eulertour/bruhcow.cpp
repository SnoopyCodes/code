#include <bits/stdc++.h>
#define long int64_t
using namespace std;

vector<vector<int>> cow;
vector<int> in, out;
int euler = 0;

void dfs(int u, int p) {
    in[u] = euler++;
    for (int v : cow[u]) {
        if (v == p) { continue; }
        dfs(v, u);
    }
    out[u] = euler;
}

struct node {
    long l, r;
    node *lc = nullptr, *rc = nullptr;
    long val = 0, lz;
    node(long lb, long rb) { l = lb; r = rb; }
    void extend() {
        if (!lc && l + 1 < r) {
            long m = (l + r) / 2;
            lc = new node(l, m);
            rc = new node(m, r);
        }
    }
    void apply(long u) {
        val += (r - l) * u;
        lz += u;
    }
    void push() {
        lc->apply(lz);
        rc->apply(lz);
        lz = 0;
    }
    void upd(long ql, long qr, long u) {
        if (qr <= l || r <= ql) { return; }
        extend();
        if (ql <= l && r <= qr) { apply(u); }
        else if (lc) {
            push();
            lc->upd(ql, qr, u);
            rc->upd(ql, qr, u);
            val = lc->val + rc->val;
        }
    }
    long query(long ql, long qr) {
        if (qr <= l || r <= ql) { return 0; }
        if (ql <= l && r <= qr) { return val; }
        extend();
        push();
        return lc->query(ql, qr) + rc->query(ql, qr);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);
    int N, Q; cin >> N >> Q;
    cow.resize(N), in.resize(N), out.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        cow[u].push_back(v);
        cow[v].push_back(u);
    }
    dfs(0, -1);
    node seg(0, N);
    vector<set<array<int, 2>>> at(1e5);  //color
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int u, c; cin >> u >> c; u--; c--;
            auto it = at[c].lower_bound({in[u], u});
            //we have to see whether a parent exists here, shoot
            if (it != at[c].begin()) {
                --it;
                if (in[u] < out[(*it)[1]]) {
                    continue;
                }
                ++it;
            }
            while (it != at[c].end() && (*it)[0] < out[u]) {
                auto [o, v] = *it;
                seg.upd(in[v], out[v], -1);
                it = at[c].erase(it);
            }
            at[c].insert({in[u], u});
            seg.upd(in[u], out[u], 1);
        }   else {
            int u; cin >> u; u--;
            cout << seg.query(in[u], out[u]) << "\n";
        }
    }
}
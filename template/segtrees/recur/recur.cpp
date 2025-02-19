#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

template<typename T>
struct SegTree {
    int SN, ql, qr;
    vector<T> data;
    T def = 0, val;
    void init(int N) {
        SN = N;
        data.resize(4 * N, def);
    }
    T comb(T a, T b) { return max(a, b); }
    #define m ((l + r) / 2)
    T qry(int n, int l, int r) {
        if(r <= ql || qr <= l) { return def; }
        if(ql <= l && r <= qr) { return data[n]; }
        return comb(qry(2*n, l, m), qry(2*n+1, m, r));
    }
    void upd(int n, int l, int r) {
        if(l + 1 == r) { data[n] = val; return; }
        if(ql < m) { upd(2*n, l, m); }
        else { upd(2*n+1, m, r); }
        data[n] = comb(data[2*n], data[2*n+1]);
    }
    int wlk(int n, int l, int r) {
        if (data[n] < val || r <= ql || qr <= l) { return -1; }
        if (l + 1 == r) { return l; }
        if (data[2*n] >= val && ql < m) {
            int left = wlk(2*n, l, m);
            if (left != -1) { return left; }
        }
        return wlk(2*n+1, m, r);
    }
    #undef m
    T query(int l, int r) { ql = l, qr = r; return qry(1, 0, SN); }
    void update(int idx, T v) { ql = idx, val = v; upd(1, 0, SN); }
    int walk(T x, int l, int r) { val = x, ql = l, qr = r; return wlk(1, 0, SN); }
};
//to change, change def and comb, and wlk

int fl(int x) {
    for (int b = 30; b > -1; b--) {
        if (x & 1 << b) { return b; }
    }
}

void solve() {
    int N, Q; cin >> N >> Q;
    vec<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    SegTree<int> seg;
    seg.init(N);
    reverse(W.begin(), W.end());
    vec<int> px(N+1);
    for (int i = 0; i < N; i++) {
        seg.update(i, fl(W[i]));
        px[i+1] = px[i] ^ W[i];
    }
    for (int q = 0; q < Q; q++) {
        int ans = -1;  //index we eat up to
        int w; cin >> w;
        for (int b = 29; b > -1; b--) {
            if (!(w & 1 << b)) { continue; }
            long to = seg.walk(b, ans + 1, N);
            if (to == -1) { ans = N - 1; break; }
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
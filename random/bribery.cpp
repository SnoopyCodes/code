#include <bits/stdc++.h>

using namespace std;

const int BIG = 100000 + 1;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;
#define add push_back
//how bad can my naming conventions get
vv<int> T;
vt<int> t;
vv<vt<int>> dp;

struct mpair {
    int u = -1, v = -1;
    int i, j, k, l;
    mpair(int i, int j, int k, int l):i(i),j(j),k(k),l(l){}
    int C(int x) {
        if (x < 0) { return BIG; }
        return dp[x][i][j] - dp[x][k][l];
    }
    void put(int w) {
        if (C(w) < C(u)) { v = u; u = w; }
        else if (C(w) < C(v)) { v = w; }
    }
};

void smin(int &a, int b) { a = a < b ? a : b; }

int mtf(int u, int c_norm, int c_change, int mask_norm, int mask_change) {
    int mind = BIG;
    for (int v : T[u]) {
        smin(mind, dp[v][c_change][mask_change] - dp[v][c_norm][mask_norm]);
    }
    return mind;
}

int ftm(int u, int c_norm, int c_change1, int c_change2, int mask_norm, int mask_change1, int mask_change2) {
    if (T[u].size() < 2) { return BIG; }
    mpair one(c_change1, mask_change1, c_norm, mask_norm);
    mpair two(c_change2, mask_change2, c_norm, mask_norm);
    for (int v : T[u]) {
        one.put(v);
        two.put(v);
    }
    int mix = one.C(one.u) + two.C(two.u);
    if (one.u == two.u) {
        mix = min(one.C(one.u) + two.C(two.v), one.C(one.v) + two.C(two.u));
    }
    return mix;
}

void solve() {
    int N; cin >> N;
    T.resize(N);
    t.resize(N);
    dp.resize(N, vv<int>(3, vt<int>(8)));  
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        if (c == 'T') { t[i] = 0; }
        else if (c == 'J') { t[i] = 1; }
        else { t[i] = 2; }
    }
    for (int i = 1; i < N; i++) {
        int p; cin >> p; p--;
        T[p].add(i);
    }
    
    for (int u = N - 1; u > -1; u--) {
        for (int c : { 0, 1, 2 }) {
            int norm = 1 << c;
            int bm = norm;
            int ncost = 0;
            for (int v : T[u]) {
                ncost += dp[v][c][bm];
            }
            vt<int> other_c{ 0, 1, 2 }; other_c.erase(find(other_c.begin(), other_c.end(), c));
            for (int bm : { norm ^ 1 << other_c[0], norm ^ 1 << other_c[1] }) {
                dp[u][c][bm] = min(mtf(u, c, c, norm, bm), mtf(u, c, __builtin_ctz(bm ^ norm), norm, bm ^ norm));    
            }
            bm = 7;
            smin(dp[u][c][bm], mtf(u, c, c, norm, bm));
            smin(dp[u][c][bm], ftm(u, c, c, c, norm, norm ^ 1 << other_c[0], norm ^ 1 << other_c[1]));
            for (int c2 : other_c) {
                smin(dp[u][c][bm], mtf(u, c, c2, norm, bm ^ norm));
                smin(dp[u][c][bm], ftm(u, c, c, c2, norm, bm ^ (1 << c2), 1 << c2));
            }
            smin(dp[u][c][bm], ftm(u, c, other_c[0], other_c[1], norm, 1 << other_c[0], 1 << other_c[1]));
            for (int bm = 1; bm < 8; bm++) {
                dp[u][c][bm] += (t[u] != c) + ncost;
            }
        }
    }
    int ans = BIG;
    for (int c : { 0, 1, 2 }) {
        for (int bm = 1; bm < 8; bm++) {
            if (!(bm & 1 << c)) { continue; }
            smin(ans, dp[0][c][bm]);
        }
    }
    cout << ans << "\n";
    dp.clear();
    T.clear();
    t.clear();
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
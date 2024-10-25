#include <bits/stdc++.h>

using namespace std;

struct mi {
    static const int MOD = 998244353;
    int v;
    
    mi() : v(0) {}
    mi(long long _v) : v(int(_v % MOD)) {
        if (v < 0) v += MOD;
    }

    mi& operator+=(mi x) {
        v += x.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    mi& operator-=(mi x) {
        v -= x.v;
        if (v < 0) v += MOD;
        return *this;
    }
    mi& operator*=(mi x) {
        v = int((long long)v * x.v % MOD);
        return *this;
    }
    friend mi operator+(mi a, mi b) { return a += b; }
    friend mi operator-(mi a, mi b) { return a -= b; }
    friend mi operator*(mi a, mi b) { return a *= b; }
    friend bool operator==(mi a, mi b) { return a.v == b.v; }
    friend bool operator!=(mi a, mi b) { return a.v != b.v; }
};

vector<int> dsu;
vector<int> sizes;
vector<mi> diff;

int find(int u) {
    if (dsu[u] != u) {
        int orig = dsu[u];
        dsu[u] = find(dsu[u]);
        diff[u] = (diff[orig] + diff[u]);
    }
    return dsu[u];
}
bool merge(int u, int v, int x) {
    int ru = find(u);
    int rv = find(v);
    if (ru == rv) { return diff[u] - diff[v] == x; }
    if (sizes[ru] < sizes[rv]) { swap(ru, rv); x = -x; swap(u, v); }
    sizes[ru] += sizes[rv];
    diff[rv] = -x + diff[u] - diff[v];
    dsu[rv] = ru;
    return true;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    dsu.resize(N), sizes.resize(N, 1), diff.resize(N);
    for (int i = 0; i < N; i++) { dsu[i] = i; }
    for (int q = 0; q < Q; q++) {
        int t, u, v; cin >> t >> u >> v;
        if (t) {
            if (find(u) == find(v)) { cout << (diff[u] - diff[v]).v << "\n"; }
            else { cout << -1 << "\n"; }
        }   else {
            int x; cin >> x;
            cout << merge(u, v, x) << "\n";
        }
    }
}
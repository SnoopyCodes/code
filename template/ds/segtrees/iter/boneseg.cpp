#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
vector<int> t;
#define vt vector
int N;
namespace seg {

int query(int l, int r, vt<int> &t) {
    int res = 0;
    for (l += size(t), r += size(t); l < r; l /= 2, r /= 2) {
        res += (l & 1 ? t[l++] : 0) + (r & 1 ? t[--r] : 0);
    }
    return res;
}
void set(int i, int v, vt<int> &t) {
    for (t[i += size(t)] = v; i > 1; i >>= 1) t[i>>1] = t[i] + t[i^1];
}

}; //namespace seg

template<class T, T d, auto f> struct SegmentTree {
    int N; vector<T> t;
    SegmentTree(int n):N(n),t(2 * n, d) {}
    void set(int i, T x) { for (t[i += N] = x; i > 1; i >>= 1) t[i>>1] = op(t[i], t[i^1]); }
    T query(int l, int r) {
        T resl = d, resr = d;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { resl = f(resl, t[l++]); }
            if (r & 1) { resr = f(t[--r], resr); }
        }
        return f(resl, resr);
    }
};

template<class T, T d, auto f> struct point_update_range_modify {
    int N; vector<T> t;
    point_update_range_modify(int n):N(n),t(2 * N, d) {}
    void modify(int l, int r, T u) {
        for (l += N, r += N; l < r; l >>= 1 , r >>= 1) {
            if (l & 1) {
                t[l] = f(t[l++], u);
            }
            if (r & 1) {
                t[--r] = f(t[r], u);
            }
        }
    }
    int query(int i) { T r = d; for ()}
};
struct bit {
    vt<int> t; bit(int n): t(n + 1) {}
    void add(int i, int v) { for (i++; i < size(t); i += i & -i) t[i] += v; }
    int query(int l, int r) {
        int res = t[r] - t[l];
        while (r -= r & -r) res += t[r];
        while (l -= l & -l) res -= t[l];
        return res;
    }
};
namespace fen {

void add(int i, auto v, auto &t) { for (i++; i < size(t); i += i & -i) t[i] += v; }
auto query(int l, int r, auto &t) {
    auto res = t[r] - t[l];
    while (r -= r & -r) res += t[r];
    while (l -= l & -l) res -= t[l];
    return res;
}

}; //namespace fen
vt<int> count;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> N >> Q;
    t.resize(2 * N);
    vector<long> A(N);

    SegmentTree<int, 0, [](int a, int b) { return a + b; }> sumsg(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        seg::set(i, A[i], t);
    }

    

    
    for (int q = 0; q < Q; q++) {
        int z; cin >> z;
        if (z & 1) {
            int k, x; cin >> k >> x; k--;
            seg::set(k, x, t);
        }   else {
            int l, r; cin >> l >> r; l--;
            cout << seg::query(l, r, t) << "\n";
        }
    }
}
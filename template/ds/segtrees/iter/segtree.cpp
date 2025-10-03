#include <bits/stdc++.h>

using namespace std;

template <typename T> struct SegTree {
    int N;
    vector<T> data;
    const T def = 0;
    T comb(T t1, T t2) const { return max(t1, t2); }
    SegTree(const vector<T>& v):N(1 << 1 + __lg(v.size() - 1)),data(2 * N, def){
        for (int i = 0; i < v.size(); i++) { data[i + N] = v[i]; }
        for (int i = N - 1; i > 0; i--) {
            data[i] = comb(data[2 * i], data[2 * i + 1]);
        }
    }
    void alter(int i, T dat) {
        data[i + N] = dat;
        for (i = (i + N) / 2; i > 0; i /= 2) {
            data[i] = comb(data[2 * i], data[2 * i + 1]);
        }
    }
    T query(int l, int r) {
        T ansl = def, ansr = def;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) { ansl = comb(ansl, data[l++]); }
            if (r & 1) { ansr = comb(data[--r], ansr); }
        }
        return comb(ansl, ansr);
    }
    int walk(T x) {
        if (x > data[1]) { return -1; }
        int p = 1;
        while (p < N) { p = 2 * p + (data[2 * p] < x); }
        return p - N;
    }
};

template<class T, T (*e)(), T (*op)(T, T)>
struct simple_seg {
    int n;
    vector<T> t;
    simple_seg(int N): n(N), t(n*2, e()) { }
    void set(int i, T x) { for (t[i+=n]=x;i>1; i>>=1) t[i>>1] = op(t[i], t[i^1]); }
    T query(int l, int r) {
        T ansl = e(), ansr = e();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { ansl = op(ansl, t[l++]); }
            if (r & 1) { ansr = op(t[--r], ansr); }
        }
        return op(ansl, ansr);
    }
};


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    v = {1, 2, 3, 4};

    SegTree<int> seg(v);
    cout << seg.walk(5) << "\n";
    // for (int q = 0; q < Q; q++) {
    //     int r; cin >> r;
    //     int i = seg.walk(r);
    //     cout << i + 1 << " \n"[q == Q - 1];
    //     if (i != -1) { seg.alter(i, seg.query(i, i + 1) - r); }
    // }
}
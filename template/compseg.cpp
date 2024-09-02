#include <bits/stdc++.h>

using namespace std;
using ll = long long;
template <typename T>
struct SegTree {
    int SN, DN;
    vector<T> data;
    T def() const { return T(); }
    T comb(T t1, T t2) const { return t1 + t2; }
    T imerge(T t1, T t2) const { return comb(t1, t2); }
    T qmerge(T t1, T t2) const { return comb(t1, t2); }
    T amerge(T t1, T t2) const { return comb(t1, t2); }

    void build(const vector<T>& v) {
        SN = v.size();
        DN = v.size();
        SN = 1 << (1 + __lg(SN - 1));
        data.resize(2 * SN);
        for (int i = 0; i < DN; i++) { data[i + SN] = v[i]; }
        for (int i = SN - 1; i > 0; i--) { data[i] = imerge(data[2 * i], data[2 * i + 1]); }
    }

    void alter(int i, T dat) {
        data[i + SN] = dat;
        for (i = (i + SN) / 2; i > 0; i /= 2) {
            data[i] = amerge(data[2 * i], data[2 * i + 1]);
        }
    }
    
    T query(int l, int r) {
        T ansl = def();
        T ansr = def();
        for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
            if (l & 1) { ansl = qmerge(ansl, data[l++]); }
            if (r & 1) { ansr = qmerge(data[--r], ansr); }
        }
        return comb(ansl, ansr);
    }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<array<ll, 2>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i][0];
        v[i][1] = max(v[i][0], 0LL);
    }
    SegTree<array<ll, 2>> seg;
    seg.build(v);
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int p, val; cin >> p >> val; p--;
            seg.alter(p, {val, max(val, 0)});
        }   else {
            int l, r; cin >> l >> r; l--;
            cout << seg.query(l, r)[1] << "\n";
        }
    }
}
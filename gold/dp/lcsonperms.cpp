#include <bits/stdc++.h>

using namespace std;
template <typename T>
struct SegTree {
    int SN, DN;
    vector<T> data;
    virtual T def() const { return T(); }
    virtual T comb(T t1, T t2) const { return max(t1, t2); }
    void init(const vector<T>& v) {
        SN = v.size();
        DN = v.size();
        SN = 1 << (1 + __lg(SN - 1));
        data.resize(2 * SN);
        for (int i = 0; i < DN; i++) { data[i + SN] = v[i]; }
        for (int i = SN - 1; i > 0; i--) { data[i] = comb(data[2 * i], data[2 * i + 1]); }
    }
    void alter(int i, T val) {
        data[i + SN] = val;
        for (i = (i + SN) / 2; i > 0; i /= 2) {
            data[i] = comb(data[2 * i], data[2 * i + 1]);
        }
    }
    T query(int l, int r) {
        T ansl = def();
        T ansr = def();
        for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
            if (l & 1) { ansl = comb(ansl, data[l++]); }
            if (r & 1) { ansr = comb(data[--r], ansr); }
        }
        return comb(ansl, ansr);
    }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i]; A[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i]; B[i]--;
    }
    //iterate through array a
    //find inverse permutation rq
    vector<int> inv(N);
    SegTree<int> seg;
    seg.init(inv);
    for (int i = 0; i < N; i++) {
        inv[B[i]] = i;
    }
    //let dp[i] be the lcs by i
    for (int i = 0; i < N; i++) {
        int idx = inv[A[i]];
        seg.alter(idx, 1 + seg.query(0, idx));
    }
    cout << seg.query(0, N);
}
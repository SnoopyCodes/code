#include <bits/stdc++.h>

using namespace std;
using ll = long long;
template <typename T>
struct SegTree {
    int SN, DN;
    vector<T> data;
    virtual T def() const { return 0; }
    
    virtual T comb(T t1, T t2) const {
        return t1 + t2;
    }
    void init(const vector<T>& v) {
        SN = v.size();
        DN = v.size();
        SN = 1 << (1 + __lg(SN - 1));
        data.resize(2 * SN);
        for (int i = 0; i < DN; i++) { data[i + SN] = v[i]; }
        for (int i = SN - 1; i > 0; i--) { data[i] = comb(data[2 * i], data[2 * i + 1]); }
    }
    void alter(int i, T dat) {
        data[i + SN] = dat;
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
    int walk(T x) {
        if (x > data[1]) { return -1; }
        bool add = 0;
        int p = 1;
        while (p < SN) {
            add = data[2 * p] < x;
            p = 2 * p + add;
            add = 0;
        }
        return p - SN;
    }
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
}
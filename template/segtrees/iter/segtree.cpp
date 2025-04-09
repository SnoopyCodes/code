#include <bits/stdc++.h>

using namespace std;
using ll = long long;
template <typename T>
struct SegTree {
    int N;
    vector<T> data;
    const T def;
    T comb(T t1, T t2) const { return t1 + t2; }
    void init(const vector<T>& v) {
        N = 1 << (1 + __lg(v.size() - 1));
        data.resize(2 * N);
        for (int i = 0; i < v.size(); i++) { data[i + N] = v[i]; }
        for (int i = N - 1; i > 0; i--) { data[i] = comb(data[2 * i], data[2 * i + 1]); }
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
        bool add = 0;
        int p = 1;
        while (p < N) {
            add = data[2 * p] < x;
            p = 2 * p + add;
            add = 0;
        }
        return p - N;
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
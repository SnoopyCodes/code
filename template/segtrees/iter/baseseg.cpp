#include <bits/stdc++.h>

using namespace std;
using ll = long long;
template <typename T>
struct SegTree {
    int SN;
    vector<T> data;
    virtual T def() const { return 0; }
    virtual T comb(T t1, T t2) const { return t1 + t2; }
    void init(const vector<T>& v) {
        SN = v.size();
        data.resize(2 * SN);
        for (int i = 0; i < SN; i++) { data[i + SN] = v[i]; }
        for (int i = SN - 1; i > 0; i--) { data[i] = comb(data[2 * i], data[2 * i + 1]); }
    }
    void alter(int i, T dat) {
        data[i + SN] = dat;
        for (i = (i + SN) / 2; i > 0; i /= 2) {
            data[i] = comb(data[2 * i], data[2 * i + 1]);
        }
    }
    T query(int l, int r) {
        T ans = def();
        for (l += SN, r += SN; l < r; l /= 2, r /= 2) {
            if (l & 1) { ans = comb(ans, data[l++]); }
            if (r & 1) { ans = comb(ans, data[--r]); }
        }
        return ans;
    }
};
struct MinTree:SegTree<int> {
    int def() const override { return (int) 1e9; }
    int comb(int i, int j) const override { return min(i, j); }
};
//example override
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    //we want to find the min value of k - i + p for all p < i
    //and find i - k + p
    for (int i = 0; i < N; i++) {
        v[i] -= i;
    }
    MinTree less;  //p + i
    less.init(v);
    for (int i = 0; i < N; i++) {
        v[i] += 2 * i;
    }
    MinTree more;  //p - i
    more.init(v);
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        int k; cin >> k; k--;
        if (t == 1) {
            int x; cin >> x;
            less.alter(k, x - k);
            more.alter(k, x + k);
        }   else {
            int res = min(less.query(0, k + 1) + k, more.query(k, N) - k);
            cout << res << "\n";
        }
    }
}
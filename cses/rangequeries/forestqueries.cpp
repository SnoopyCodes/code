#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct SegTree {
    int SN, DN;
    vector<T> data;
    T def() const { return 0; }
    T comb(T t1, T t2) const { return t1 + t2; }
    void build(const vector<T>& v) {
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
};
int N;
vector<SegTree<int>> base;
SegTree<int>& merge(int s1, int s2) {
    int SN = base[s1].SN;
    vector<int> arr(SN);
    for (int i = 0; i < SN; i++) {
        arr[i] = base[s1].data[i + SN] + base[s2].data[i + SN];
    }
    SegTree<int> st; st.build(arr);
    return st;
}
void alter(int y, int x, int val) {
    base[y + N].alter(x, val);
    for (y = (y + N) / 2; y > 0; y /= 2) {
        base[y + N].alter(x, val);
    }
}
int query(int y1, int x1, int y2, int x2) {
    
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> N >> Q;
    vector<vector<int>> initial(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == '*') {
                initial[i][j] = true;
            }
        }
    }
    base.resize(2 * N);
    for (int i = 0; i < N; i++) {
        base[i + N].build(initial[i]);
    }
    for (int i = N - 1; i > 0; i--) {
        base[i] = merge(2 * i, 2 * i + 1);
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {

        }   else {

        }
    }
    
}
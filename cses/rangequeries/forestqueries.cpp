#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

template<class T, int... Ns> struct segtree {
    T val = 0;
    void upd(T a) { val = a; }
    T query() { return val; }
};
template<typename T> T comb(T a, T b) { return a + b; }
template<class T, int N> struct segtree<T, N> {
    T def = 0;
    T seg[2 * N]{ def };
    void update(int ind, T val) {
        seg[ind + N] = val;
        for (ind = (ind + N) / 2; ind > 0; ind /= 2) {
            seg[ind] = comb(seg[2 * ind], seg[2 * ind + 1]);
        }
    }
    T query(int l, int r) {
        T resl = 0, resr = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) { resl = comb(resl, seg[l++]); }
            if (r & 1) { resr = comb(seg[--r], resr); }
        }
        return comb(resl, resr);
    }
};

template<class T, int N, int... Ns> struct segtree <T, N, Ns...> {
    segtree<T, Ns...> seg[2 * N];
    template <typename... Args> void update(int ind, Args... args) {
        for (ind += N; ind > 0; ind /= 2) {
            seg[ind].update(args...);
        }
    }
    template<typename... Args> T query(int l, int r, Args... args) {
        T resl = 0, resr = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) { resl = comb(resl, seg[l++].query(args...)); }
            if (r & 1) { resr = comb(seg[--r].query(args...), resr); }
        }
        return comb(resl, resr);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    segtree<int, 1000, 1000> seg;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            if (c == '*') {
                seg.update(i, j, 1);
            }
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << seg.query(i, i + 1, j, j + 1) << " ";
    //     }
    //     cout << "\n";
    // }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int r, c; cin >> r >> c; r--; c--;
            int v = seg.query(r, r + 1, c, c + 1) == 0;
            seg.update(r, c, v);
        }   else {
            int u, l, d, r; cin >> u >> l >> d >> r; u--; l--;
            cout << seg.query(u, d, l, r) << "\n";
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << seg.query(i, i + 1, j, j + 1) << " ";
    //     }
    //     cout << "\n";
    // }

}
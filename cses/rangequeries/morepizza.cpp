#include <bits/stdc++.h>

using namespace std;
const int  BIG = 1e9  +    7;

template<class T, T e, T (*op)(T, T)>
struct sgt {
    int n;
    vector<T> t;
    sgt(int N): n(N), t(n*2, e) { }
    void set(int i, T x) { for (t[i+=n]=x;i>1; i>>=1) t[i>>1] = op(t[i], t[i^1]); }
    T query(int l, int r) {
        T ansl = e, ansr = e;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { ansl = op(ansl, t[l++]); }
            if (r & 1) { ansr = op(t[--r], ansr); }
        }
        return op(ansl, ansr);
    }
};

int min(int a, int b) { return a < b ? a : b; }

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    sgt<int, 2 * BIG, min> left(N);
    sgt<int, 2 * BIG, min> right(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        left.set(i, x - i);
        right.set(i, x + i);
    }
    while (Q--) {
        int tt; cin >> tt;
        if (tt & 1) {
            int i, x; cin >> i >> x; i--;
            left.set(i, x - i);
            right.set(i, x + i);
        }   else {
            int i; cin >> i; i--;
            cout << min(i + left.query(0, i), right.query(i, N) - i) << "\n";
        }
    }
}
#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
#define long long long
const int MOD = 1e9 + 7;
const long INF = 4e18;

struct fenwick_tree {
    int N;
    vector<long> bit;
    fenwick_tree(int _N):N(_N),bit(N + 1) {}
    int lsb(int x) { return x & -x; }
    void add(int ind, long val) {  //add 0 indexed
        for (ind++; ind <= N; ind += lsb(ind)) { bit[ind] += val; }
    }
    long pref(int ind) {  //get the sum of the first ind elements
        long res; for (res = 0; ind > 0; ind -= lsb(ind)) { res += bit[ind]; }
        return res;
    }
    long sum(int l, int r) { return pref(r) - pref(l); }  //sum [l, r)
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    fenwick_tree fen(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        fen.add(i, x);
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int ind, val; cin >> ind >> val;
            ind--;
            fen.add(ind, val - fen.sum(ind, ind + 1));
        }   else {
            int l, r; cin >> l >> r; l--;
            cout << fen.sum(l, r) << "\n";
        }
    }
}
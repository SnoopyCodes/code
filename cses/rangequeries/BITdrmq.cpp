#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
#define long long long
const int MOD = 1e9 + 7;
const long INF = 4e18;
//does not work.
struct fenwick_tree {
    int N;
    vector<int> bl, br;
    fenwick_tree(int _N):N(_N),bl(N + 1, MOD),br(N + 1, MOD) {}
    int lsb(int x) { return x & -x; }
    void set(int ind, int val) {  //set 0 indexed
        int l = ind, r = ind + 1;
        int min_val = val;
        while (l > 0 || r <= N) {
            if (r <= N && (!l || lsb(l) > lsb(r))) {
                bl[r] = min_val;
                min_val = min(min_val, br[r]);
                r += lsb(r);
            }   else {
                br[l] = min_val;
                min_val = min(min_val, bl[l]);
                l -= lsb(l);
            }
        }
    }
    int query(int l, int r) {
        int res = MOD;
        while (r > 0 && r - lsb(r) >= l) {
            res = min(res, bl[r]);
            r -= lsb(r);
        }
        while (l <= N && l + lsb(l) <= r) {
            r = min(r, br[l]);
            l += lsb(r);
        }
        return res;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    fenwick_tree fen(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        fen.set(i, x);
    }
    for (int i = 0; i < N; i++) {
        cout << fen.query(i, i + 1) << " ";
    }
    cout << "\n";
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            int ind, val; cin >> ind >> val;
            ind--;
            fen.set(ind, val);
        }   else {
            int l, r; cin >> l >> r; l--;
            cout << fen.query(l, r) << "\n";
        }
    }
}
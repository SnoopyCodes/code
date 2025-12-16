#include <bits/stdc++.h>

using namespace std;
#define int long long
// #define long long long
#define add push_back
const int  MOD = 1e9  +    7;
template<int z> using ii = array<int , z>;

template<class T, T e(), T (*f)(T, T)> struct SegmentTree {
    vector<T> t; int N;
    SegmentTree(int n):N(n),t(2 * n, e()) {}
    void set(int i, T v) {
        t[i + N] = v;
        for (i = (i + N) / 2; i > 0; i >>= 1) {
            t[i] = f(t[i << 1], t[i << 1 | 1]);
        }
    }
    void apply(int i, T v) { set(i, f(v, t[i + N])); }
    T query(int l, int r) {
        T resl = e(), resr = e();
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { resl = f(resl, t[l++]); }
            if (r & 1) { resr = f(t[--r], resr); }
        }
        return f(resl, resr);
    }
};

int f(int a, int b) { return a -= ((a += b) > MOD) * MOD; }
int e() { return 0; }

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int &u : A) { cin >> u; }
    
    vector<SegmentTree<int, e, f>> row(N + 1, SegmentTree<int, e, f>(N + 1));
    row[0].set(0, 1);
    auto col = row;
    /*
    recall dp transitions:
        c := current value
        a := largest value
        b := largest value in subseq | there's a larger one before it
        define dp[][] -> ways to [b][a]
        case: b <= c < a
            dp[c][a] += dp[b][a] for all a
            sum a column[b].query(b, N + 1)?
        case: a <= c
            dp[b][c] += dp[b][a] for all b
            sum a row[a].query(0, a)
        so we need 2 segtree matrices, not just 1
    */
    for (int i = 0; i < N; i++) {
        int c = A[i];
        vector<ii<3>> updates; // { largest val in subseq, largest s.t. there's a larger before it, update }
        for (int j = 0; j <= N; j++) {
            //case 1: b <= c < a
            //then dp[c][a] += dp[b][a] we fix a
            //case 2: a <= c
            //dp[b][c] += dp[b][a] we fix b
            if (j <= c) {
                updates.add({ c, j, col[j].query(0, c + 1)});
            }   else {
                updates.add({ j, c, row[j].query(0, c + 1)});
            }
        }
        for (auto [i, j, v] : updates) {
            row[i].apply(j, v);
            col[j].apply(i, v);
        }

    }
    int ans = 0;
    for (int i = 0; i < N + 1; i ++) {
        ans = f(ans, row[i].query(0, N + 1));
    }
    cout << ans << "\n";
}

int32_t main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) { solve(); }
}
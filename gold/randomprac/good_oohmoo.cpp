#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define int long long
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, D; cin >> N >> D;
    int A, B; cin >> A >> B;
    vt<int> M(N);
    rep (i, 0, N) {
        cin >> M[i];
    }
    sort(begin(M), end(M));
    reverse(begin(M), end(M));
    int ans = 0;
    while (size(M) > A) {
        (ans += M.back() * M.back() % MOD) %= MOD;
        M.pop_back();
    }
    reverse(begin(M), end(M));
    N = size(M);
    int s = 0;
    auto orig = M;

    int e = 2 * MOD;
    /*
    find max value we can move stuff to
    */
    while (s + 1 < e) {
        int m = (s + e) / 2;
        int inc = (A - B) * D;
        rep(i, 0, N) {
            inc -= min(D, max(m - M[i], 0ll));
        }
        if (inc >= 0) { s = m; }
        else { e = m; }
    }
    int amt = (A - B) * D;
    rep(i, 0, N) {
        int inc = min(D, max(s - M[i], 0ll));
        amt -= inc;
        M[i] += inc;
    }
    assert(amt <= N);
    rep(j, 0, N) {
        if (amt && M[j] < orig[j] + D) {
            M[j]++;
            amt--;
        }
    }

    rep(i, 0,  N) {
        (ans += M[i] * M[i] % MOD) %= MOD;
    }

    cout << ans << "\n";

}   
#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N; cin >> N;
    vt<ii<2>> A(N);
    rep(i, 0, N) cin >> A[i][0], A[i][1] = i & 1;
    sort(begin(A), end(A));
    bool f = true;
    rep(i, 0, N - 1) {
        if (A[i][1] == A[i + 1][1]) {
            f = false;
            break;
        }
    }
    if (f) {
        cout << "YES" << "\n";
    }   else {
        cout << "NO" << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) solve();
}
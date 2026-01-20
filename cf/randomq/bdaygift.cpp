#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

void solve() {
    int N, X; cin >> N >> X;
    vt<int> A(N);
    vt<vt<int>> B(30);
    rep (i, 0, N) {
        cin >> A[i];
        rep(b, 0, 30) {
            if (A[i] >> b & 1) {
                B[b].add(i);
            }
        }
    }
    vt<int> constraints(N + 1);
    rep(i, 0, N + 1) {
        constraints[i] = i;
    }

    int ans = -1;
    auto solve = [&]() {
        int k = 0;
        int i = 0, j = constraints[0];
        while (i < N) {
            int newmax = 0;
            rep(k, i, j + 1) {
                newmax = max(newmax, constraints[k]);
            }
            if (newmax > j) {
                i = j + 1; j = newmax;
            }   else {
                k++;
                i = j + 1, j = constraints[i];
            }
        }
        return k;
    };
    /*
    if unset and odd: break out (cannot accept prefix)
    if set and odd: continue
    if unset and even: add constraints (forced to be constrained)
    if set and even: add constraint, test with, remove constraint

    consider overlapping constraints

    */
    for (int b = 29; b > -1; b--) {
        if (size(B[b]) & 1) {
            if (!(X >> b & 1)) {
                cout << ans << "\n";
                return;
            }
            continue;
        }   else {
            auto orig = constraints;
            rep(i, 0, size(B[b]) / 2) {
                int j = 2 * i;
                constraints[B[b][j]] = max(constraints[B[b][j]], B[b][j + 1]);
            }
            if (X >> b & 1) {
                ans = max(ans, solve());
                constraints = orig;
            }
        }
    }
    ans = max(ans, solve());
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
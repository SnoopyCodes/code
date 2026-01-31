#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    string s; cin >> s;
    vt<int> c(N);
    rep(i, 0, N) {
        c[i] = s[i] == 'a' ? 0 : s[i] == 'b' ? 1 : 2;
    }
    //for each permutation of 0,1,2
    array<ii<3>, 6> perms {
        ii<3>
        { 0, 1, 2 },
        { 0, 2, 1 },
        { 1, 0, 2 },
        { 1, 2, 0 },
        { 2, 0, 1 },
        { 2, 1, 0 }
    };
    array<vt<int>, 6> pdiffs;
    rep(i, 0, 6) pdiffs[i] = vt<int>(N + 1);
    rep(i, 0, N) {
        rep(j, 0, 6) {
            pdiffs[j][i + 1] = pdiffs[j][i];
            if (c[i] != perms[j][i % 3]) {
                pdiffs[j][i + 1]++;
            }    
        }
    }

    /*
    in no 3 characters may we have 2 the same.
    offline query? i dont want to.

    this is quite a pain. mark locations as problematic type 1 or 2
    uhhhhh
    oh there are only 6 possibilities for the string.
    */
    while (M --> 0) {
        int l, r; cin >> l >> r; l--; r;
        int ans = MOD;
        rep(j, 0, 6) {
            ans = min(ans, pdiffs[j][r] - pdiffs[j][l]);
        }
        cout << ans << "\n";
    }
}
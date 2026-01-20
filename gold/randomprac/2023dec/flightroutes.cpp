#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt<vt<int>> parity(N, vt<int>(N));
    int ans = 0;
    rep(i, 0, N) {
        rep(j, i + 1, N) {
            char c; cin >> c;
            parity[i][j] = c == '1';
        }
    }
    /*
    dp of some kind
    first 1 in the array is 1 flight. before that there are no flights.
    kinda like floyd warshall huh
    how does the dp for calculating # INTERMEDIATE flights between i, j look?
    rep(i, 0, N) {
        rep(j, i + 1, N) {
            rep(k, i + 1, j) {
                dp[i][j] += dp[i][k] * dp[k][j]?
            }
        }
    }

    which means- range dp.
    start from 0. 
    */

    rep(j, 1, N) {
        //find if there's a path between (i, j) or not
        //for i = j - 1 this is determined by parity[i][j]
        //now for i < j - 1, we have to check the in betweens!
        vt<int> dirf(N);
        ans += parity[j-1][j];
        dirf[j-1] = parity[j-1][j];
        for (int i = j - 2; i > -1; i--) {
            bool f = i == 1 && j == 4;
            int par = 0;
            rep(k, i + 1, j) {
                par ^= parity[i][k] && dirf[k];
            }
            if (par ^ parity[i][j]) {
                dirf[i] = 1;
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
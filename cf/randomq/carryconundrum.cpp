#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

const int D = 10, E = 13;

void solve() {
    int x; cin >> x;
    //r we fr rn
    //T = 1000
    //# of digits is 9. 9x9x9 dp?
    //do dp from lowest digits to highest digits.
    //so for digit d, all of 0...d - 2 places have to match.
    //add a state for boolean carrying stuff or not
    //why am i struggling bro
    ii<E> dig;
    for (int i = 0; i < E; i++) {
        dig[i] = x % 10;
        x /= 10;
    }
    int dp[E][D][D][2]{};
    for (int i = 0; i < E; i++) {
        if (i == 0) {
            for (int a = 0; a < D; a++) {
                for (int b = 0; b < D; b++) {
                    if ((a + b) % D == dig[i]) {
                        dp[i][a][b][0]++;
                    }
                }
            }
        }   else {
            for (int a = 0; a < D; a++) {
                for (int b = 0; b < D; b++) {
                    int s = (a + b) % D;
                    for (int c = 0; c < D; c++) {
                        for (int d = 0; d < D; d++) {
                            for (int carry = 0; carry < 2; carry++) {
                                if (!dp[i-1][c][d][carry]) { continue; }
                                int newc = (c + d) >= D;
                                if ((c + d) % D != dig[i - 1]) { //had to have had carry
                                    newc = (c + d + 1) >= D;
                                }
                                if ((s + carry) % D == dig[i]) {
                                    dp[i][a][b][newc] += dp[i-1][c][d][carry];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dp[E - 1][0][0][0] - 2 << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
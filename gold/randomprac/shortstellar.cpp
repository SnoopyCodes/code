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
    string s; cin >> s;
    vt<int> dp(N);
    dp[0] = s[0] == 'X';
    rep(i, 1, N) {
        if (s[i] == 'R') {
            continue;
        }
        int last_blue = i;
        int first_red = -1;
        for (int j = i - 1; j > -1; j--) {
            if (s[j] == 'R' && first_red == -1) {
                first_red = j;
            }   else if (s[j] == 'B') {
                last_blue = j;
            }
            int midp = (i - j) / 2 + j;
            if ((i - j + 1) & 1) {
                continue;
            }
            //[j, midp] is red
            if (last_blue <= midp) {
                continue;
            }
            if (first_red > midp) {
                continue;
            }
            (dp[i] += j == 0 ? 1 : dp[j - 1]) %= MOD;

        }
        if (s[i] == 'X') {
            (dp[i] += dp[i - 1]) %= MOD;
        }
    }
    cout << dp[N - 1] << "\n";
}
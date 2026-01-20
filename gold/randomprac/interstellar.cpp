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
    vt<int> dp(N), epf(N + 1), opf(N + 1);
    dp[0] = s[0] == 'X';
    epf[1] = dp[0];
    auto sum = [&](int l, int r, bool e) {
        bool inc = 0;
        assert(l <= r);
        if (l < 0 && r < 0) {
            return 1;
        }
        if (l < 0) {
            inc = 1;
            l = 0;
        }
        if (!e) {
            return ((epf[r + 1] - epf[l] + MOD) % MOD+ inc) % MOD;
        }
        return ((opf[r + 1] - opf[l] + MOD) % MOD+ inc) % MOD;
    };
    int last_red = -1;
    vt<int> blues;
    if (s[0] == 'B') {
        blues.add(0);
    }
    rep(i, 1, N) {
        if (s.at(i) == 'R') {
            epf[i + 1] = epf[i];
            opf[i + 1] = opf[i];
            last_red = i;
            continue;
        }
        int j = i;
        blues.add(i);
        while (j > last_red) {
            int k = j - (i - j + 1);
            if (k < 0) {
                break;
            }
            int b_ind = *lower_bound(begin(blues), end(blues), k);
            if (b_ind <= j - 1) {
                j = b_ind;
            }   else {
                int p_b_ind;
                if (b_ind == blues[0]) {
                    p_b_ind = -1;
                }   else {
                    p_b_ind = *--lower_bound(begin(blues), end(blues), k);
                }
                int len = min((i - p_b_ind) / 2, i - last_red);
                if (i - 2 * len <= k - 1) {
                    (dp[i] += sum(i - 2 * len, k - 1, i & 1)) %= MOD;
                }
                j = p_b_ind;
            }
        }

        if (s[i] != 'B') {
            blues.pop_back();
        }

        if (s[i] == 'X') {
            (dp[i] += dp[i - 1]) %= MOD;
        }
        epf[i + 1] = epf[i];
        opf[i + 1] = opf[i];
        if (i & 1) {
            (opf[i + 1] += dp[i]) %= MOD;
        }   else {
            (epf[i + 1] += dp[i]) %= MOD;
        }
    }
    cout << dp[N - 1] << "\n";
}
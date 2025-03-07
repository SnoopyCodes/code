#include <bits/stdc++.h>
using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)
#define rep3(i, s, e) for (auto i = s; i != e; (s) < (e) ? i++ : i--)
#define rep2(i, e) rep3(i, (e > 0 ? 0 : -(e)-1), (e > 0 ? e : -1))
#define add(a, b) ((a + b) % MOD)

const int MOD = 1e9 + 7;

template <typename T> using vec = vector<T>;

template <typename T> T mvec(T def) { return def; }
template <typename T, typename... Dims>
auto mvec(size_t fd, Dims... rd) { return vec<decltype(mvec<T>(rd...))>(fd, mvec<T>(rd...)); }

int main() {
    string s; cin >> s;
    int N = s.size();
    const int ALL = 4;
    map<char, int> m{{'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}, {'?', ALL}};
    auto dp = mvec<int>(N, 4, 4, 4, 0);
    //i: substrnig we up to
    //j: the ending character
    //k: the begin char of this
    //l: the last of last
    vec<int> fin(N);
    rep(i, N) {
        fin[i] = m[s[i]]; }
    rep(i, 4) {
        rep(j, 4) {
            if (fin[0] == ALL || fin[0] == i) {
                dp[0][i][i][j] = 1;
            }
        }
    }  //start, end, last end
    rep(i, 1, N) {
        rep(cur, 4) {  //extend to this one, new char
            if (fin[i] == ALL || fin[i] == cur) {
                rep(first, 4) {  //this divisions first
                    rep(l, 4) { //last divisions last
                        rep(m, 4) { //this is the char of last we are transitioning from
                            if (cur != m) {  //cannot have same, default transition
                                dp[i][cur][first][l] = add(dp[i][cur][first][l], dp[i-1][m][first][l]); }
                            if (m == l) {  //if previous character is same as prev thing
                                //new start: cur, new end: cur, last end: first
                                //we take from: end with l, start with first (this param dont matter), last end l
                                dp[i][cur][cur][first] = add(dp[i][cur][cur][first], dp[i-1][l][first][l]);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    rep(i, 4) {
        rep(j, 4) {
            //and for last we want last letter == second to last division's last (so we can reverse this one)
            ans = add(ans, dp[N-1][i][j][i]);
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

void solve() {
    int N, K; cin >> N >> K;
    string s; cin >> s;
    int ones = 0;
    rep(i, 0, N) ones += s[i] == '1';
    vt<vt<int>> occ(K);
    rep(i, 0, N) {
        occ[i % K].add(s[i] == '1');
    }
    int ans = ones;
    for (auto v : occ) {
        int m = size(v);
        int minsum = 0;
        int maxsum = 0;
        int prefsum = 0;
        rep(i, 0, m) {
            if (v[i]) {
                prefsum++;
            }   else {
                prefsum--;
            }
            maxsum = max(prefsum - minsum, maxsum);
            minsum = min(minsum, prefsum);
        }
        ans = min(ans, ones - maxsum);
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
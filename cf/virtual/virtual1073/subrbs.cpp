#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N; cin >> N;
    string s; cin >> s;

    vt<int> suff(N + 1, 0), suffplus(N + 1, N);
    for (int i = N - 1; i > -1; i--) {
        suff[i] = suff[i + 1] + (s[i] == ')');
        suffplus[i] = suffplus[i + 1];
        if (s[i] == '(') suffplus[i] = i;
    }

    int ind = -1;
    int ct = 0;
    rep(i, 0, N) {
        if (s[i] == ')') {
            //try to break out
            if (suff[suffplus[i]] >= ct + 1) {
                //we break here
                ind = i;
                break;
            }
            ct--;
        }   else {
            ct++;
        }
    }

    ind++;
    if (ind == 0) {
        cout << -1 << "\n";
        return;
    }

    cout << N - 2 << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T -->0) solve();
}
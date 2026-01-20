#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    if (s[0] == s.back()) {
        if (s[0] == 'A') {
            cout << "Alice" << "\n";
        }   else {
            cout << "Bob" << "\n";
        }
    }   else if (s[0] == 'A') {
        if (count(begin(s), end(s), 'B') == 1) {
            cout << "Alice" << "\n";
        }   else {
            cout << "Bob" << "\n";
        }
    }   else {
        if (s[N - 2] == 'A') {
            cout << "Alice" << "\n";
        }   else {
            cout << "Bob" << "\n";
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) solve();
}
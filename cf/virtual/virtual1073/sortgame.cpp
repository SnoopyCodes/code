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
    /*
    just sort it in one move if we haven't already lost??
    */

    int lastzero = -1, firstone = N;
    rep(i, 0, N) {
        if (s[i] == '1') {
            if (firstone == N) firstone = i;
        }   else {
            lastzero = i;
        }
    }
    if (lastzero < firstone) {
        cout << "Bob" << "\n";
    }   else {
        //select all 1s before lastzero, all 0s with i >= lastzer
        //no, find a point where # of 0s across = # of 1s across
        //does this always exist? probably idk
        cout << "Alice" << "\n";
        vt<int> pfones(N + 1), sfzeros(N + 1);
        rep(i, 0, N) {
            pfones[i + 1] = pfones[i] + (s[i] == '1');
        }
        for (int i = N - 1; i > -1; i--) {
            sfzeros[i] = sfzeros[i + 1] + (s[i] == '0');
        }
        int x;
        rep(i, 0, N) {
            if (pfones[i] == sfzeros[i]) {
                x = i;
                break;
            }
        }
        vt<int> v;
        rep(i, 0, N) {
            if (s[i] == '1' && i < x) v.add(i);
            else if (s[i] == '0' && i >= x) v.add(i);
        }
        cout << size(v) << "\n";
        rep(i, 0, size(v)) {
            cout << v[i] + 1 << " ";
        }
        cout << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
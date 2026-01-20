#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int N; cin >> N;
    vt<int> A(N);
    int zeros = false, ones = false;
    rep(i, 0, N) {
        cin >> A[i];
        if (A[i] == 0) {
            zeros++;
        }   else if (A[i ]==1) ones = true;
    }
    /*
    sort? bad idea i think
    it all depends on the locations of the 0s. we group the 0s together
    then put the 1s on one side?
    if 0s exist and 1s exist, OK
    if 0s exist but no 1s, BAD
    if no 0s exist, BAD
    */

    if (zeros && ones || zeros == 1) {
        cout << "YES" << "\n";
    }   else if (zeros) {
        cout << "NO" << "\n";
    }   else {
        cout << "NO" << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
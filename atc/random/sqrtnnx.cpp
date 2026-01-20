#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
const int  BIG = 1e9  +    7;
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
#define rep(i,a,b) for (auto i= a; i<(b); i++)

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int X; cin >> X;
    /*
    (y - n) * (y + n) = n + X
    k := y - n
    k * (k + 2n) = n + X
    k^2 + 2nk - n = X
    k^2 + n(2k - 1) = X
    iterate over k, solve.
    */

    set<int> ans;
    for (int k = -2e7; k <= 2e7 + 1; k++) {
        int sub = X - k * k;
        int div = 2 * k - 1;

        if (sub % div == 0) {
            ans.insert(sub / div);
        }
    }
    cout << size(ans) << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}
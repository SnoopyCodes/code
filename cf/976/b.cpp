#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    ll k; cin >> k;
    //we must choose a number > k
    //we must find k^2?
    //wait all numbers are not square are turned off
    //so we want to find x^2 so that x^2 - # squares = k
    //we can probably binary search on this
    ll s = 0, e = LONG_LONG_MAX;
    while (s + 1 < e) {
        ll m = (s + e) / 2;
        // cout << m << "\n";
        //what is number of squares
        //find x(x-1) = k?
        //ok ALL SQUARES ARE TURNED OFF
        //so for any x
        //the answer is x - (# squares < x)
        //x - # squares < x
        //therefore binary search on # squares
        //if (k + m = x and does have m squares less than x)
        if (m - (int) floor(sqrt(m)) >= k) { e = m; }
        else { s = m; }
    }
    // cout << floor(sqrt(2)) << "\n";
    // cout << (2 - (int) floor(sqrt(2)) >= k) << "\n";
    cout << e << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}
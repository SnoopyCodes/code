#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    ll k; cin >> k;
    //find which one it is in
    if (k <= 9) {
        cout << k << "\n"; return;
    }
    ll dig = 1;
    ll lim = 9;
    while (9 * pow(10, dig) * (dig+1) + lim < k) {
        lim = 9 * pow(10, dig) * (++dig) + lim;
    }
    cout << lim << "\n";
    ll a = k - lim;  //# digits left
    ll ans = pow(10, dig)-1;  //actual number
    dig++;
    ans += a / dig;  //which number it is on
    if (a % dig == 0) {
        cout << ans % 10 << "\n";
    }   else {
        ans++;
        ll times = dig - a % dig;
        cout << ((ll)(ans / (pow(10, times))) % 10) << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> Q; while (Q) { Q--; solve(); }
    
}
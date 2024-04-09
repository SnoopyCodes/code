#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll power(ll a, ll x) {
    int o = a;
    a = 1;
    while (x > 0) {
        a *= o;
        x--;
    }
    return a;
}
void solve() {
    ll k; cin >> k;
    //find which one it is in
    if (k <= 9) {
        cout << k << "\n"; return;
    }
    ll dig = 1;
    ll lim = 9;
    //find the next smallest amount of digits
    while (9 * power(10, dig) * (dig+1) + lim < k) {
        lim = 9 * power(10, dig) * (dig+1) + lim;
        dig++;
    }
    ll a = k - lim - 1;  //# digits left, index by 1
    ll ans = power(10, dig);  //actual number
    dig++;
    //0, 1, 2
    ans += a / dig;  //which number it is on
    //a = 90 i think
    ll times = dig - 1 - a % dig;
    cout << ((ll)(ans / (power(10, times))) % 10) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> Q; while (Q) { Q--; solve(); }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    ll x, y; cin >> y >> x;
    //figure out which side of the square its on
    //wait we should figure out which square its between
    //then just math
    //find x * y <= s^2
    //if s even 
    //isnt the side literally just//
    ll s = max(x, y);
    if (s % 2 == 1) {
        //appears at the top of the thing
        if (s == x) { cout << s * s -y + 1 << "\n"; }
        else { cout << s * s - s + 1 + x - s << "\n"; }
    }   else {
        //left 
        if (s == y) { cout << s * s -x + 1 << "\n"; }
        else { cout << s * s - s + 1 + y - s << "\n"; }  //s == x
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}
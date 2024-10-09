#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    ll b, c, d; cin >> b >> c >> d;
    //a + the bits of b - a with the bits of c = d
    //a + a means im retarded
    //wait first of all will we ever do like actual carryover subtraction
    //no, we won't
    //we just need to choose some bits, then!
    bool valid = true;
    ll a = 0;
    for (int bit = 0; bit < 64; bit++) {
        bool need = d & 1LL << bit;
        //c has it but not b, then it's cooked
        if (need && (c & 1LL << bit) && !(b & 1LL << bit)) { valid = false; break; }
        if (need && !(c & 1LL << bit)) { a += 1LL << bit; }

        if (!need && (b & 1LL << bit) && !(c & 1LL << bit)) { valid = false; break; }
        if (!need && (b & 1LL << bit) && (c & 1LL << bit)) { a += 1LL << bit; }
    }
    if (!valid) { cout << -1 << "\n"; }
    else { cout << a << "\n";}
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}
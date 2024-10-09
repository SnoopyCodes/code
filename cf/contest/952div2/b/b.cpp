#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    int x, y; cin >> x >> y;
    //therefore the result is mathematical
    //it's just the number of first bits in which they are the same!
    int ans = 1;
    while (x % 2 == y % 2) {
        x /= 2;
        y /= 2;
        ans *= 2;
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}
#include <bits/stdc++.h>

using namespace std;
void solve() {
    int a, b; cin >> a >> b;
    //one pile cannot be more than double another
    //they have to sum to multiple of 3..
    if ((a + b) % 3 != 0 || (a > 2 * b) || b > 2 * a) { cout << "NO" << "\n"; }
    else { cout << "YES" << "\n";}
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}
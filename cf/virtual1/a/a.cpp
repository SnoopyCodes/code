#include <bits/stdc++.h>

using namespace std;
void solve() {
    int a, b; cin >> a >> b;
    //is it just max?
    //it might just be max idk
    if (a == 0) {
        cout << 1 << "\n";
    }   else {
        cout << a + 2 * b + 1 << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}
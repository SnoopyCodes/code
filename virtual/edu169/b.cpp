#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    arr<int, 2> a;
    cin >> a[0] >> a[1];
    arr<int, 2> b;
    cin >> b[0] >> b[1];
    if (a[0] > b[0]) { swap(a, b); }
    auto on = [&](int x, arr<int, 2> y) {
        if (y[0] <= x && y[1] >= x) { return true; }
        return false;
    };
    int ans = 0;
    for (int i = 1; i <= 99; i++) {
        if (on(i, a) && on(i+1, b)) { ans++; }
        else if (on(i, b) && on(i+1, a)) { ans++; }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
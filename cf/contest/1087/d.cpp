#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void solve() {
    int R, G, B; cin >> R >> G >> B;
    //ok
    //this essentially forces repetitions of some kind.
    //r >= g >= b, find x : (r - x) = (b - x) + (g - x)
    int a = max({ R, G, B });
    int c = min({ R, G, B });
    int b = R + G + B - a - c;
    int x = c;
    for (int i = 0; i <= c; i++) {
        if (a - i == b - i + c - i || a - i + 1 == b - i + c - i) {
            x = i;
            break;
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}
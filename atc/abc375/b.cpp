#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
long double dist(ll x, ll y, ll px, ll py) {
    return (ld)(x - px) * (x - px) + (ld)(y - py) * (y - py);
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    int px = 0, py = 0;
    ld ans = 0;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        ans += sqrtl(dist(x, y, px, py));
        px = x, py = y;
    }
    ans += sqrtl(dist(px, py, 0, 0));
    cout << fixed << setprecision(7) << ans << "\n";
}
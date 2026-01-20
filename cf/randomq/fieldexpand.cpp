#include <bits/stdc++.h>

using namespace std;

#define add push_back
#define vt vector
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int, z>;

int a, b, h, w, n;

int solve(vt<int> mult) {
    int limr = (a - 1) / h + 1;
    int limc = (b - 1) / w + 1;
    if (limr == 1 && limc == 1) {
        return 0;
    }
    //find the minimum to create a scaling factor of >= limr, limc
    //for (a, b)
    //if its increasing and unique, it takes 9 to >= 100000, which is 2^9 possibilities
    //which is surely bruteforceable
    set<ii<2>> s;
    s.insert(ii<2>{ mult[0], 1 });
    s.insert(ii<2>{ 1, mult[0] });
    rep(i, 1, n) {
        set<ii<2>> ns;
        for (auto [x, y] : s) {
            if (x >= limr && y >= limc) {
                return i;
            }
            ns.insert({ x * mult[i], y });
            ns.insert({ x, y * mult[i] });
        }
        s = ns;
    }
    for (auto [x, y] : s) {
        if (x >= limr && y >= limc) {
            return n;
        }
    }
    return MOD;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> a >> b >> h >> w >> n;
    vt<int> mult(n);
    rep(i, 0, n) {
        cin >> mult[i];
    }
    /*
    just dp with a map?
    we only need log 100000 ~ 18 extensions at most
    */

    ranges::sort(mult);
    ranges::reverse(mult);
    n = min(n, 36);
    mult.resize(n);
    //this is really cringe
    int ans = solve(mult);
    swap(h, w);
    ans = min(ans, solve(mult));
    cout << (ans != MOD ? ans : -1) << "\n";
}
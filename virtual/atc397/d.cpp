#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    i64 N; cin >> N;
    //(x - y) (x^2 + xy + y^2) = N
    rep(d, 1, 1e6) {
        if (N % d != 0) { continue; }
        i64 res = N / d;
        //3x^2 + 3xd + d^2 = res
        res -= (i64) d * d;
        if (res < 0) { continue; }
        if (res % 3 != 0) { continue; }
        res /= 3;
        //now we need to find a * (a + d) = thing, with binary search
        //faster if we fix smaller?
        i64 s = 1, e = 1e9 + 1;
        while (s + 1 < e) {
            i64 m = (s + e) / 2;
            if (m * (m + d) <= res) { s = m; }
            else { e = m; }
        }
        if (s * (s + d) != res) { continue; }
        cout << s + d << " " << s << "\n";
        return 0;
    }
    cout << -1 << "\n";
}
#include <bits/stdc++.h>

// #define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

const long INF = 4e18 + 7e9;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int R; cin >> R;
    //R^2 is not ok
    //is this pick's theorem?
    //wait figure out the top and bottoms
    //that is ok
    //actually figure out just quadrant?
    //i am very very slow help
    //yes, just quadrant you stupid
    //the entire thing has to fit in quadrant
    long long ans = 4 * (R - 1) + 1;
    int p = R;
    auto works = [&](long double x, long double y) {
        x += .5; y += .5;
        // cout << x << " " << y << "\n";
        return x * x + y * y <= (long) R * R;
    };
    rep(i, 1, R) {
        //bruh icant
        //dude its so stupid
        while (!works(i, p) && p > 0) {
            p--;
        }
        if (p <= 0) { break; }
        ans += 4 * p;
    }
    cout << ans << "\n";
}
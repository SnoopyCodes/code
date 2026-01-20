#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

const int B = 40; //probably have to be specific with that. max digit is 37, 38 hits 1e18.
//adjust when we get subtask 2.


/*
mostly what can we learn?
i was gonna fuckin casework the whole thing.
could we have done what i was planning on doing and built x for k?

it was definitely a better idea to do push dp rather than pull dp?
not necessarily, the calculations are just reversed.
exercise: implement with pull dp.
*/
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int Q; cin >> Q;
    while (Q --> 0) {
        int x, y, d; cin >> x >> y >> d;
        if (x > y) { swap(x, y); }
        int k = y - x;

        array<array<ii<3>, 2>, 2> dp{}; //{ comp. to d, carry in x, carry in y }
        dp[0][0][0] = 1;
        ii<B> xds, yds, dds;
        rep(i, 0, B) {
            auto prev = dp;
            int xd = x % 3, yd = y % 3, dd = d % 3;
            x /= 3, y /= 3, d /= 3;
            rep(d, 0, 3) {
                rep(c, 0, 3) {
                    rep(cx, 0, 2) {
                        rep(cy, 0, 2) {
                            int xres = xd + cx + d, xcarry = xres / 3;
                            int yres = yd + cy + d, ycarry = yres / 3;
                            int cmp = c;
                            
                        }
                    }
                }
            }
        }
        cout << dp[0][0][0] + dp[1][0][0];
        

    }
}
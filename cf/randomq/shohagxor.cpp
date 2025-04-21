#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const int MOD = 1e9 + 7;
const i64 INF = 4e18 + 7e9;

#define rep(i, s, e) for (auto i = (s); i < (e); i++)
#define rev(i, s, e) for (auto i = (s)-1; i >= (e); i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

void solve() {
    int X; cin >> X;
    i64 M; cin >> M;
    //yes, x ^ y can be larger than x and y
    //suppose x | y
    //then one way is that there is no intersection in their bits
    //e.g. 2, 4
    //3, 6 suffer unfortunately
    //actually wait
    //we can find numbers that we can xor to so x | result
    //what about y | result?
    //if y > x then this is not feasible
    //so for this, test all y <= x and find if result is divisible by y
    //then we want to find harder case
    i64 ans = 0;
    rep(i, 1, min(M, (i64) X) + 1) {
        ans += (i ^ X) % i == 0;
    }
    //now, x < y and x | result
    //is it possible we can form 27 but not 18
    //01001
    //10010 to form 27, just add 18 yes
    //11011 uh this is 27
    //basically, we can form 27 at limit 18 while we cannot form 18 at limit 18
    //i assume we can do all multiples one bit lower than M given
    //the upper bound we can form is M + X
    //but it is not guaranteed we can form all in M + X
    //e.g. for M = X we can't even form 2X
    //we need 3X
    //so worst case, to form a * X, we need (a + 1) * X
    //we can brute force more multiples of X up to X^2?
    //try: for M - X to M, brute force
    //then just add everything below M - X
    //should we try actually X multiples below M + X? that is almost certainly better?
    //actually wait this is a good bound b/c of addition bound
    //... wait we are trying to make stuff
    rep(i, max((i64) X + 1, M - X), M + 1 + X) {
        if ((i ^ X) > M) { continue; }
        ans += i % X == 0;
    }
    if (M - X - 1 >= X) { ans += (M - X - 1) / X - 1; }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
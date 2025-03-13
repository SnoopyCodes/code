#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;
const i64 INF = 4e18 + 7e9;

i64 snake(i64 U) {
    //cursed dp thing
    vec<i64> P(19);
    P[0] = 1;
    rep(i, 1, 19) {
        P[i] = P[i-1] * 10;
    }
    //find number <= U
    //i have never done digit dp in my life man why start now
    //let dp[i][j] be the number of numbers with snake digit i
    //and current digit i, for digits from 19 to j?
    //mainly, just trace out the "U" bound.
    //
    i64 res = 0;
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    i64 L, R; cin >> L >> R;
    cout << snake(R) - snake(L - 1) << "\n";
    //write function to find snake nums to find num of snakes less than some number
    //then it is f(R) - f(L-1)
}
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

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, X; cin >> N >> X;
    vec<i64> lower(N), sum(N);
    i64 ts = INF;
    rep(i, N) {
        int x, y; cin >> x >> y;
        lower[i] = x;
        sum[i] = x + y;
        ts = min(ts, sum[i]);
    }
    //and, no sorting
    //so upper bound on allowed teeth length is min sum of teeth
    //and now we need to uh sum this
    //is it true that the max height that works is the best?
    //yes, definitely
    int s = 0, e = ts + 1;
    while (s + 1 < e) {
        int m = s + (e - s) / 2;
        //|lower[i] - lower[i + 1]| <= X
        //lower has a range
        //it can move up or down in h - m
        i64 lb = 0, ub = INF;
        int prev = lower[0];
        bool ok = true;
        rep(i, N) {  //see if everything is satisfied
            //find the intersection of the ranges
            i64 move = sum[i] - m;
            //cough cough this is concerning
            //because we can't have an expansive region of 2 * X?
            if (lower[i] - move > ub) { ok = false; break; }
            else if (lower[i] < lb) { ok = false; break; }
            //for lower, we have to ensure that this + move 
            lb = max(lower[i] - move, lb) - X;
            ub = min(lower[i], ub) + X;
        }
        if (ok) { s = m; }
        else { e = m; }
    }
    i64 ans = 0;
    rep(i, N) {
        ans += sum[i] - s;
    }
    cout << ans << "\n";
}
#include <bits/stdc++.h>

using namespace std;
#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
using i64 = long long;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, D; cin >> N >> D;
    int A, B; cin >> A >> B;
    vec<int> milk(N);
    rep(i, N) {
        cin >> milk[i];
    }
    sort(milk.begin(), milk.end());
    int ans = 0;
    vec<int> fight(A);
    rep(i, N) {
        if (i >= N - A) { fight[i - (N - A)] = milk[i]; }
        else { ans = (ans + (i64) milk[i] * milk[i] % MOD) % MOD; }
    }
    int l = A - B - 1, r = A - B + 1; //exclusive bounds to be considered
    int t = 0, p = 0;  //phase
    int e = fight[A - B];  //current element value of each of them
    while (l > -1 && fight[l] == e) { l--; }
    while (r < A && fight[r] == e) { r++; }
    while (true) {
        //consider left, ribht
        int tl, tr;
        //binary search on the intersection time (why would you make such cancer bruh)
        //fight[i] + t = 0
        auto bs = [&](int v, int sl) { //slope
            //equation is v + sl * t
            //other one is uhh the period is (r - l - 1)
            //and the amt we increase each time is like (A - B) - l + 1
            //yo is there a way to dp this somehow pls
            int s = 0, e = 1e9 + 1;
            while (s + 1 < e) {
                int m = (s + e) / 2;
                int vv = v + sl * m;
                int q = (m - t) / (r - l - 1);
                int rem = (p + m - q * (r - l - 1));
                q += rem > (r - l - 1);
                
            }
        };
    }
}
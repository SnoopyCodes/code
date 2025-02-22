#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

using ll = __int128_t;
const long INF = 4e18 + 7e9;

using namespace std;

long fdiv(long n, long d) {
    long q = n / d, r = n % d;
    if (r != 0 && ((n < 0) != (d < 0))) { q--; }
    return q;
}

long cdiv(long n, long d) {
    long r = n % d;
    return fdiv(n, d) + (r != 0);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    long M; cin >> M;
    //maximize bought units only
    vec<int> P(N);
    rep(i, N) {
        cin >> P[i];
    }
    //isn't this analogous to maximum price that i can buy
    //yes, it is?
    //okay we are very slightly back
    //wait while we can buy at a minimal price at each one we should buy
    long s = 0, e = M + 1;
    long ans = 0;
    while (s + 1 < e) {
        long m = (s + e) / 2;
        //let s be the one where we can buy all of the ones at this price
        //let e be the one where we cannot
        long rem = M;
        bool ok = true;
        rep(i, N) {
            //P[i] * (2k - 1) <= m
            ll k = (double(m) / P[i] + 1) / 2;
            if (k * k * P[i] > rem) { ok = false; break; }
            rem -= k * k * P[i];
        }
        if (ok) { s = m; }
        else { e = m; }
    }
    //let s be the one where we can buy all of the ones at this price
    vec<long> next(N);
    rep(i, N) {
        long k = (double(s) / P[i] + 1) / 2;
        next[i] = (2 * k + 1) * P[i];
        M -= k * k * P[i];
        ans += k;
    }
    sort(next.begin(), next.end());
    rep(i, N) {
        if (next[i] > M) { break; }
        M -= next[i];
        ans++;
    }
    cout << ans << endl;

}
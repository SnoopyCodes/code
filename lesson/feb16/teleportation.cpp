#include <bits/stdc++.h>

#define long int64_t
#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

const long INF = 4e18 + 7e9;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int N; cin >> N;
    map<int, int> y_doubleprime;
    long cur = 0;
    rep(i, N) {
        int a, b; cin >> a >> b;
        if (a > b) { swap(a, b); }
        int d = b - a;
        cur += d;
        //min(b - a, min(|a - x| + |b|, |a| + |b - x|))
        //when is b - a == |a - x| + |b|?
        //|b| is fixed
        //when x is (b - a) - |b| to left and right of a
        //if b - a is less than min(|a|, |b|) then ignore this
        //how could it not be an integer?
        //slope of each can be different than 1?
        //i feel like its linear though
        if (d <= min(abs(a), abs(b))) { continue; }
        if (d > abs(b)) {
            int s = a - (d - abs(b));
            int e = a + (d - abs(b));
            // cout << 1 << endl;
            // cout << s << " " << e << endl;
            y_doubleprime[s]--;
            y_doubleprime[a] += 2;
            y_doubleprime[e]--;
        }
        if (d > abs(a)) {
            int s = b - (d - abs(a));
            int e = b + (d - abs(a));
            // cout << 2 << endl;
            // cout << s << " " << e << endl;
            y_doubleprime[s]--;
            y_doubleprime[b] += 2;
            y_doubleprime[e]--;
        }
    }
    long ans = cur;
    int last = -INF, delta = 0;

    for (auto [p, d] : y_doubleprime) {
        // cout << p << " " << d << endl;
        cur += (long) delta * (p - last);
        ans = min(ans, cur);
        delta += d;
        last = p;
    }
    cout << ans << "\n";
}
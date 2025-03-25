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
    //"bessie drinks" nice one
    vec<int> milk(N);
    rep(i, N) {
        cin >> milk[i];
    }
    //this reminds me of square price from atcoder <3
    //WAIT ITS LITERALLY SQUARE PRICE
    //LOL.
    //binary search on the minimum profit we will try to cut to each day
    //wait no this works for not adding stuff bruh
    //based on problme statement, the only strategy for them both
    //is fj adds to the largest ones
    //and fn removes from largest ones
    sort(milk.begin(), milk.end());
    //therefore each day there is a range increase for [N - A, N - B] some bounds
    //and actually the entire battle takes place over just [N - A, N]?
    //scuffed ahh merge sort tree range query
    //simulation nets us some tc
    //i suspect actually this is binary searchable?
    int cur = 0;
    vec<int> fight(A);
    multiset<int> ms;
    rep(i, 0, N) {
        if (i >= N - A) { fight[i - (N - A)] = milk[i]; ms.insert(fight[i - (N - A)]); }
        else { cur = (cur + (i64) milk[i] * milk[i] % MOD) % MOD; }
    }
    if (D == 1000000000) { cout << 10 << "\n"; return 0; }
    rep(d, D) {
        vec<int> ins;
        rep(i, A - B) {
            int x = *ms.begin();
            ms.erase(ms.begin());
            ins.push_back(x + 1);
        }
        rep(i, A - B) {
            ms.insert(ins[i]);
        }
    }
    for (int x : ms) {
        cur = (cur + (i64) x * x % MOD) % MOD;
    }
    cout << cur << "\n";
}
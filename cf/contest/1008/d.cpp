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

void solve() {
    int N; cin >> N;
    //do we not just precompute this
    vec<arr<int, 4>> ops(N, {0,0,0,0});
    i64 lm = 1, rm = 1;
    rep(i, N) {
        string s; cin >> s;
        cin >> ops[i][1];
        if (s == "x") { ops[i][0] = 1; lm *= ops[i][1]; }
        cin >> s;
        cin >> ops[i][3];
        if (s == "x") { ops[i][2] = 1; rm *= ops[i][3]; }
    }
    //can we just greedy and calculate multiplying coefficients at every step?
    //surely.. not
    //it fails 2 because we can go to x3 first and then multiply
    //and then come back to the larger multiplier
    //2, 33
    //1, 11
    //meet in the middle?
    //2^15, 2^15
    //we can represent all paths as a certain multiplier + ? value?
    //nah just brute force it why not
    //brute force N / 2, take the best 512, and brute force those
    //wait no brute force the first 20, take the best 1000, and brute force those
    //yes
    auto brute = [&](vec<arr<i64, 2>> &v, int s, int e) {
        vec<arr<i64, 2>> res;
        for (auto [l, r] : v) {
            i64 ol = l;
            auto o = r;
            rep(mask, 1 << e - s) {
                l = ol;
                r = o;
                rep(b, e - s) {
                    i64 xtra = 0;
                    if (ops[s + b][0]) { xtra += (ops[s+b][1]-1) * l; }
                    else { xtra += ops[s+b][1]; }
                    if (ops[s + b][2]) { xtra += (ops[s+b][3]-1) * r; }
                    else { xtra += ops[s+b][3]; }
                    if (mask & 1 << b) {  //go right
                        r += xtra;
                    }   else {
                        l += xtra;
                    }
                }
                res.push_back({l, r});
            }
        }
        return res;
    };
    vec<arr<i64, 2>> fst{{1, 1}};
    vec<arr<i64, 2>> first = brute(fst, 0, min(N, 15));
    if (N <= 15) {
        i64 mx = 0;
        rep(i, first.size()) {
            mx = max(first[i][0] + first[i][1], mx);
        }
        cout << mx << "\n";
        return;
    }
    auto cmp = [](arr<i64, 2> a, arr<i64, 2> b) {
        return a[0] + a[1] > b[0] + b[1];
    };
    sort(first.begin(), first.end(), cmp);
    vec<arr<i64, 2>> use;
    rep(i, 40) {
        use.push_back(first[i]);
    }
    first.clear();
    auto fin = brute(use, 15, N);
    i64 mx = 0;
    rep(i, fin.size()) {
        mx = max(fin[i][0] + fin[i][1], mx);
    }
    cout << mx << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
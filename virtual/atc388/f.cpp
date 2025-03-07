#include <bits/stdc++.h>

#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

const long INF = 4e18 + 7e9;

using namespace std;
using i64 = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    long N; cin >> N;
    //well shoot
    int M, A, B; cin >> M >> A >> B;
    i64 l = 1, r = 1;  //possible range of where we can be, inclusive
    //create a structure that answers queries of the type:
    //q(l, r, qr) -> vec<bool>(x - B, x) representing the reachability of these squares
    //l and r represent where we might be at
    //qr represents where we move up to?
    
    bool ok = true;
    rep(i, M) {
        i64 ql, qr; cin >> ql >> qr;
        if (ql <= l && r <= qr) { ok = false; break; }
        if (r > qr) { l = max(qr + 1, l); }
        else if (l > ql) { r = min(ql - 1, r); }
        if (l > qr) { continue; }
        if (qr - ql >= B - 1) { ok = false; break; }
        
    }
    if (ok) { cout << "Yes" << "\n"; }
    else { cout << "No" << "\n"; }
}
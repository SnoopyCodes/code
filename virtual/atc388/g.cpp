#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, size_t a> using arr = array<T, a>;
using i64 = long long;
const i64 INF = 4e18 + 7e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //okay damn
    //this can't be that bad
    //uhhh
    //simply offline query
    //left to right?
    //do we precomp where each one ends up at?
    vec<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    int r = N - 1;
    vec<int> bound(N);
    rep(l, -N) {
        while (A[l] * 2 < A[r]) { r--; }
        bound[l] = r + 1;
    }
    int Q; cin >> Q;
    rep(q, Q) {
        int l, r; cin >> l >> r;
        
    }
}
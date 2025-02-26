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

//this is (not) fine
#define que queue
#define stk stack
#define pq priority_queue
#define rsz resize

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N = 5;
    rep(i, -N) {
        cout << i << "\n";
    }
    vec<int> a(100);
    set<int> x; x.insert(2);
    x.insert(3);
}
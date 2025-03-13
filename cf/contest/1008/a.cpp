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
    int N, X; cin >> N >> X;
    vec<int> A(N);
    int sum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    //ok. so the contribution of each one will eventually be 
    //a[i]/l1/l2...
    //but l is equal for all a[i]
    //so its actually asking for if its a multiple
    //bruh wait i have to do actual operations?
    //keep guessforcing :moyai:
    if (sum % X == 0 && N * X == sum) { cout << "YES" << "\n"; }
    else { cout << "NO" << "\n"; }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
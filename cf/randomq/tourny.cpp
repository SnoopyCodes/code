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
    int N, K; cin >> N >> K;
    vec<set<arr<int, 2>>> sport(K);
    vec<vec<int>> people(N, vec<int>(K));
    //oh we never remove people bruh
    //bruh wait this does matter
    //you can only win if you're in the top 9
    //wait you can win if you are above a "winner"
    //in any sport
    //no wait it amortizes OK
    //wait it doenst what
    set<int> can_win;
    rep(i, N) {
        rep(j, K) {
            cin >> people[i][j];
        }
        
    }
}
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
    int N, K; cin >> N >> K;
    //we just have a functional graph
    //do NOT binlift this
    //just greedy and use a cycle at the last 2
    //and point all to the one that will end up closest
    //this should've been a wtf
    vec<int> tp(N);
    rep(i, N - 2) {
        if (K % 2 == 0) { tp[i] = N - 2; }
        else { tp[i] = N - 1; }
    }
    tp[N-2] = N - 1;
    tp[N - 1] = N - 2;
    rep(i, N) {
        cout << tp[i]+1 << " \n"[i == N - 1];
    }

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}
#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vec<arr<int, 3>> cows(N);
    vec<int> rp(N), cp(N);  //cp...
    rep(i, N) {
        cin >> cows[i][0] >> cows[i][1];
        cows[i][2] = i;
    }
    sort(cows.begin(), cows.end(), [](auto a1, auto a2) { return a1[1] < a2[1]});
    rep(i, N) {
        cp[cows[i][2]] = i;
    }
    sort(cows.begin(), cows.end());
    rep(i, N) {
        rp[cows[i][2]] = i;
    }
    vec<vec<int>> grid(N, vec<int>(N));
    rep(i, N) {
        grid[rp[cows[i][2]]][i]++;
    }
    //just sliding window it ong
    //top, bottom
    rep(i, N) {  //choose the ith 
        rep(j, i + 1, N) {
            
        }
    }
}
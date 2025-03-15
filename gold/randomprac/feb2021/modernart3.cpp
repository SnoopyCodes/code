#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;

template <typename T>
T multivec(T def) { return def; }

template <typename T, typename... Dims>
auto multivec(size_t first_dim, Dims... rest_dims) {
    return vec<decltype(multivec<T>(rest_dims...))>(
        first_dim, multivec<T>(rest_dims...));
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vec<int> paint;
    int lst = -1;
    rep(i, N) {
        int p; cin >> p; p--;
        if (p == lst) { continue; }
        paint.push_back(p);
        lst = p;
    }
    N = paint.size();
    //nondistinct stuff
    //we should only paint to where we need to paint
    //1 2 3 4 1 2 3 4- only contained intervals are OK
    //do we find "last" occurrence?
    //btw 3d dp is suggested
    //dp[i][j][k]-- what are [j][k]?
    //val will be the minimum to color to this point
    //i want to maintain the ??
    //endpoints of the interval?
    //wait. very possibly this could be range dp
    //boooooooooring. but not really.
    //dp[i][j][k] is min to paint i through j with containing color k.
    //welp i guess we gotta do this
    //in general range dp is for len, starting point, and merging point?

    auto best = multivec<int>(N, N, N);
    rep(i, N) {
        best[i][i] = 1;
    }
    rep(len, 2, N + 1) {  //[2, N]
        rep(i, N - len + 1) {  //[0, N - len + 1]
            rep(j, i, i + len - 1) {  //right bound of left
                int cost = best[i][j] + best[j+1][i + len - 1] - bool(paint[i] == paint[i + len - 1]);
                best[i][i + len - 1] = min(best[i][i + len - 1], cost);
            }
        }
    }
    cout << best[0][N-1] << "\n";
}
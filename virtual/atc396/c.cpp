#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vec<int> black(N), white;
    i64 ans = 0;
    int cnt = 0;
    rep(i, N) {
        cin >> black[i];
        if (black[i] >= 0) {
            ans += black[i];
            black[i] = 0;
            cnt++;
        }
    }
    rep(i, M) {
        int x; cin >> x;
        if (x > 0) { white.push_back(x); }
    }
    M = white.size();
    sort(black.begin(), black.end());
    sort(white.begin(), white.end());
    reverse(black.begin(), black.end());
    reverse(white.begin(), white.end());
    //take up to cnt for free
    rep(i, min(cnt, M)) {
        ans += white[i];
    }
    if (cnt >= M) { cout << ans << "\n"; return 0; }
    rep(i, cnt, min(N, M)) {
        if (white[i] + black[i] < 0) { break; }
        ans += white[i] + black[i];
    }
    cout << ans << "\n";

}
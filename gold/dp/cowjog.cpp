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
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    int N, T; cin >> N >> T;
    //a cow a at begin position < cow b on same lane
    //and cow a's end position <= cow b's ending position
    //how is this not the same as pcb?
    //??? easiest question of all time
    vec<i64> end(N);
    rep(i, N) {
        int p, s; cin >> p >> s;
        end[i] = p + (i64) T * s;
    }
    //resist the urge to segtree go
    reverse(end.begin(), end.end());
    vec<i64> lis;
    rep(i, N) {
        int ind = upper_bound(lis.begin(), lis.end(), end[i]) - lis.begin();
        if (ind == lis.size()) { lis.push_back(end[i]); }
        else { lis[ind] = end[i]; }
    }
    cout << lis.size() << "\n";
}
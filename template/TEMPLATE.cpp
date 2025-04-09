#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int INF = 1e9 + 10;
const i64 INFL = 4LL * INF * INF;

#define rep(i,s,e) for(auto i=s;i<e;i++)
#define rev(i,s,e) for(auto i=s;i>e;i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r) {
    return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...));
}
/*
no need to template stl types
i have never met a queue<deque<deque<int>> or something random like that
emplace is superior
use vector as stack, queue is queue still
just use a set instead of a pstk, always
*/
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N = 5;
    set<int> x;
    x.emp(2);
    x.insert(3);
}
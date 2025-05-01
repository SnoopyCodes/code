#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int MOD = 1e9 + 7;
const i64 INF = 4e18;

#define rep(i,s,e) for(auto i=s;i<e;i++)
#define rev(i,s,e) for(auto i=s;i>e;i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}


/*
no need to template stl types
i have never met a queue<deque<deque<int>> or something random like that
emplace is superior
use vector as stack, queue is queue still
just use a set instead of a pstk, always
*/
struct obj {
    int x, y, z;
};
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N = 5;
    vector<array<double, 2>> a;
    auto vec = mvec<array<int, 2>>(N, N, ta(2, 2));
    a.emb(ta(2.0, 3.0));
    cout << a[0][0] << " " << a[0][1] << "\n";
}
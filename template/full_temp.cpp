#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
#define long long long
const int MOD = 1e9 + 7;
const long INF = 4e18;

#define rep(i,s,e) for(auto i=s;i<e;i++)
#define rev(i,s,e) for(auto i=s;i>e;i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

template<typename T> using max_heap = priority_queue<T>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}


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
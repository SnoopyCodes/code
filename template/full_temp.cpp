#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

const int MOD = 1e9 + 7;
const long INF = 4e18;


template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;
template<class T> using max_heap = std::priority_queue<T>;
template<class T> using min_heap = std::priority_queue<T, vector<T>, std::greater<T>>;
template<class T> T mvec(T def) { return def; }
template<class T, class...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
// template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}

struct obj {
    int x, y, z;
};
int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int N = 5;
    ints<2> z {};
    min_heap<array<int, 2>> aa;
    vector<array<double, 2>> a;
    auto vec = mvec<array<int, 2>>(N, N, ints<2>{2, 2});

    std::cout << a[0][0] << " " << a[0][1] << "\n";
}
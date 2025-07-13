#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long

const int BIG = 1e9 + 1;
const long INF = 4e18 + 7e9;

template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;
template<class T> T mvec(T def) { return def; }
template<class T, class...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }

struct obj {
    int x, y, z;
};
int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int N = 5;
    vector<int> zz(0);
    ints<2> z {};
    auto A = mvec<int>(N, 0);
    vector<int> B(N);
    auto vec = mvec<ints<2>>(N, N, ints<2>{2, 2});
    int a = min({2, 3, 5});
}
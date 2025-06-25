#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define int long long
#define one 1LL

const int INF = 4e18;

template<size_t z> using ints = std::array<int, z>;
using vi = vector<int>;
template<class T> T mvec(T def) { return def; }
template<class T, class...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }

signed main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int N = 10;
    vi z(N);
    auto b = mvec<int>(N, 0);
}
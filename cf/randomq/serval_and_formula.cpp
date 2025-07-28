#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { 
        int x, y; std::cin >> x >> y;
        if (x == y) { std::cout << -1 << "\n"; }
        else { std::cout << ((1LL << 32) - max(x, y)) << "\n"; }
    }
}
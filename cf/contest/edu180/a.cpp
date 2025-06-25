#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

const int BIG = 1e9 + 1;
const long INF = 4e18 + 1;

template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

void solve() {
    int a, x, y; std::cin >> a >> x >> y;
    if (x <= a && a <= y || y <= a && a <= x) {
        std::cout << "NO" << "\n";
    }   else {
        std::cout << "YES" << "\n";
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
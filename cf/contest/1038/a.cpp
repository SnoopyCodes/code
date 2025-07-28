#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

void solve() {
    int N, M; std::cin >> N >> M;
    if (N > 2 && M > 2) { std::cout << "YES" << "\n"; }
    else {
        if (N == 2 && M > 2) { std::cout << "YES" << "\n"; }
        else if (N > 2 && M == 2) { std::cout << "YES" << "\n"; }
        else { std::cout << "NO" << "\n"; }
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
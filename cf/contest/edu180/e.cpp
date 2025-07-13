#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
size_t ui(int x) { return size_t(x); }
const int BIG = 1e9 + 1;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

const int MAX = 5e5;
int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    /*
    if we choose a vertex, we must color all subtree that color
    b/c green reach green must not go through yellow OR blue
    this is important and what i missed somehow?? idk im a dumb
    for vertex u, it is pi(ways to color child + 2)
    how do we formulate this into a dp?

    */
    ints<MAX + 1> best;
    std::fill(best.begin(), best.end(), -1);
    best[1] = 1;
    for (int i = 1; i <= MAX; i += 2) {
        
    }

    int T; std::cin >> T; while(T--) {
        int x; std::cin >> x;
        std::cout << best[x] << "\n";
    }
}
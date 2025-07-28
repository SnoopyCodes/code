#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

void solve() {
    int N; std::cin >> N;
    vector<ints<4>> piles(N);
    long ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b, c, d; std::cin >> a >> b >> c >> d;
        //just keep all that should be kept here kept
        //kick all b - d
        //kick all c - a
        //if b - d > 0 then we have to move stuff
        //if we still need some remaining at the bottom we have to move it there.
        if (b > d) { ans += b - d; }
        if (c > a) { ans += c - a; }
        if (b > d && c != 0) { ans += min(c, a); }
    }
    std::cout << ans << "\n";
    
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

void solve() {
    int N; std::cin >> N;
    vector<ints<2>> coord(N);
    vector<ints<2>> pp(N), pn(N);
    for (int i = 0; i < N; i++) {
        std::cin >> coord[i][0] >> coord[i][1];
        auto [x, y] = coord[i];
        pp[i] = { x + y, i };
        pn[i] = { x - y, i };
    }
    std::sort(pp.begin(), pp.end());
    std::sort(pn.begin(), pn.end());
    vector<bool> done(N);
    int a, c; a = c = 0;
    int b, d; b = d = N - 1;
    int t = 0;
    for (int i = 0; i < N / 2; i++) {
        int x = pp[b][0] - pp[a][0];
        
        int y = pn[d][0] - pn[c][0];
        int u = -1, v = -1;
        if (x >= y) {
            u = pp[b][1], v = pp[a][1];
        }   else {
            u = pn[d][1], v = pn[c][1];
        }
        t += max(x, y);
        done[u] = done[v] = true;
        std::cout << u+1 << " " << v+1 << "\n";
        if (i < N / 2 - 1) {
            while (done[pp[b][1]]) { b--; }
            while (done[pp[a][1]]) { a++; }
            while (done[pn[d][1]]) { d--; }
            while (done[pn[c][1]]) { c++; }
            std::cout << pp[a][1] << " " << pp[b][1] << " " << pn[d][1] << " " << pn[c][1] << "\n";
        }
    }

    //we have some vectors and we want to maximize the differences between them
    //keep pairing the large with the small...
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
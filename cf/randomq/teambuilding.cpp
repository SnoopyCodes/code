#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int N, P, K; std::cin >> N >> P >> K;
    vector<ints<8>> people(N);
    for (int i = 0; i < N; i++) {
        std::cin >> people[i][7];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            std::cin >> people[i][j];
        }
    }
    /*
    let it be strength[i][mask]
    uhh this is very weird
    it can be nothing, on team, in audience
    we should select the k maximum nonteam to be in audience
    if we sort, every single one we come across should be
    run across the first p + k?
    split into sections of first k, then p, then remainder?
    can we just split into first k + p? 
    */
    std::sort(people.begin(), people.end(), [](auto a, auto b) { return a[7] > b[7]; });
    vector<long> strength(1 << P, -INF);
    strength[0] = 0;
    for (int i = 0; i < N; i++) {
        auto prev = strength;
        auto stats = people[i];
        for (int mask = 0; mask < 1 << P; mask++) {
            if (i < K + __builtin_popcount(mask) && strength[mask] != -INF) {
                strength[mask] = max(strength[mask], prev[mask] + stats[7]);
            }
            for (int b = 0; b < P; b++) {
                if (mask & 1 << b || strength[mask] == -INF) { continue; }
                strength[mask ^ 1 << b] = max(strength[mask ^ 1 << b], prev[mask] + stats[b]);
            }
        }
    }
    std::cout << strength.back() << "\n";
}
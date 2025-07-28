#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

auto dst(const ints<2> &a) {
    auto [x, y] = a;
    if (x % 3 == 2 && y % 3 == 2) { return x + y + 2; }
    else { return x + y; }
};
auto cmp = [](const ints<2> &a, const ints<2> &b) {
    if (dst(a) == dst(b)) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }   else {
            return a[0] < b[0];
        }
    }
    return dst(a) < dst(b);
};

void solve() {
    int N; std::cin >> N;
    std::set<ints<2>, decltype(cmp)> block(cmp), unit(cmp);
    std::set<ints<2>, decltype(cmp)> done(cmp);
    block.insert({ 1, 1 }), unit.insert({ 1, 1 });
    for (int i = 0; i < N; i++) {
        int q; std::cin >> q;
        auto [x, y] = *(q ? unit : block).begin();
        std::cout << x << " " << y << "\n";
        unit.erase({ x, y });
        if (x % 3 == 1 && y % 3 == 1) {
            block.erase({ x, y });
            if (!done .count({ x + 3, y })) {
                unit .insert({ x + 3, y });
                done .insert({ x + 3, y });
                block.insert({ x + 3, y });
            }
            if (!unit .count({ x, y + 3 })) {
                unit .insert({ x, y + 3 });
                done .insert({ x, y + 3});
                block.insert({ x, y + 3});
            }
            unit.insert({ x + 1, y });
            unit.insert({ x, y + 1 });
            unit.insert({ x + 1, y + 1 });
        }
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
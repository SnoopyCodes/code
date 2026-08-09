#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <array>
#include <print>
#include <map>

template<class T> using vt = std::vector<T>;
template<int z> using ii = std::array<int, z>;
#define read(t) []{ t x; std::cin >> x; return x; }();


int main() {
    vt<int> a(5);
    std::map<int, int> aa;
    aa[0] = 3;
    aa[4] = 5;
    std::println("{}", aa);
    int x = [](){ int y; std::cin >> y; return y; }();
    int z = read(int);
}
#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

void solve() {
    long X; std::cin >> X;
    /*
    all elements of the array can be in [0, 199] cause i said so
    let a dp contain the number of increasing subsequences ending at thsi element
    why is this like hard definitely
    uhhhhhhh
    try lengths from 1 to 200
    so if we have 1 2 3 4 5 ... a
    # of inc subsequences is 2^a
    */
    int b = 0;
    while (1LL << b < X) {
        b++;
    }
    long cur = 1LL << b;
    if (cur != X) {
        b--;
        cur = 1LL << b;
    }
    vector<int> shuzi(b);
    std::iota(shuzi.begin(), shuzi.end(), 0);
    long diff = X - cur;
    for (int bb = b - 1; bb > -1; bb--) {
        if (diff & 1LL << bb) {
            shuzi.push_back(bb);
        }
    }
    std::cout << shuzi.size() << "\n";
    for (int i = 0; i < shuzi.size(); i++) {
        std::cout << shuzi[i] << " \n"[i == shuzi.size() - 1];
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while (T--) { solve(); }
}
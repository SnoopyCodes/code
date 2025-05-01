#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7, power = 2, to = 1 << 16;

using i64 = long long;
template<typename T, int a> using arr = array<T, a>;
//extraordinarily niche use for precomputing powers of b
//up to 1e9
//e.g. usaco 2025 feb gold p2
//very cringe problem, I don't understand this either
arr<i64, to> small, large;
void comp_pow() {
    small[0] = large[0] = 1;
    for (int i = 1; i < to; i++) {
        small[i] = small[i-1] * power % MOD;
    }
    for (int i = 1; i < to; i++) {
        large[i] = large[i-1] * small[to-1] % MOD;
    }
}

int pow(int p) {
    return small[p & (to-1)] * large[p / to] % MOD;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //https://vmhl87.github.io/starship/pages/24_sqrt-exponentiat.html
}
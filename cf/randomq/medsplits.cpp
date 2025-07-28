#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

void solve() {
    int N, K; std::cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int x; std::cin >> x;
        A[i] = x <= K ? 1 : -1;
    }
    //we need at least 2 medians <= K.
    //iterate through the left bound and maintain median
    //iterate through the right bound and maintain median
    //how do we query for a centerpiece being <= K?
    //wait turn it into # of > k and <= k
    //then we can query trivially
    int minv = BIG, cur = 0;
    bool works = false;
    vector<bool> pf(N + 1);
    for (int i = 0; i < N - 1; i++) {
        cur += A[i];
        pf[i + 1] = cur >= 0 || pf[i];
        if (cur >= 0) {
            if (minv <= cur) { works = true; }
            else { minv = cur; }
        }
    }
    minv = BIG, cur = 0;
    for (int i = N - 1; i > 0; i--) {
        cur += A[i];
        if (cur >= 0) {
            if (minv <= cur) { works = true; }
            else { minv = cur; }
            works |= pf[i] && i != 1;
        }
    }
    if (works) { std::cout << "YES" << "\n"; }
    else { std::cout << "NO" << "\n"; }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;;

#define long long long
int beauty(long x) { return __builtin_popcountll(x); }
int low_unset(long x) { return x & 1 ? 1 + low_unset(x >> 1) : 0; }
void solve() {
    int N; std::cin >> N;
    long K; std::cin >> K;
    vector<long> A(N);
    int cur = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        cur += beauty(A[i]);
    }
    //binary search.
    //5000 * 64 < int max
    //oh is this just greedy
    for (int b = 0; b < 63; b++) {
        for (int i = 0; i < N; i++) {
            if (low_unset(A[i]) == b) {
                if (K < 1LL << b) { break; }
                A[i] += 1LL << b;
                cur++;
                K -= 1LL << b;
            }
        }
    }
    std::cout << cur << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
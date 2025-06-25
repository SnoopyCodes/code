#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const int INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

void solve() {
    int N; std::cin >> N;
    //min # of ops
    //do we just goddang simulate
    int ans = BIG;
    vector<int> A(N);
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        if (i && abs(A[i] - A[i - 1]) <= 1) { ans = 0; }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {  //the gap
            if (i == j || i == j + 1) { continue; }
            int small = min(A[j], A[j + 1]);
            int big = max(A[j], A[j + 1]);
            if (small - 1 <= A[i] && A[i] <= big + 1) {
                ans = min({abs(i - j), abs(i - (j + 1)), ans});
            }
        }
    }
    if (ans == BIG) { ans = -1; }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
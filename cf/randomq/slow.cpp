#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
#define dd define
#define tp template
tp<int z> using ints = std::array<int, z>;
tp<int z> using longs = std::array<long, z>;

tp<class T> using vt = vector<T>;
tp<class T> using vv = vt<vt<T>>;

void solve() {
    int N; std::cin >> N;
    vt<int> A(N);
    vv<int> msb(32);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    long ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = j; k < N; k++) {
                int res = 0;
                for (int l = i; l <= k; l++) {
                    res ^= A[l];
                }
                if (res < (res ^ A[j])) {
                    std::cout << res << " " << (res ^ A[j]) << "\n";
                    std::cout << i << " " << j << " " << k << "\n";
                    ans++; }
            }
        }
    }

    std::cout << ans << "\n";
    
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}
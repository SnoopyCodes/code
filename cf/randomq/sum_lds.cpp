#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = std::array<int, z>;
template<int z> using longs = std::array<long, z>;

#define tpct template<class T>
tpct using vt = vector<T>;
tpct using vv = vt<vt<T>>;

void solve() {
    int N; std::cin >> N;
    vt<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }
    vt<long> sum(N);  //sum of all lds ending here.
    sum[0] = 1;
    sum[1] = 2 + bool(P[0] > P[1]);
    /*
    i > [0...i-2)
    so how do we transition from them?
    actually, we only need to transition from any of the previous 2
    this is like slightly annoying
    */
    for (int i = 2; i < N; i++) {
        if (P[i] < P[i-1]) {
            sum[i] = sum[i-1];
        }   else {
            sum[i] = sum[i-2];
        }
        sum[i] += i + 1;
    }
    std::cout << std::accumulate(sum.begin(), sum.end(), 0LL) << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}